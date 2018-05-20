N=int(raw_input())
T=map(int, raw_input().split())
M=int(raw_input())
for i in xrange(M):
    p, x = map(int, raw_input().split())
    ans = 0
    for j in xrange(N):
        if j+1 == p:
            ans += x
        else:
            ans += T[j]
    print ans


