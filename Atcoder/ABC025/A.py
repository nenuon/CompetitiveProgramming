s = input()
n = int(input())

like = []
for i in s:
    for j  in s:
        like.append(i+j)
print(like[n-1])
