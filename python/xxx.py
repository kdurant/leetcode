import os
import sys

fileList = os.listdir(r'.')

for file in fileList:
    new = file.replace(' ', '_')
    os.renames(file, new)
