#!/usr/local/bin/python3

import os
import yaml
import re
import sys
import getopt
import datetime

class Options(object):
  pass

class CodeGenerator:
  def __init__(self, opts):
    self.opts = opts
    self.out = None
    self.space = 0
    self.prefix = "lifx"
    self.debug = True
    pass

  def indent(self):
    self.space += 2

  def outdent(self):
    if self.space == 0:
      raise Error;
    self.space -= 2

  def write(self, str):
    self.out.write(" " * self.space)
    self.out.write(str)

  def open_file(self, name):
    self.out = open(name, "w")
    self.write("//\n")
    self.write("// DO NOT EDIT - AUTO-GENERATE:%s\n" % (datetime.datetime.now()))
    self.write("//\n")

  def gen_enum_name(self, idx, name, key):
    s = "kLifx"
    if name == "reserved":
      return "%s%s_%s%d" % (s, key, name, idx)
    is_lower = False
    for ch in name:
      if ch == '_':
        is_lower = False
        continue
      if is_lower:
        s += ch.lower()
      else:
        s += ch
        is_lower = True
    return s

  def emit_guard_prefix(self, guard):
    self.write("#ifndef %s\n" % (guard))
    self.write("#define %s\n" % (guard))
    self.write("\n")
    self.write("#ifdef __cplusplus\n")
    self.write("extern \"C\" {\n")
    self.write("#endif\n")
    self.write("\n")

  def emit_guard_suffix(self):
    self.write("#ifdef __cplusplus\n")
    self.write("}\n")
    self.write("#endif\n")
    self.write("#endif\n")

  def gen_enums(self, enums):
    # self.out = open("lifx_enums.h", "w")
    self.open_file("lifx_enums.h")
    self.emit_guard_prefix("__LIFX_ENUMS_H__")
    self.write("#include <stdint.h>\n")
    self.write("\n")
    for key, value in enums.items():
      self.write("typedef enum {\n")
      self.indent()
      for idx, entry in enumerate(value["values"]):
        if idx > 0:
          self.out.write(",\n")
        self.write("%s = %s" % (self.gen_enum_name(idx, entry["name"], key), entry["value"]))
      self.write("\n")
      self.outdent()
      self.write("} %s%s_t;\n" % (self.prefix, key))
      self.write("\n")
    self.emit_guard_suffix()

  def gen_pkt_type_enum(self, pkts):
    packet_types = {}
    for name, value in pkts["device"].items():
      packet_types.update({int(value["pkt_type"]) : name})
    for name, value in pkts["light"].items():
      packet_types.update({int(value["pkt_type"]) : name})
    for name, value in pkts["tile"].items():
      packet_types.update({int(value["pkt_type"]) : name})
    for name, value in pkts["multi_zone"].items():
      packet_types.update({int(value["pkt_type"]) : name})
    self.packet_types = packet_types

    self.write("\n")
    self.write("typedef enum {\n")
    is_first = True 
    self.indent()
    for value, name in sorted(packet_types.items()):
      if not is_first:
        self.out.write(",\n")
      self.write("kLifxPacketType%s = %d" % (name, int(value)))
      is_first = False
    self.write("\n")
    self.outdent()
    self.write("} %sPacketType_t;\n" % (self.prefix))
    self.write("\n")

  def gen_pkt_defs(self, pktname, pktdef):
    debug = {}
    try:
      if "pkt_type" in pktdef:
        debug['pkt_type'] = pktdef['pkt_type']
      if "size_bytes" in pktdef:
        debug['size_bytes'] = pktdef['size_bytes']
    except KeyError:
      print(pktdef)
      raise
    if self.debug:
      self.write("// %s\n" % (debug))
    self.write("typedef struct {\n")
    self.indent()
    for idx, field in enumerate(pktdef["fields"]):
      if "name" in field:
        name = field["name"]
      else:
        name = "pad%d" % (idx)
        type = "uint8"
      type = field["type"]
      size = field["size_bytes"]
      try:
        if self.debug:
          self.write("// %s\n" % (field))
        self.write("%s;\n" % (self.gen_type_name(name, type, size)))
      except Exception as err:
        print("failed to parse line")
        print(err)
        print("key:", pktname)
        print("val:", pktdef)
        sys.exit(1)
    self.outdent()
    self.write("} %s%s_t;\n" % (self.prefix, pktname))

  def gen_fields(self, doc, fields):
    #self.out = open("lifx_fields.h", "w")
    self.open_file("lifx_fields.h")
    self.emit_guard_prefix("__LIFX_FIELDS_H__")
    self.write("#include <stdbool.h>\n")
    self.write("#include <lifx_enums.h>\n\n")

    # XXX: hack for now. The fields reference two of the packets, so 
    # they need to be defined in this file
    self.write("// XXX: Hack These are actually packets, but are\n")
    self.write("//      referenced in the fields structures\n")
    self.gen_pkt_defs("DeviceStateVersion", doc["packets"]["device"]["DeviceStateVersion"])
    self.gen_pkt_defs("DeviceStateHostFirmware", doc["packets"]["device"]["DeviceStateHostFirmware"])
    self.write("// XXX: end hack\n")
    self.write("\n\n")

    for key, val in fields.items():
      self.write("\n")
      self.gen_pkt_defs(key, val)
    self.write("\n")
    self.emit_guard_suffix()
    self.out.close()

  def gen_decoder(self, key, pktdef):
    struct_name =  "%s%s" % (self.prefix, key)
    self.write("int lifxDecoder_Decode%s(lifxBuffer_t* buff, %s_t* pkt)\n" % (key, struct_name))
    self.write("{\n")
    self.indent()
    self.write("// %s\n" % (pktdef))
    if len(pktdef["fields"]) > 0:
      for idx, field in enumerate(pktdef["fields"]):
        if "name" in field:
          name = field["name"]
        else:
          name = "pad%d" % (idx)
          type = "uint8"
        type = field["type"]
        size = field["size_bytes"]
        if type == "reserved":
          self.write("// %s\n" % (field))
          self.write("lifxBuffer_Seek(buff, %d, kLifxBufferWhenceCurrent);\n" % (int(field["size_bytes"])))
          continue
        self.write("// %s\n" % (field))
        is_array = re.search("\[(\d+)\]byte", type)
        if is_array:
          self.write("lifxBuffer_Read(buff, pkt->%s, %d);\n" % (name, int(is_array.group(1))))
          continue
        user_defined_type = re.search("\<([^>]+)\>", type)
        if user_defined_type:
          user_defined_type_name = user_defined_type.group(1)
          if self.is_enum(user_defined_type_name):
            self.write("lifxBuffer_ReadUInt8(buff, (uint8_t *) &pkt->%s);\n" % ( name))
          elif self.is_packet(user_defined_type_name):
            is_array = re.search("\[(\d+)\]", type)
            if is_array:
              for i in range(int(is_array.group(1))):
                self.write("lifxDecoder_Decode%s(buff, &pkt->%s[%d]);\n" % (user_defined_type_name, name, i))
            else:
              self.write("lifxDecoder_Decode%s(buff, &pkt->%s);\n" % (user_defined_type_name, name))
          elif self.is_field(user_defined_type_name):
            is_array = re.search("\[(\d+)\]", type)
            if is_array:
              for i in range(int(is_array.group(1))):
                self.write("lifxDecoder_Decode%s(buff, &pkt->%s[%d]);\n" % (user_defined_type_name, name, i))
            else:
              self.write("lifxDecoder_Decode%s(buff, &pkt->%s);\n" % (user_defined_type_name, name))
          else:
            raise Exception("unsupported type %s/%s" % (type, user_defined_type_name))
        else:
          try:
            self.write("%s(buff, &pkt->%s);\n" % (self.gen_typed_function_name("lifxBuffer_Read", type),  name))
          except Exception:
            print(pktdef)
            raise
    self.write("return 0;\n")
    self.outdent()
    self.write("}\n")

  def gen_encoder(self, key, pktdef):
    struct_name =  "%s%s" % (self.prefix, key)
    self.write("int lifxEncoder_Encode%s(lifxBuffer_t* buff, %s_t const* pkt)\n" % (key, struct_name))
    self.write("{\n")
    self.indent()
    self.write("// %s\n" % (pktdef))
    # self.write("lifxBuffer_Init(buff, %d);\n" % (pktdef["size_bytes"]))
    if len(pktdef["fields"]) > 0:
      for idx, field in enumerate(pktdef["fields"]):
        if "name" in field:
          name = field["name"]
        else:
          name = "pad%d" % (idx)
          type = "uint8"
        type = field["type"]
        size = field["size_bytes"]
        if type == "reserved":
          self.write("// %s\n" % (field))
          self.write("lifxBuffer_Seek(buff, %d, kLifxBufferWhenceCurrent);\n" % (int(field["size_bytes"])))
          continue
        self.write("// %s\n" % (field))
        is_array = re.search("\[(\d+)\]byte", type)
        if is_array:
          self.write("lifxBuffer_Write(buff, pkt->%s, %d);\n" % (name, int(is_array.group(1))))
          continue
        user_defined_type = re.search("\<([^>]+)\>", type)
        if user_defined_type:
          user_defined_type_name = user_defined_type.group(1)
          if self.is_enum(user_defined_type_name):
            self.write("lifxBuffer_WriteUInt8(buff, (uint8_t) pkt->%s);\n" % ( name))
          elif self.is_packet(user_defined_type_name):
            is_array = re.search("\[(\d+)\]", type)
            if is_array:
              for i in range(int(is_array.group(1))):
                self.write("lifxEncoder_Encode%s(buff, &pkt->%s[%d]);\n" % (user_defined_type_name, name, i))
            else:
              self.write("lifxEncoder_Encode%s(buff, &pkt->%s);\n" % (user_defined_type_name, name))
          elif self.is_field(user_defined_type_name):
            is_array = re.search("\[(\d+)\]", type)
            if is_array:
              for i in range(int(is_array.group(1))):
                self.write("lifxEncoder_Encode%s(buff, &pkt->%s[%d]);\n" % (user_defined_type_name, name, i ))
            else:
              self.write("lifxEncoder_Encode%s(buff, &pkt->%s);\n" % (user_defined_type_name, name))
          else:
            raise Exception("unsupported type %s/%s" % (type, user_defined_type_name))
        else:
          try:
            self.write("%s(buff, pkt->%s);\n" % (self.gen_typed_function_name("lifxBuffer_Write", type),  name))
          except Exception:
            print(pktdef)
            raise
    self.write("return 0;\n")
    self.outdent()
    self.write("}\n")

  def is_request_packet(self, name):
    for p in [ "DeviceGet", "LightGet", "TileGet", "MultiZoneGet" ]:
      if name.startswith(p):
        match = re.search("(Get.*)", name)
        return match.group(1)
    return None

  def is_response_packet(self, name):
    for p in [ "DeviceState", "LightState", "TileState", "MultiZoneState" ]:
      if name.startswith(p):
        s = name.replace("State", "Get")
        return s
    return None

  def get_method_name(self, name):
    if name.startswith("DeviceGet"):
      return "Device_" + name[6:]
    if name.startswith("LightGet"):
      return "Light_" + name[5:]
    return name

  def gen_gets(self, pkts, fields):
    requests = {}
    self.open_file("lifx_requests.h")
    self.emit_guard_prefix("__LIFX_REQUESTS_H__")
    self.write("#include <lifx_defines.h>\n")
    self.write("#include <lifx_packets.h>\n")
    self.write("\n")
    # multi_zone is bit more complicated since requeset can return either/or
    for s in ["device", "light", "tile"]: #, "multi_zone"]:
      for key, val in pkts[s].items():
        req = self.is_request_packet(key)
        if req is not None:
          if key not in requests:
            requests[key] = {}
          requests[key]["request"] = key
          requests[key]["name"] = req
          requests[key]["method"] = req;
        res = self.is_response_packet(key)
        if res is not None:
          if res not in requests:
            requests[res] = {}
          requests[res]["response"] = key 

    for key, val in requests.items():
      method_name = self.get_method_name(key)
      if method_name == "Light_Get":
        continue
      self.write("LIFX_EXPORT int %s%s(lifxSession_t* lifx, lifxDeviceId_t deviceId, "
        % (self.prefix, method_name))
      self.write("%s%s_t* response);\n" % (self.prefix, val["response"]))
    self.write("\n")
    self.emit_guard_suffix()
    self.out.close()

    self.open_file("lifx_requests.c")
    self.write("#include \"lifx.h\"\n")
    self.write("\n")
    for key, val in requests.items():
      method_name = self.get_method_name(key)
      if method_name == "Light_Get":
        continue
      self.write("int %s%s(lifxSession_t* lifx, lifxDeviceId_t deviceId, "
        % (self.prefix, method_name))
      self.write("%s%s_t* response)\n" % (self.prefix, val["response"]))
      self.write("{\n")
      self.indent()
      self.write("int status;\n")
      self.write("int timeoutMillis;\n")
      self.write("lifxPacket_t res;\n")
      self.write("%s%s_t request;\n" % (self.prefix, val["request"]))
      self.write("\n")
      self.write("timeoutMillis = 2000;\n")
      self.write("status = lifxSession_SendRequest(lifx, deviceId, &request, kLifxPacketType%s, &res, timeoutMillis);\n" %
        (val["request"]))
      self.write("if (status == 0)\n")
      self.write("{\n")
      self.indent()
      self.write("*response = res.%s;\n" % (val["response"]))
      self.outdent()
      self.write("}\n")
      self.write("return status;\n")
      self.outdent()
      self.write("}\n")
      self.write("\n")
    self.out.close();

  def gen_encoders(self, pkts, fields):
    self.open_file("lifx_encoders.h")
    self.emit_guard_prefix("__LIFX_ENCODERS_H__")
    self.write("#include <lifx.h>\n")
    self.write("#include <lifx_fields.h>\n")
    self.write("#include <lifx_packets.h>\n")
    self.write("\n")
    self.write("int lifxDecoder_DecodePacket(lifxBuffer_t* buff, lifxPacketType_t type, lifxPacket_t* pkt);\n")
    self.write("int lifxEncoder_EncodePacket(lifxBuffer_t* buff, lifxPacketType_t type, lifxPacket_t const* pkt);\n")
    self.write("int lifxEncoder_GetEncodedSize(lifxPacketType_t type);\n")
    self.write("\n")
    for s in ["device", "light", "tile", "multi_zone"]:
      for key, val in pkts[s].items():
        struct_name =  "%s%s" % (self.prefix, key)
        self.write("int lifxEncoder_Encode%s(lifxBuffer_t* buff, %s_t const* pkt);\n" % (key, struct_name))
    self.write("\n")
    for s in ["device", "light", "tile", "multi_zone"]:
      for key, val in pkts[s].items():
        struct_name =  "%s%s" % (self.prefix, key)
        self.write("int lifxDecoder_Decode%s(lifxBuffer_t* buff, %s_t* pkt);\n" % (key, struct_name))
    self.write("\n")
    for key, val in fields.items():
      struct_name =  "%s%s" % (self.prefix, key)
      self.write("int lifxEncoder_Encode%s(lifxBuffer_t* buff, %s_t const* pkt);\n" % (key, struct_name))
      self.write("int lifxDecoder_Decode%s(lifxBuffer_t* buff, %s_t* pkt);\n" % (key, struct_name))
    self.write("\n")
    self.emit_guard_suffix()
    self.out.close()

    self.open_file("lifx_encoders.c")
    self.write("#include \"lifx_internal.h\"\n")
    self.write("#include \"lifx_encoders.h\"\n\n")

    self.write("int lifxDecoder_DecodePacket(lifxBuffer_t* buff, lifxPacketType_t type, lifxPacket_t* pkt)\n")
    self.write("{\n");
    self.indent()
    self.write("int ret = 0;\n")
    self.write("switch (type)\n")
    self.write("{\n")
    self.indent()
    for value, name in sorted(self.packet_types.items()):
      self.write("case kLifxPacketType%s:\n" % (name))
      self.write("ret = %sDecoder_Decode%s(buff, &pkt->%s);\n" % (self.prefix, name, name))
      self.write("break;\n")
    self.outdent()
    self.write("}\n")
    self.write("return ret;\n")
    self.outdent()
    self.write("}");
    self.write("\n")

    self.write("\n")
    self.write("int lifxEncoder_EncodePacket(lifxBuffer_t* buff, lifxPacketType_t type, lifxPacket_t const* pkt)\n")
    self.write("{\n");
    self.indent()
    self.write("int ret = 0;\n")
    self.write("switch (type)\n")
    self.write("{\n")
    self.indent()
    for value, name in sorted(self.packet_types.items()):
      self.write("case kLifxPacketType%s:\n" % (name))
      self.write("ret = %sEncoder_Encode%s(buff, &pkt->%s);\n" % (self.prefix, name, name))
      self.write("break;\n")
    self.outdent()
    self.write("}\n")
    self.write("return ret;\n")
    self.outdent()
    self.write("}");
    self.write("\n")

    self.write("\n")
    self.write("int lifxEncoder_GetEncodedSize(lifxPacketType_t type)\n")
    self.write("{\n");
    self.indent()
    self.write("int ret = 0;\n")
    self.write("switch (type)\n")
    self.write("{\n")
    self.indent()
    for s in ["device", "light", "tile", "multi_zone"]:
      for key, pktdef in pkts[s].items():
        self.write("// %s\n" % (pktdef))
        self.write("case kLifxPacketType%s:\n" % (key))
        self.write("ret = %d;\n"  % (pktdef["size_bytes"]))
        self.write("break;\n")
    self.outdent()
    self.write("}\n")
    self.write("return ret;\n")
    self.outdent()
    self.write("}");
    self.write("\n")

    self.write("\n")
    for s in ["device", "light", "tile", "multi_zone"]:
      for key, pktdef in pkts[s].items():
        self.gen_encoder(key, pktdef)
        self.write("\n")
        self.gen_decoder(key, pktdef)
        self.write("\n")
    for key, pktdef in fields.items():
      self.gen_encoder(key, pktdef)
      self.write("\n")
      self.gen_decoder(key, pktdef)
      self.write("\n")
    self.out.close()
    pass

  def gen_pkts(self, pkts):
    #self.out = open("lifx_packets.h", "w")
    self.open_file("lifx_packets.h")
    self.emit_guard_prefix("__LIFX_PACKETS_H__")
    self.write("#include <stdbool.h>\n")
    self.write("#include <lifx_enums.h>\n")
    self.write("#include <lifx_fields.h>\n")
    self.gen_pkt_type_enum(pkts)
    for key, val in pkts["device"].items():
      if key == "DeviceStateVersion":
        self.write("\n")
        self.write("// HACK: DeviceStateVersion is in lifx_fields.h\n")
        continue
      if key == "DeviceStateHostFirmware":
        self.write("\n")
        self.write("// HACK: DeviceStateHostFirmware is in lifx_fields.h\n")
        continue
      self.write("\n")
      self.gen_pkt_defs(key, val)
    for key, val in pkts["light"].items():
      self.write("\n")
      self.gen_pkt_defs(key, val)
    for key, val in pkts["tile"].items():
      self.write("\n")
      self.gen_pkt_defs(key, val)
    for key, val in pkts["multi_zone"].items():
      self.write("\n")
      self.gen_pkt_defs(key, val)
    self.write("\n")

    self.write("typedef union\n")
    self.write("{")
    self.write("\n")
    self.indent()
    for pkt in self.packets:
      self.write("%s%s_t %s;\n" % (self.prefix, pkt, pkt))
    self.outdent()
    self.write("} lifxPacket_t;\n")
    self.write("\n")
    self.emit_guard_suffix()

  def gen_typed_function_name(self, func, type):
    if type == "uint32":
      return func + "UInt32"
    if type == "float32":
      return func + "Float";
    if type == "uint64":
      return func + "UInt64"
    if type == "uint16":
      return func + "UInt16"
    if type == "bool":
      return func + "Bool"
    if type == "int16":
      return func + "Int16"
    if type == "uint8":
      return func + "UInt8"
    raise Exception("unsupported type %s" % (type))

  def gen_type_name(self, name, type, size):
    if type == "reserved":
      if size == 1:
        return "uint8_t %s" % (name)
      else:
        return "uint8_t %s[%d]" % (name, int(size))
    if type == "float32":
      return "float %s" % (name)
    if type == "int16":
      return "int16_t %s" % (name)
    if type == "uint16":
      return "uint16_t %s" % (name)
    if type == "uint32":
      return "uint32_t %s" % (name)
    if type == "uint64":
      return "uint64_t %s" % (name)
    if type == "uint8":
      return "uint8_t %s" % (name)
    if type == "bool":
      return "bool %s" % (name)

    match = re.search("\<([^>]+)\>", type)
    if match:
      is_array = re.search("\[(\d+)\]", type)
      if is_array:
        return "%s%s_t %s[%d]" % (self.prefix, match.group(1), name, int(is_array.group(1)))
      else:
        return "%s%s_t %s" % (self.prefix, match.group(1), name)

    match = re.search("\[(\d+)\]byte", type)
    if match:
      return "uint8_t %s[%d]" % (name, int(match.group(1)))

    raise Exception("unsupported type %s" % (type))

  def load_types(self, doc):
    self.enums = doc["enums"].keys()
    self.fields = doc["fields"].keys()
    self.packets = []
    for key, val in doc["packets"].items():
      for name in doc["packets"][key].keys():
        self.packets.append(name)

  def is_field(self, name):
    return name in self.fields

  def is_enum(self, name):
    return name in self.enums

  def is_packet(self, name):
    return name in self.packets

def main(argv):
  infile = ''
  outfile = ''

  try:
    opts, args = getopt.getopt(argv, "i:o:",["infile=","outfile"])
  except getopt.GetoptError:
    sys.exit(1)

  for opt, arg in opts:
    if opt in ("-i", "--infile"):
      infile = arg
    elif opt in ("-o", "--outfile"):
      outfile = arg

  opts = Options()
  opts.infile = open(infile, "r")

  try:
    code_generator = CodeGenerator(opts)
    for doc in yaml.load_all(opts.infile):
      code_generator.load_types(doc);
      code_generator.gen_enums(doc["enums"])
      code_generator.gen_fields(doc, doc["fields"])
      code_generator.gen_pkts(doc["packets"])
      code_generator.gen_encoders(doc["packets"], doc["fields"])
      code_generator.gen_gets(doc["packets"], doc["fields"])
  except yaml.YAMLError as err:
    print(err)

if __name__ == "__main__":
  main(sys.argv[1:])
