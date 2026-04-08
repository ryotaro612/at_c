import sys

s = input()
t = input()


t_pos = [0] * len(t)
j = 0
for i in range(len(s)):
    if j == len(t):
        break
    if s[i] == t[j]:
        t_pos[j] = i
        j += 1

if j < len(t):
    print(len(s) * (len(s) + 1) // 2)
    sys.exit(0)


res = 0

for i in range(len(s)):
    if t_pos[0] < i:
        for t_i in range(len(t)):
            if t_i == 0:
                a = i
            else:
                a = max(t_pos[t_i], t_pos[t_i - 1] + 1)

            for j in range(a, len(s)):
                if s[j] == t[t_i]:
                    t_pos[t_i] = j
                    break
            else:
                t_pos[-1] = len(s)
    # print(i, t_pos, t_pos[-1] - i)
    res += t_pos[-1] - i
print(res)
