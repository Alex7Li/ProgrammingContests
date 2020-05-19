package open.max_prime_interval

import kotlin.math.max
import kotlin.math.sqrt

// True or False: for any l, s in N, the number of noncomposite numbers
// in the interval $[1,l]$ is at least the number of noncomposite in the interval $[s+1,s+l]$.

// This code would give evidence to suggest the answer is True, since there is no low counterexample.
fun main() {
    val n = 100_000_000;
    // check if there is a counter example less than 2n
    val isComp = Array(n) { false }
    val root = (sqrt(n.toFloat()) + 1).toInt()
    for (i in 2..root) {
        if (!isComp[i]) {
            var prod = i * i;
            while (prod < n) {
                isComp[prod] = true
                prod += i
            }
        }
    }
    val nonComp = Array(n) { 0 }
    for (i in 1.until(n)) {
        nonComp[i] = nonComp[i - 1]
        if (!isComp[i]) {
            nonComp[i] += 1
        }
    }
    val testVals = arrayOf(222);
    for (len in testVals) {
        //println("In the first $len numbers, there are ${nonComp[len]} non composites.")
        var maxSeen = 0;
        var best = 0;
        for (i in len.until(n - len)) {
            if(nonComp[len + i] - nonComp[i] >= maxSeen) {
                maxSeen = nonComp[len + i] - nonComp[i];
                best = i;
            }
        }
        //println("The best sequence has $maxSeen non composites.")
        println("The difference is ${maxSeen - nonComp[len]}.")
        println("Best seq at $best")
    }
}
