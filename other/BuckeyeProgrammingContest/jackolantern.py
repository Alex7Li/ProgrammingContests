eye_sz, teeth = map(int, input().split(" "))
n = eye_sz + 3
m = 2 * eye_sz + 5
a = [[' ' for _ in range(m)] for _ in range(n)]
w = eye_sz * 2
for i in range(eye_sz):
  a[eye_sz - i - 1][i] = '/'
  a[eye_sz - i - 1][w - i - 1] = '\\'
  a[eye_sz - i - 1][w + i] = '/'
  a[eye_sz - i - 1][2 * w - i] = '\\'

for i in range((eye_sz - 1)* 2):
  a[eye_sz - 1][i + 1] = '_'
  a[eye_sz - 1][w + i + 2] = '_'


st = w - teeth + 1
cc = '/\\'
for i in range(2 * teeth):
  a[n - 1][st + i] = cc[i % 2]
  a[n - 2][st + i] = cc[(i + 1) % 2]

print('\n'.join([''.join(b) for b in a]))
