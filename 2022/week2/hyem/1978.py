N=int(input())
lst = list(map(int, input().split()))
print('lst=',lst)
answer=0
i=0
for num in lst:
    i+=1
    flag=0
    if num==1:
        continue
    for i in range(2,num+1):
        if num%i==0:
            flag=i
            break
    if flag==num:
        answer+=1
print(answer)
