#!/opt/homebrew/bin/python3

import string
import random

cmds = ("cd", "pwd", "pushd", "popd", "dirs")


def random_dir() -> str:
    return ''.join(random.choices(string.ascii_letters + string.digits, k=1 + random.randrange(10)))


def random_path(n: int) -> str:
    basis = ("/", "")
    if n >= 2:
        basis += ("~", "-", ".")
    if n >= 5:
        basis += ("..",)
    base = random.choice(basis)
    dep = min(random.randrange(10)
              for _ in range(1 + random.randrange(10))) if base != '-' else 0
    return base + ('/' if dep and base != '/' else "") + '/'.join(tuple(random_dir() for _ in range(dep)))


n = int(input())

for _ in range(1 + random.randrange(5000)):
    cmd = random.choice(cmds)
    print(cmd, random_path(n) if cmd in {"cd", "pushd"} else "")
