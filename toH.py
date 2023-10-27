import re

with open('array/array.c') as fp:
    l = re.findall(r'[a-z]+ [a-zA-Z]+\(.+\)',fp.read())
    l = list(map(lambda x:x+';',l))
    print(l)
    with open('array/array.h','a') as fo:
        fo.writelines(l)