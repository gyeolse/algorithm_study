M=int(input())
N=int(input())
lst=[]
def identif(num):
    flag=0
    for i in range(2,num+1):
        if num%i==0:
            #소수아님
            flag=i
            break
    if flag==num:
        #num is 소수
        return 1
    else :
        return 0

for j in range(M, N+1):
    temp_num=identif(j)
    if temp_num==1:#소수
        lst.append(j)
if len(lst)==0:
    print(-1)
else :
    print(sum(lst))
    print(lst[0])

