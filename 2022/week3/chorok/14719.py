H, W = map(int, input().split())
blocks = list(map(int, input().split()))
result = 0

for i in range(len(blocks)):
    max_left = max(blocks[:i + 1])
    max_right = max(blocks[i:])
    min_value = min(max_left, max_right)
    result = result + abs(blocks[i] - min_value)

print(result)