'''유클리드 호제법으로 풀면 더 간단하게 풀 수 있다고 함
a와 b의 최대공약수 G는 b와 a%b의 최대공약수 G와 같다
gcd(24, 18) = gcd(18, 6) = gcd(6, 0) (이때 b가 0이 될 때 6이 최대공)

최소공 == A*B/gcd(a, b)


'''
def divide():
    global M, N
    flag=0
    for i in range(2, min(M, N)+1):
        if M%i==0 and N%i==0:
            M=M//i
            N=N//i
            flag=1
            # print("return is ",i)
            return i
    if flag==0:
        return 0

M, N = map(int,input().split())
GCD, LCM=1, 1
while(1):
    temp=divide()
    if temp==0:
        LCM=LCM*M*N
        break
    else:
        GCD=GCD*temp
        LCM=LCM*temp

print(GCD)
print(LCM)
