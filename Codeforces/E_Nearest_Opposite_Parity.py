from collections import deque
from typing import Dict, List, Set

n = int(input())
a = list(map(int, input().split(" ")))

# Create graph with reverse-directed edges.
g = [[] for _ in range(n)]
assert(len(g) == len(a))
for i, x in enumerate(a):
  if i - x >= 0:
    g[i - x].append(i)
  if i + x < len(a):
    g[i + x].append(i)

# Compute the distance from all nodes in set S
# to all other nodes using bfs.
def bfs(seen: Set[int], a: List[int]) -> Dict[int, int]:
  Q = deque()
  distances = {}
  for index in seen:
    Q.appendleft((0, index)) # distance from input, index of node
  while len(Q):
    dist, ind = Q.pop()
    for next in g[ind]:
      if next not in seen:
        seen.add(next)
        Q.appendleft((dist + 1, next))
        distances[next] = dist + 1
  return distances

even_inds = [i for i, x in enumerate(a) if x % 2 == 0]
odd_inds = [i for i, x in enumerate(a) if x % 2 == 1]

odd_distances = bfs(set(even_inds), a)
even_distances = bfs(set(odd_inds), a)

ans = ["-1"] * len(a)
for dist_dict in [odd_distances, even_distances]:
  for index, distance in dist_dict.items():
    ans[index] = str(distance)

print(' '.join(ans))
