# https://brilliant.org/problems/waterflow-problem/?ref_id=1507844


def solve_half(heights):
    max_l = 0
    ans = 0;
    for h in heights:
        max_l = max(max_l, h)
        ans += max_l - h;
    return ans


heights = [int(x) for x in input().split()]

maxInd = 0
maxH = heights[0]
for i in range(len(heights)):
    if maxH < heights[i]:
        maxH = heights[i]
        maxInd = i
firstHeights = heights[:maxInd]
lastHeights = heights[maxInd+1:]
lastHeights.reverse()
print(solve_half(firstHeights) + solve_half(lastHeights))
