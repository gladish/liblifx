#!/usr/local/bin/python3

import datetime
import getopt
import json
import sys

class CodeGenerator:
  def __init__(self):
    self.space = 0

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

  def as_bool(self, b):
    if b:
      return "true"
    else:
      return "false"

  def gen_product_info(self, products):
    vendor_id = products["vid"]
    vendor_name = products["name"]
    for idx, product in enumerate(products["products"]):
      variable_name = "_product_info_vid_%d_pid_%d" % (vendor_id, product["pid"])
      self.write("static lifxProductInformation_t %s = \n" % (variable_name))
      self.write("{\n")
      self.indent()
      self.write("%d, // ProductId\n" % (product["pid"]))
      self.write("\"%s\", // Name\n" % (product["name"]))
      self.write("{\n")
      self.indent()
      self.write("%s, // Features.Color\n" % (str(product["features"]["color"]).lower()))
      self.write("%s, // Features.Infrared\n" % (str(product["features"]["infrared"]).lower()))
      self.write("%s, // Features.Matrix\n" % (str(product["features"]["matrix"]).lower()))
      self.write("%s, // Features.Multizone\n" % (str(product["features"]["multizone"]).lower()))
      self.write("{\n")
      self.indent()
      self.write("%d, // Features.TemperatureRange.Minimum\n" % (int(product["features"]["temperature_range"][0])))
      self.write("%d // Features.TemperatureRange.Maximum\n" % (int(product["features"]["temperature_range"][1])))
      self.outdent()
      self.write("},\n")
      self.write("%s // Fetures.Chain\n" % (str(product["features"]["chain"]).lower()))
      self.outdent()
      self.write("}\n")
      self.outdent()
      self.write("};\n\n")
    self.write("\n")

    num_products = len(products["products"])
    self.write("lifxProductInformation_t* __lifx_products[%d] = \n" % (num_products + 1))
    self.write("{\n")
    self.indent()
    for idx, product in enumerate(products["products"]):
      variable_name = "_product_info_vid_%d_pid_%d" % (vendor_id, product["pid"])
      if idx > 0:
        self.out.write(",\n")
      self.write("&" + variable_name)
    self.out.write(",\n")
    self.write("NULL\n")
    self.outdent()
    self.write("};\n")
   
    #for idx, product in enumerate(products["products"]):
    #  print(product["features"])
    #  self.write("lifxDeviceDatabase_Add(&db, %d, %d, \"%s\", %s, %s, %s, %s, %d, %d, %s);\n" % (
    #    int(products["vid"]),
    #    int(product["pid"]),
    #    product["name"],
    #    str(product["features"]["color"]).lower(),
    #    str(product["features"]["infrared"]).lower(),
    #    str(product["features"]["matrix"]).lower(),
    #    str(product["features"]["multizone"]).lower(),
    #    int(product["features"]["temperature_range"][0]),
    #    int(product["features"]["temperature_range"][1]),
    #    str(product["features"]["chain"]).lower()))

def main(argv):
  try:
    opts, args = getopt.getopt(argv, "i:", ["infile="])
  except getopt.GetoptError:
    sys.exit(1)

  for opt, arg in opts:
    if opt in ("-i", "--infile"):
      infile = arg

  with open(infile) as f:
    data = json.load(f)
    code_generator = CodeGenerator();
    code_generator.open_file("lifx_product_db.c")
    code_generator.write("#include \"lifx.h\"\n\n")
    code_generator.write("#include <stdlib.h>\n")
    for idx, vendor_products in enumerate(data):
      code_generator.gen_product_info(vendor_products)

if __name__ == "__main__":
  main(sys.argv[1:])
