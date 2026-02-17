import bisect

n, q = map(int, input().split())
s = input()
left = [0] * (n + 1)
right = [0] * (n + 1)

slashes = []
for i, c in enumerate(s):
    if c == "/":
        slashes.append(i)
    left[i + 1] = left[i]
    right[i + 1] = right[i]
    if c == "1":
        left[i + 1] += 1
    if c == "2":
        right[i + 1] += 1

# print(left)
# print(right)

for _ in range(q):
    l, r = map(int, input().split())
    l -= 1
    r -= 1
    a = bisect.bisect_left(slashes, l)
    if a == len(slashes) or r < slashes[a]:
        print("0")
        continue
    b = bisect.bisect_left(slashes, r)
    if b == len(slashes) or slashes[b] > r:
        b -= 1
    lb = a - 1
    ub = b + 1
    while ub - lb > 1:
        m = (ub + lb) // 2
        if left[slashes[m]] - left[l] <= right[r + 1] - right[slashes[m] + 1]:
            lb = m
        else:
            ub = m
    res = 0
    if 0 <= lb < len(slashes):
        res = min(left[slashes[lb]] - left[l], right[r + 1] - right[slashes[lb] + 1])
    if 0 <= ub < len(slashes):
        res = max(
            res, min(left[slashes[ub]] - left[l], right[r + 1] - right[slashes[ub] + 1])
        )

    print(res * 2 + 1)
