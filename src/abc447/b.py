s = input()

pos_a, pos_b, pos_c = [], [], []

for i, c in enumerate(s):
    if c == "A":
        pos_a.append(i)
    elif c == "B":
        pos_b.append(i)
    elif c == "C":
        pos_c.append(i)

res = 0

while pos_c:
    c = pos_c.pop()
    while pos_b and pos_b[-1] > c:
        pos_b.pop()

    if pos_b:
        b = pos_b.pop()
        while pos_a and pos_a[-1] > b:
            pos_a.pop()

        if pos_a:
            a = pos_a.pop()
            res += 1
print(res)
