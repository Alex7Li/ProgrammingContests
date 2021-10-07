package math.implementation

//https://codeforces.com/contest/1171/problem/D
fun main(){
    val (x,y,z) = readLine()!!.split(" ").map{it.toInt()}
    var (a,b,c) = readLine()!!.split(" ").map{it.toInt()}
    if(x>a || y >a+b-x || z > a+b+c-x-y) print("NO") else print("YES")
}
