import sys
import collections
import heapq

input = sys.stdin.readline
INF = int(1e9)


def dijkstra(start):
    Q = [(0, start)]

    while Q:
        time, node = heapq.heappop(Q)
        if dist[node] < time:
            continue
        for v, w in graph[node]:
            alt = time + w
            if dist[v] > alt:
                dist[v] = alt
                heapq.heappush(Q, (alt, v))


N = int(input())
M = int(input())
graph = collections.defaultdict(list)
dist = [INF] * (N + 1)

for _ in range(M):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

start, end = map(int, input().split())

dijkstra(start)
print(dist[end])