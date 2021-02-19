import sys
from fractions import gcd

# Function asd
def asd():
	# vars
    r, t = map(int, input().split())
    y = [int(sys.stdin.readline().rstrip()) for i in range(r)]
	# if
    if 0 < y.count(0):
        print(r)
        return
	#vars
    q = 0
    result = 0
    w = 0
    e = 1
    
	#while
    while r > w:
        if w == q:
            e *= y[q]
            w += 1

            if t < e:
                q += 1
                e = 1
            else:
                result = max(result, 1)
        elif t >= (y[w] * e):
            e *= y[w]
            w += 1
            result = max(result, w - q)
        else:
            e //= y[q]
            q += 1

        # print('value:', e) qweqweqwe
	
	# print
    print(result)


# function debuf
def debug(x, table):
    for name, value in table.items():
		# if
        if value is x:
            print('DEBUG:{} -> {}'.format(name, value), file=sys.stderr)
            return None
			
			
# Function qwe
def qwe(a, b):
	# something return
    return b * a // gcd(a, b)

if __name__ == '__main__':
    asd()