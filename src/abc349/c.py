import sys

s = input().upper()
t = input()

i = 0
for c in s:
    if c == t[i]:
        i += 1
        if i == 3:
            print("Yes")
            sys.exit()


if i >= 2 and t[-1] == "X":
    print("Yes")
else:
    print("No")
