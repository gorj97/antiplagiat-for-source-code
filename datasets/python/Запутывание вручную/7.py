import sys
from fractions import gcd

def solve():
    N, K = map(int, input().split())
    s = [int(sys.stdin.readline().rstrip()) for i in range(N)]

    ans = 0
    l = 0
    v = 1
    r = 0
	
    if s.count(0) > 0:
        print(N)
        return
	
    while r < N:
        if l == r:
            v *= s[l]
            r += 1
            if v > K:
                l += 1
                v = 1
            else:
                ans = max(ans, 1)
        elif (v * s[r]) <= K:
            v *= s[r]
            r += 1
            ans = max(ans, r - l)
        else:
            v //= s[l]
            l += 1

        # print('value:', v)

    print(ans)
	

def lcm(a, b):
    return a * b // gcd(a, b)
	

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()