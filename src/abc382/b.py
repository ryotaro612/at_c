n, d = map(int, input().split())
s = list(input())
for i in range(n - 1, -1, -1):
    if s[i] == "@" and d:
        d -= 1
        s[i] = "."


print("".join(s))
