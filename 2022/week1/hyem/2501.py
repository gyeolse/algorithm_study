N, K = map(int, input().split())
lst=[1]
for i in range(2, N):
    if N%i==0:
        lst.append(i)
lst.append(N)
if len(lst)<K:
    print(0)
else :
    print(lst[K-1])