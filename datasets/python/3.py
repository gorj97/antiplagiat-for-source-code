
def main():
    N,K = map(int,input().split())
    s = [int(input()) for _ in range(N)]
    has_zero = False
    for i in range(N):
        if s[i] == 0:
            has_zero = True
            break
    if has_zero:
        print(N)
        return
    
    multi = s[0]
    R = 1
    maxi = 0
    for L in range(N):
        if s[L] <= K:
            maxi = max(maxi,1);
        if L >= R:
            R = L + 1
            multi = s[L]
        while R < N and multi * s[R] <= K:
            maxi = max(maxi,R-L+1)
            multi *= s[R];
            R = R + 1
        multi = multi // s[L]
    print(maxi)
        
    
    

if __name__ == "__main__":
    main()
