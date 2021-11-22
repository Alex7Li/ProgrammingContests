# https://codeforces.com/problemset/problem/1133/C
n = int(input())
a = map(int, input().split(" "))
a = sorted(a)

def min_ind_gen(a):
  cur_ind = 0
  while True:
    max_el = yield cur_ind
    while a[cur_ind] + 5 < max_el:
      cur_ind += 1

generator = min_ind_gen(a)
best_ans = 0
generator.send(None)
for i, el in enumerate(a):
  min_ind = generator.send(el)
  best_ans = max(best_ans, i - min_ind + 1)
  
print(best_ans)
  