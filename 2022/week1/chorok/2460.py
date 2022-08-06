people, max_people = 0, 0

for _ in range(10):
    out_man, in_man = map(int, input().split())
    people += in_man - out_man
    max_people = max(people, max_people)
print(max_people)