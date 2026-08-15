import os
import sys
from collections import defaultdict

sys.setrecursionlimit(10**7)


def dbg(*args):
    if not os.environ.get("ATCODER"):
        print("\033[92m {}\033[00m".format(args))


# letter -> [count, x end, child]
tree = {}


def is_appendable(node, idx, s):
    n = len(s)
    if n == idx:
        return True
    if s[idx] in node:
        if node[s[idx]][1]:
            return False
        return is_appendable(node[s[idx]][2], idx + 1, s)
    return True


def add_node(node, idx, s):
    n = len(s)
    if n == idx:
        return
    if s[idx] in node:
        node[s[idx]][0] += 1
    else:
        node[s[idx]] = [1, False, {}]

    add_node(node[s[idx]][2], idx + 1, s)


def count_prefix(node, idx, s, path):
    if idx == len(s):
        top = path.pop()
        dec = top[0]
        top[1] = True
        top[2] = {}
        while path:
            p = path.pop()
            p[0] -= dec
            # エラー
            assert p[0] >= 0
        return dec
    if s[idx] not in node:
        node[s[idx]] = [0, False, {}]
    if node[s[idx]][1]:
        return 0
    path.append(node[s[idx]])
    return count_prefix(node[s[idx]][2], idx + 1, s, path)


q = int(input())
res = 0

for _ in range(q):
    t, s = input().split()
    # xにsを追加
    if t == "1":
        res -= count_prefix(tree, 0, s, [])
    # yにsを追加
    else:
        if is_appendable(tree, 0, s):
            add_node(tree, 0, s)
            res += 1
    print(res)

    # yに含まれる文字列のうち、xのどの要素も接頭辞にならないものの数を出力
    # (num, child)
