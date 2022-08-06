import itertools

N, K = map(int, input().split())
alphabet = list(set(chr(i) for i in range(97, 123)) - {'a', 'n', 't', 'i', 'c'})
bit = [0] * N
result = 0

for i in range(N):
    words = input()
    for w in words:
        bit[i] |= (1 << (ord(w) - ord('a')))

if K < 5:
    print(0)
else:
    for i in list(itertools.combinations(alphabet, K - 5)):
        cal_bit = 0
        value = 0
        for j in ['a', 'n', 't', 'i', 'c']:
            cal_bit |= (1 << (ord(j) - ord('a')))
        for j in i:
            cal_bit |= (1 << (ord(j) - ord('a')))
        for j in bit:
            if cal_bit & j == j:
                value += 1
        if result < value:
            result = value
    print(result)