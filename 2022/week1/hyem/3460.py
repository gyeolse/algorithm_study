#이진수 변환 함수 사용
T=int(input())
for _ in range(T):
    lst=bin(int(input()))[2:]
    for j in range(len(lst)):
        #뒤 인덱스부터 접근할 때는  -i-1사용
        if lst[-j-1]=='1':
            print(j, end=' ')

#직접 변환하기 (재귀 사용)
T=int(input())
def getBin(n, lst):
    a, b = divmod(n, 2)
    lst.append(b)
    if a==1:#몫이 1이 나오면 종료
        lst.append(a)
        return lst
    elif a==0:#n이 1일 경우
        return lst
    else :#재귀로 몫이 1이 나올때까지 반복
        return getBin(a, lst)

for _ in range(T):
    n=int(input())
    lst = []
    answer=getBin(n, lst)

    for i in range(len(answer)):
        if answer[i]==1:
            print(i,end=' ')