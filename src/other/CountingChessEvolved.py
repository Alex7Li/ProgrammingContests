# Problem statement: how many armies are possible in the online game Chess Evolved Online?

# cost of the most expensive minion that exists
MAX_COST_MINION = int(input())  # 7
N_CHAMPION = int(input())  # 43
# costCount[i] = number of minions with cost i.
# For the non-coders: Arrays are indexed starting at 0.
# To go from 0 to 7, we need 8 different values.
cost_count = [0 for i in range(MAX_COST_MINION + 1)]

# we go up to maxCost+1 because range is exclusive
for champ_ind in range(len(cost_count)):
    # set the number of units with a cost to the
    # next line of user-created input (as a number)
    cost_count[champ_ind] = int(input().strip())
print("Minion input taken")

# The below algorithm is essentially the knapsack algorithm (you can look it up)

# Ok, let's look at ways. It is a 9 by 140 array of arrays, a matrix.
# ways[i][j] will represent the following: the number of ways to
# use exactly i minions such that they have a cost of j.
# The bound 9 is because there are 8 minions total. (and we are 0-indexed)
# The other bound is because the max moral is 100, but we go a bit higher
# to be safe
ways = [[0 for i in range(110)] for i in range(9)]

# Suppose the number of units is 0. There is 1 way to arrange 0 minions
# with cost 0, and no ways with any other cost. So this line completes row 1.
ways[0][0] = 1

# Ok, now that we know the first row with 0 minions, we can calculate the next
for n_minions, row in enumerate(ways[:8]):
    # we know there are n ways to place n_minion
    # different minions in the first n_minion slots.
    # Of course we only care about this when the total_cost
    # is less than or equal to 100, since that is the
    # max possible
    for total_cost, n in enumerate(row[:101]):
        # Suppose we place a minion with cost
        # c next. Then we have found n new
        # ways to achieve a cost of total_cost+c
        # Of course, we can choose any of the minions
        # with cost c, so instead we add n*count new ways.
        for c, count in enumerate(cost_count):
            ways[n_minions + 1][total_cost + c] += n * count

# So, we have calculated the number of ways for every row, and the answer is
# the 8th row, representing with 8 different minions!
# minion_ways[i] = number of ways to place minions with total cost exactly i.
minion_ways = ways[8].copy()

# Now to find champion ways.
# Because we can have a max of 4 champions, we need to keep track of which one is which,
# so we get the input a bit differently
champion_costs = []
for champ in range(N_CHAMPION):
    for tier in (map(int, input().split())):
        champion_costs.append(tier)
print("Champion input taken. Now hang tight for a minute!")
# Now, champion costs is a list, but importantly, every group of 4 is the same champion,
# so index i and j represent the same champion iff i//4=j//4 (where // means dividing and truncating)

# First, let's find the ways to place 7 champions WITHOUT caring about the place-4 rule.
# We do this exactly the same as with the minions
ways = [[0 for i in range(170)] for i in range(8)]
ways[0][0] = 1
for n_champions, row in enumerate(ways[:7]):
    for total_cost, n in enumerate(row[:101]):
        for c in champion_costs:
            ways[n_champions + 1][total_cost + c] += n
champion_ways = ways[7].copy()
print(champion_ways[:101])
# WOW, it's a lot more condensed without 600 lines of comments
# Now we subtract out impossible cases, with 5 or more of the same
# champion. Here we can calculate each case directly, as there are
# only about 10^8 ways
fact = [1, 1, 2, 6, 24, 120, 720, 5040]


# count by 4 since there is a new champion every 4 spots
for champ_ind in range(0, len(champion_costs), 4):
    # We choose all sets of 5 to 7 champs of some given type.
    # First choose the number of Tier 1 champs.
    for n1 in range(0, 8):
        # now choose number of Tier 2 (+) champs, but of course less than 8 total.
        for n2 in range(0, 8 - n1):
            for n3 in range(0, 8 - (n1 + n2)):
                # now the lower bound here is because we need at least 5 for
                # a combination to be invalid.
                min_n4champs = max(0, 5 - (n1 + n2 + n3))
                for n4 in range(min_n4champs, 8 - (n1 + n2 + n3)):
                    # the cost of using these champions
                    cost = n1 * champion_costs[champ_ind] + n2 * champion_costs[champ_ind + 1] \
                           + n3 * champion_costs[champ_ind + 2] + n4 * champion_costs[champ_ind + 3]
                    # if the cost is still less than 100, we may soon find an invalid way!
                    if cost <= 100:
                        n = n1 + n2 + n3 + n4
                        n_permutations = fact[7] // (fact[n1] * fact[n2] * fact[n3] * fact[n4])
                        if n == 7:  # we found 1 invalid combination, subtract out all possible permutations
                            champion_ways[cost] -= n_permutations
                        elif n == 6:  # we need to add 1 champ that is not the same type
                            for other_champ in [x for x in range(N_CHAMPION * 4) if not x // 4 == champ_ind // 4]:
                                other_champ_cost = champion_costs[other_champ]
                                champion_ways[cost + other_champ_cost] -= n_permutations
                        elif n == 5:  # we need to add 2 champs that are not the same type
                            for other_champ1 in [x for x in range(N_CHAMPION * 4) if not x // 4 == champ_ind // 4]:
                                for other_champ2 in [x for x in range(N_CHAMPION * 4) if
                                                     not x // 4 == champ_ind // 4]:
                                    total_cost = cost + champion_costs[other_champ1] + champion_costs[other_champ2]
                                    # We will assume other_champ1 always is on the left of other_champ2,
                                    # halving the possibilities.
                                    champion_ways[total_cost] -= n_permutations//2
# king can go in 1 of 8 slots
for i in range(len(champion_ways)):
    champion_ways[i] *= 8
# Alright, now that we know minion ways and champion ways, it is easy to finish it off
total_ways = 0
for cost in range(101): # total army cost
    for champ_cost in range(cost+1): # cost dedicated to champs
        minion_cost = cost - champ_cost # cost dedicated to minions
        total_ways += minion_ways[minion_cost] * champion_ways[champ_cost]
print(total_ways)
