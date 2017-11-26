#!/usr/bin/python3

FILE_PATH = "./littleschoolbus.bmp"

with open(FILE_PATH,"rb") as f:
    bytes = bytearray(f.read())

result = ""

for byte in bytes[54:]:
    result += str(byte & 1)

print(result)
