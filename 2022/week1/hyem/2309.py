####
import random

heights = []

for _ in range(9):
    heights.append(int(input()))  # 입력 받기

dwarfs = heights[:7]

while sum(dwarfs) != 100:  # 7명 키의 합이 100이 될 때까지
    random.shuffle(heights)  # heights 리스트를 섞어
    dwarfs = heights[:7]  # 무차별 대입

dwarfs = sorted(dwarfs)  # 오름차순 정렬

for h in dwarfs:
    print(h)
