A, B, C, K = map(int, list(input().split()))
S, T = map(int, list(input().split()))
if K <= S + T:
    A -= C
    B -= C
print(S*A+T*B)
