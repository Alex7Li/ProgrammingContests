b, n = map(int, input().split(" "))
a = [int(input()) for _ in range(n)]
def works(v):
  required = [(x + v - 1) // v for x in a]
  return sum(required) <= b
l = 2**21 - 1
sub = 2**20
while sub != 0:
  if works(l - sub):
    l -= sub
  sub //= 2
print(l)
