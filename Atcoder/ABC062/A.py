a, b = map(int, input().split())
num = [0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1]
if num[a] == num[b]:
    print("Yes")
else:
    print("No")
