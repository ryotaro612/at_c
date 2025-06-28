from collections import defaultdict

n, q = list(map(int, input().split()))

commands = []
last = defaultdict(lambda: -1)
for _ in range(q):
    commands.append(list(map(int, input().split())))
    for i in range(1, len(commands[-1])):
        commands[-1][i] -= 1

nest_ps = {i: i for i in range(n)}
ps_nest = {i: i for i in range(n)}
pigeon_ps = {i: i for i in range(n)}

for i in range(q):
    a = commands[i][1]
    if commands[i][0] < 3:
        b = commands[i][2]
    if commands[i][0] == 1:
        pigeon_ps[a] = nest_ps[b]
    elif commands[i][0] == 2:
        nest_ps[a], nest_ps[b] = nest_ps[b], nest_ps[a]
        ps_nest[nest_ps[a]] = a
        ps_nest[nest_ps[b]] = b
    else:
        print(ps_nest[pigeon_ps[a]] + 1)

# print(pos_pigeon)
