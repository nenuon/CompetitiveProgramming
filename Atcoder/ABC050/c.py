import numpy as np
N=int(raw_input())
A=map(int, raw_input().split())


cnt = 0
if N%2 == 0:
    if A.count(0) >= 1:
        print 0
        cnt = 1
    else:
        for i in np.arange(1, N, 2):
            if A.count(i) != 2:
                print 0
                cnt = 1
                break
    if cnt == 0:
        print 2**(N/2)%(10**9+7)
else:
    if A.count(0) >= 2:
        print 0
        cnt = 1
    else:
        for i in np.arange(2, N, 2):
            if A.count(i) != 2:
                print 0
                cnt = 1
                break
    if cnt == 0:
        print 2**(N/2)%(10**9+7)
