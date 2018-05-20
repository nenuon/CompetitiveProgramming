import collections
N=int(raw_input())
A=map(int, raw_input().split())
count_A=collections.Counter(A).most_common(1)
cnt = 0
if N == 1:
    if A[0] == 0:
        print 1
    else:
        print 0
elif N%2 == 0:
    if A.count(0) != 0:
        print 0
        cnt = 1
    elif count_A[0][1] != 2:
        print 0
        cnt = 1
    if cnt == 0:
        print (2**(N/2)) % (10**9+7)
else:
    if A.count(0) != 1:
        print 0
        cnt = 1
    elif count_A[0][1] != 2:
        print 0
        cnt = 1
    if cnt == 0:
        print (2**(N/2)) % (10**9+7)
