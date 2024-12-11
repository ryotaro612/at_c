n, d = map(int, input().split())
s = input()
n_at = len([_ for _ in s if _ == "@"])

n_s = len(s)
print(n_s - (n_at - d))
