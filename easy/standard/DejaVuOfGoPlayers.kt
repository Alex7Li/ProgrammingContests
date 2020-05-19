package easy.standard

/*
 * https://codeforces.com/gym/102056/problem/D
 * You play a game with an obvious strategy.
 */
private fun main() {
    val t = readLine()!!.toInt()
    for (i in 0.until(t)) {
        val (aj, bj) = readLine()!!.split(" ").map { it.toInt() }
        if(aj<=bj){
            println("Yes")
        }else{
            println("No")
        }
        readLine()
        readLine()
    }
}