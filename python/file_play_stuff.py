import re

print ('Hello World')

f = open("data.txt", "r")
for line in f :
    #print(line)
    x = re.search("123", line)
    print(x)
