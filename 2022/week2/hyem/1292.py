A, B = map(int, input().split())
lst=[]
answer=0
for i in range(46):#45*46/2=1035, 44*45/2=990 따라서 n은 45
    for _ in range(i):
        lst.append(i)
for i in range(A-1, B):
    # print('lst[i]=',lst[i])
    answer+=lst[i]

print(answer)