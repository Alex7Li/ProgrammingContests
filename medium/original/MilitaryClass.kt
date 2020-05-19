package medium.original

import kotlin.math.abs

//https://codeforces.com/gym/102219/problem/F
// This is a pretty nice problem about bitmasks.
// Just be warned since the input data is WRONG!!!
// In fact, it should read 1<=tough.interesting.getN<=2000.
private val MOD = 1_000_000_007;

fun main() {
    val (n, e, k) = readLine()!!.split(" ").map { it.toInt() }
    // the jth bit of invalid[i] is 1 if it's not an allowed configuration
    val invalid = Array(n) { 0 }
    // invalid pair conditions
    for (i in 0.until(k)) {
        val (u, v) = readLine()!!.split(" ").map { it.toInt() }
        // the last 2 checks are needed because the checker is broken );
        if (abs(u - v) <= e && u <= n && v <= n) {
            val bitToChange = v - u
            invalid[u - 1] = invalid[u - 1].or(1.shl(bitToChange + e))
    }
    }
    // boundary conditions
    for (i in 0.until(n)) {
        for (j in (i - e).until(0)) {
            val bitToChange = (j - i)
            invalid[i] = invalid[i].or(1.shl(bitToChange + e))
        }
        for (j in n..(i + e)) {
            val bitToChange = (j - i)
            invalid[i] = invalid[i].or(1.shl(bitToChange + e))
        }
    }
    val ways = Array(2) { Array(2.shl(2 * e)) { 0 } }
    for (firstPair in 0..e) {
        val config = 1.shl(e + firstPair);
        if (config.and(invalid[0]) == 0) {
            ways[0][config] = 1
        }
    }
    for (i in 1.until(n)) {
        for (j in 0.until(ways[i % 2].size)) {
            ways[i % 2][j] = 0
        }
        for (last_config in 0.until(2.shl(2 * e))) {
            if (ways[(i - 1) % 2][last_config] == 0) {
                continue
            }
            for (pairing in -e..e) {
                // location of the next pair
                val pairLoc = 1.shl(pairing + e)
                // pairing doesn't violate any invalid positions or any positions of last config
                if ((invalid[i].or(last_config.shr(1))).and(pairLoc) == 0) {
                    val newConfig = last_config.shr(1).or(pairLoc)
                    ways[i % 2][newConfig] = (ways[(i - 1) % 2][last_config] + ways[i % 2][newConfig]) % MOD;
                }
            }
        }
    }
    val totalWays = ways[(n - 1) % 2].fold(0) { sum, el -> (sum + el) % MOD }
    println(totalWays)
}

