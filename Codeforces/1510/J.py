# https://codeforces.com/contest/1510/my
# MACHINE LEARNING
import math
from sys import stdout
from typing import List


def get_guesses() -> List[int]:
    inp = input()
    return [-1 if x == '0' else 1 for x in inp]


def guess(answer: int) -> None:
    print(answer)
    stdout.flush()


def get_ans() -> int:
    true_ans = int(input())
    return true_ans


def solve():
    n, m = list(map(int, (input().split(" "))))
    lr = .01
    weights = [.0] * n
    weights.append(0.0)  # bias
    for i in range(m):
        g = get_guesses()
        g.append(1)
        weighted_sum = sum([weights[j] * g[j] for j in range(len(g))])
        guess(1 if weighted_sum > 0 else 0)
        sig_out = 1 / (1.0 + math.exp(-weighted_sum))
        error = sig_out - get_ans()
        # Square error
        gradient = [g[i] * sig_out * (1 - sig_out) *
                    error for i in range(len(g))]
        weights = [weights[i] - gradient[i] * lr for i in range(len(weights))]

solve()
