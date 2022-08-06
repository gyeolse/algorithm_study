N=int(input())
lst = list(map(int, input().split()))
print(min(lst), max(lst), end=' ')
#또는
# lst.sort()
# print(lst[0], lst[len(lst) - 1], end=' ')