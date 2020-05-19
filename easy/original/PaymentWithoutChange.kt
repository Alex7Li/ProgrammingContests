package easy.original

//http://codeforces.com/problemset/problem/1256/A
fun main(){
    val q = readLine()!!.toInt()
    for (i in 0.until(q)){
        val (a, b, n, S) = readLine()!!.split(" ").map { x->x.toLong() }
        var possible = true
        if(a*n+b<S){
            possible = false
        }else if(S%n > b){
            possible = false;
        }
        println(if(possible) "YES"  else "NO")
    }
}
