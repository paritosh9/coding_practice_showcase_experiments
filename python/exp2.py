import re

print("Hello World")

txt = "The rain in Spain"
x = re.findall("ai", txt)
print(x)

txt = "The rain in Spain"
x = re.split("\s", txt)
print(x)

txt = "The rain in Spain Spain"
x = re.search(r"\bS\w", txt)
print(x)
print(x.string)

txt = "The rain in Spain Spain"
x = re.search(r"\bS\w+", txt)
print(x.span())
