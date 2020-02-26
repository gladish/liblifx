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

  def gen_product_info(self, products):
    vendor_id = products["vid"]
    for idx, product in enumerate(products["products"]):
      self.write("lifxDeviceDatabase_Add(&db, %d, %d);\n" % (
        int(products["vid"]),
        int(product["pid"]),
        product["name"],
        product["features"]["color"],
        product["features"]["infrared"],
        product["features"]["matrix"],
        product["features"]["multizone"],
        product["features"]["temperature_range"][0],
        product["features"]["temperature_range"][1],
        product["features"]["chain"]))

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
    code_generator.open_file("lifx_device_database.c")
    for idx, vendor_products in enumerate(data):
      code_generator.gen_product_info(vendor_products)

if __name__ == "__main__":
  main(sys.argv[1:])
