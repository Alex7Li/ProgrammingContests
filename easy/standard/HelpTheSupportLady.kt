package easy.standard

//https://codeforces.com/gym/102219/problem/K
// A simple problem that comes down to sorting and searching
private fun main() {
    val cases = readLine()!!.toInt()
    for (t in 1..cases){
        val n = readLine()!!.toInt()
        val requests = readLine()!!.split(" ").map { it.toInt() }.sorted()
        var happy = 0
        var time = 0
        for (i in 0.until(n)){
            if(time <= requests[i]){
                time += requests[i]
                happy++
            }
        }
        println("Case #${t}: " + happy)
    }
}