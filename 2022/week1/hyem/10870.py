#반복문방식
n=int(input())
lst=[]
for i in range(n+1):
    if i==0:
        lst.append(i)
    elif i==1:
        lst.append(i)
    else:
        lst.append(lst[i-2]+lst[i-1])
print(lst[n])

#재귀방식
n=int(input())

def f(n):
    if n==0:
        return 0
    elif n==1 or n==2:
        return 1

    return f(n-2)+f(n-1)

A=f(n)
print(A)