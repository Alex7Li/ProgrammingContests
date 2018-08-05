from math import *
# https://brilliant.org/problems/fixed-point/?ref_id=1507237


def fixedPoint(f, x):
    # calculate fixed-point y = f(y)
    if abs(f(x)-x) > .000001:
        return fixedPoint(f, f(x))
    return x


print(fixedPoint(cos, 0.5))
