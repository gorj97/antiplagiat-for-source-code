import sys
from fractions import gcd

def qwe(a, b):
    return a * b // gcd(a, b)

def asd():
    r, t = map(int, input().split())
    y = [int(sys.stdin.readline().rstrip()) for i in range(r)]

    if y.count(0) > 0:
        print(r)
        return

    q = 0
    w = 0
    result = 0
    e = 1

    while w < r:
        if q == w:
            w += 1
            e *= y[q]

            if e > t:
                e = 1
                q += 1
            else:
                result = max(result, 1)
        elif (e * y[w]) <= t:
            e *= y[w]
            w += 1
            result = max(result, w - q)
        else:
            e //= y[q]
            q += 1

        # print('value:', e)

    print(result)

def debug(x, table):
    for name, value in table.items():
        if x is value:
            print('DEBUG:{} -> {}'.format(name, value), file=sys.stderr)
            return None

if __name__ == '__main__':
    asd()