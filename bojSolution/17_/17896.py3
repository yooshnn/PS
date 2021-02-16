import sys; input = sys.stdin.readline
import re

s = input().rstrip()

if re.search("meow", s): print(0)
elif re.search("moew|meo|eow|m.?ow|me.?w|me.ow", s): print(1)
elif re.search("me|eo|ow|m.?o|m.?.?w|e.?w|m.?e.?w|m.?o.?w", s): print(2)
elif re.search("m|e|o|w", s): print(3)
else: print(4)
