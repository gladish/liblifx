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

  def gen_encoders(self, pkts):
    #self.out = open("lifx_encoders.h", "w")
    self.open_file("lifx_encoders.h")
    self.emit_guard_prefix("__LIFX_ENCODERS_H__")
    self.write("#include <lifx_packets.h>\n")
    self.write("\n")
    for s in ["device", "light", "tile", "multi_zone"]:
      for key, val in pkts[s].items():
        struct_name =  "%s%s" % (self.prefix, key)
        self.write("int %sEncode(%s const* pkt, lifxBuffer_t* buff);\n" % (struct_name, struct_name))
        self.write("int %sDecode(%s* pkt, lifxBuffer_t const* buff);\n" % (struct_name, struct_name))
        self.write("\n")
    self.write("\n")
    self.emit_guard_suffix()
    self.out.close()

    self.open_file("lifx_encoders.c")
    self.write("#include \"lifx.h\"\n\n")
    for s in ["device", "light", "tile", "multi_zone"]:
      for key, pktdef in pkts[s].items():
        struct_name =  "%s%s_t" % (self.prefix, key)
        self.write("int %sEncode(%s const* pkt, lifxBuffer_t* buff)\n" % (struct_name, struct_name))
        self.write("{\n")
        self.indent()
        self.write("lifxBufferInit(buff, %d);\n" % (pktdef["size_bytes"]))
        offset = 0
        if len(pktdef["fields"]) > 0:
          for idx, field in enumerate(pktdef["fields"]):
            if "name" in field:
              name = field["name"]
            else:
              name = "pad%d" % (idx)
              type = "uint8"
              continue
            type = field["type"]
            size = field["size_bytes"]
            if type == "reserved":
              self.write("// skip %s\n" % (field))
            self.write("// %s\n" % (field))
            is_array = re.search("\[(\d+)\]byte", type)
            if is_array:
              self.write("lifxBufferWrite(buff, %d, pkt->%s, %d);\n" %
                (offset, name, int(is_array.group(1))))
              continue

            # TODO: need to handle embedded packets

            is_enum = re.search("\<([^>]+)\>", type)
            if is_enum:
              self.write("lifxBufferWriteUInt8(buff, %d, (uint8_t) pkt->%s);\n" %
                (offset, name))
            else:
              try:
                self.write("%s(buff, %d, pkt->%s);\n" %
                  (self.gen_typed_function_name("lifxBufferWrite", type), offset, name))
              except Exception:
                print(pktdef)
                raise
            offset += int(field["size_bytes"])
        self.write("return 0;\n")
        self.outdent()
        self.write("}\n")
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
      return func + "UInt8"
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
      return "%s%s_t %s" % (self.prefix, match.group(1), name)

    match = re.search("\[(\d+)\]byte", type)
    if match:
      return "uint8_t %s[%d]" % (name, int(match.group(1)))

    raise Exception("unsupported type %s" % (type))

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
      code_generator.gen_enums(doc["enums"])
      code_generator.gen_fields(doc, doc["fields"])
      code_generator.gen_pkts(doc["packets"])
      code_generator.gen_encoders(doc["packets"])
  except yaml.YAMLError as err:
    print(err)

if __name__ == "__main__":
  main(sys.argv[1:])
