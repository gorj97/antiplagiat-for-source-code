import sys
from fractions import gcd

# Function lcm
def lcm(a, b):
	# something return
    return a * b // gcd(a, b)

# Function solve
def solve():
	# Initializing vars
    N, K = map(int, input().split())
    s = [int(sys.stdin.readline().rstrip()) for i in range(N)]

    if s.count(0) > 0:
        print(N)
        return

    l = 0
    r = 0
    ans = 0
    v = 1
	# while
    while r < N:
        if l == r:
            r += 1
            v *= s[l]

            if v > K:
                v = 1
                l += 1
            else:
                ans = max(ans, 1)
        elif (v * s[r]) <= K:
            v *= s[r]
            r += 1
            ans = max(ans, r - l)
        else:
            v //= s[l]
            l += 1

        # print('value:', v) ya tut bil

    print(ans)

# Function debug
def debug(x, table):
	# For
    for name, val in table.items():
        if x is val:
			# print
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()