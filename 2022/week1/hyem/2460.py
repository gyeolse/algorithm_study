#list사용하는 방식
lst=[]
for i in range(10):
    p_out, p_in = map(int, input().split())
    if i==0:
        lst.append(p_in)
    else:
        lst.append(lst[i-1]-p_out+p_in)
lst.sort()
print(lst[9])
#그냥 max로 비교하기
cur, mx=0,0
for _ in range(10):
    p_out, p_in = map(int, input().split())
    cur+=p_in-p_out
    mx=max(cur,mx)
print(mx)

