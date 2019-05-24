# https://brilliant.org/problems/polynomial-cipher/
val = 13417108788227


def f(x):
    return 2*(x**4)+3*(x**3)+x**2+4*x+1


x = 1
while f(x) != val:
    x += 1
print(x)
