n = int(input())
sl = []

for _ in range(n):
    sl.append(input())

mx_len = max(len(s) for s in sl)

for s in sl:
    l = len(s)
    a = (mx_len - l) // 2

    print("." * a + s + "." * a)

