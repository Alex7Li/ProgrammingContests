package tough.original

/* https://codeforces.com/gym/102056/problem/I
   This problem is a dynamic programming problem which requires
   a solution that uses interesting values for the dp.
   You must record the number of moves of a certain type,
   as well as the sum time since moves of that type.
*/
fun main() {
    val cases = readLine()!!.toInt()
    for (t in 0.until(cases)) {
        val n = readLine()!!.toInt()
        val a = Array(n) { 0 };
        val b = Array(n) { 0 };
        val c = Array(n) { 0 };
        for (j in 0.until(n)) {
            val (aj, bj, cj) = readLine()!!.split(" ").map { it.toInt() }
            a[j] = aj; b[j] = bj; c[j] = cj;
        }
        // dp[i][j][k] = The number of points of damage that can be done from the ith round
        // to the last round, considering that,
        // after the ith round, j attacks will be done, and the sum of their distance from
        // the ith round is k.
        val dp = Array(2) { Array(n + 1) { Array(n + n * (n + 1) / 2) { 0L } } }
        dp[(n-1)%2][1][1] = a[n - 1].toLong()
        for (i in (n - 2).downTo(0)) {
            for (j in 0.until(n)) {
                for (k in 0.until(n * (n + 1) / 2)) {
                    if (dp[(i + 1)%2][j][k] > 0) {
                        // suppose we choose to increase aggression this round
                        dp[i%2][j][k + j] = maxOf(dp[i%2][j][k + j], dp[(i + 1)%2][j][k] + j.toLong() * c[i])
                        // suppose we choose to increase growth rate this round
                        dp[i%2][j][k + j] = maxOf(dp[i%2][j][k + j], dp[(i + 1)%2][j][k] + k.toLong() * b[i])
                        // suppose we choose to attack this round
                        dp[i%2][j + 1][k + j + 1] = maxOf(dp[i%2][j + 1][k + j + 1], dp[(i + 1)%2][j][k] + a[i])
                    }
                }
            }
        }
        var max = 0L
        for (j in 0.until(n+1)) {
            for (k in 0.until(n + n * (n + 1) / 2)) {
                max = maxOf(max, dp[0][j][k]);
            }
        }
        println(max)
    }
}