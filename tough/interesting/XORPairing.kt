package tough.interesting

import java.lang.RuntimeException
import java.util.*
import kotlin.collections.HashMap

//http://codeforces.com/gym/102367/problem/E
//gets TLE
val MOD = 1_000_000_007
val memo = HashMap<BitSet, Pair<Long, Long>>(100000)
var list = Array(0) { 0 }
var n = 0

fun ways(n: Int): Long {
    return if (n == 2) 1L else ((n - 1) * ways(n - 2)) % MOD
}

fun solveWithoutIndex(x: BitSet, pow: Int, size: Int): Array<Pair<Long, Long>> {
    var loc = x.nextSetBit(0)
    val solutions = Array(size) { Pair(0L, 0L) }
    var i = 0;
    while (loc != -1) {
        x.set(loc, false)
        solutions[i] = solve(x, pow - 1, size - 1)
        x.set(loc, true)
        loc = x.nextSetBit(loc + 1)
        i++;
    }
    return solutions
}

fun solve(x: BitSet, pow: Int, size: Int): Pair<Long, Long> {
    if (memo.contains(x)) {
        return memo[x]!!
    }
    if (size % 2 != 0) {
        throw RuntimeException()
    }
    if (size == 0) {
        return Pair(0, 1)
    } else if (pow == -1) {
        //every number is the same
        return Pair(0, ways(size))
    }
    val big = BitSet(n)
    var bigSize = 0
    val small = BitSet(n)
    var smallSize = 0
    var nextSet = x.nextSetBit(0)
    while (nextSet != -1) {
        val el = list[nextSet]
        if (el.and(1.shl(pow)) != 0) {
            big.set(nextSet)
            bigSize++
        } else {
            small.set(nextSet)
            smallSize++
        }
        nextSet = x.nextSetBit(nextSet + 1)
    }
    val ans: Pair<Long, Long>
    if (bigSize % 2 == 0) {// small.size%2==0
        val bigS = solve(big, pow - 1, bigSize)
        val smallS = solve(small, pow - 1, smallSize)
        ans = Pair(bigS.first + smallS.first, (bigS.second * smallS.second) % MOD)
    } else {
        var minPos = Long.MAX_VALUE / 2
        var nPairs = 0L
        val bigRes = solveWithoutIndex(big, pow, bigSize)
        val smallRes = solveWithoutIndex(small, pow, smallSize)
        var outerTimes = 0;
        var nextBigSet = big.nextSetBit(0)
        while (nextBigSet != -1) {
            var innerTimes = 0;
            var nextSmallSet = small.nextSetBit(0)
            while (nextSmallSet != -1) {
                val bigS = bigRes[outerTimes]
                val smallS = smallRes[innerTimes]
                val cost = bigS.first + smallS.first + list[nextBigSet].xor(list[nextSmallSet])
                if (cost < minPos) {
                    minPos = cost
                    nPairs = (bigS.second * smallS.second) % MOD
                } else if (cost == minPos) {
                    nPairs = (nPairs + bigS.second * smallS.second) % MOD
                }
                innerTimes++;
                nextSmallSet = small.nextSetBit(nextSmallSet + 1)
            }
            outerTimes++;
            nextBigSet = big.nextSetBit(nextBigSet + 1)
        }
        ans = Pair(minPos, nPairs)
    }
    memo[x] = ans
    //println("$x $ans")
    return ans
}

fun main() {
    n = readLine()!!.toInt()
    list = readLine()!!.split(" ").map { x -> x.toInt() }.sorted().toTypedArray()
    val bs = BitSet(list.size)
    bs.flip(0, list.size)
    val (a, b) = solve(bs, 9, list.size)
    println("$a $b")
}
