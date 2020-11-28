import sys
import re
input = sys.stdin.readline

s = input().rstrip()

if s.count("+")+s.count("-")+s.count("*")+s.count("/")+1!=len(re.findall('\d+', s)):
    print("ROCK")
    sys.exit(0)

s = s.replace("/", "//")
s = s.replace("**", "ROCK")

try:
    print(eval(s))
except:
    print("ROCK")
