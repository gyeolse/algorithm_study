N, K = map(int, input().split())
elecs = list(map(int, input().split()))
multitap = []
result = 0

for i in range(K):
    if elecs[i] in multitap:
        continue
    if len(multitap) < N:
        multitap.append(elecs[i])
        continue
    result += 1
    out_multitap = 0
    out_index = 0
    for j in range(N):
        try:
            index = elecs[i + 1:].index(multitap[j])
            if index > out_index:
                out_multitap = j
                out_index = index
        except:
            out_multitap = j
            break
    multitap[out_multitap] = elecs[i]

print(result)