package medium.standard

import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.sqrt
// http://codeforces.com/gym/102367/problem/B
private fun isSquare(x : Long) : Boolean{
    val root = sqrt(x.toDouble()-.1).toLong()
    return root*root == x || (root+1)*(root+1)==x
}
fun main(){
    val k = readLine()!!.toLong()
    val factors = ArrayList<Long>()
    for (i in 1..sqrt(k.toDouble()+.1).toLong()){
        if(k%i==0L){
            factors.add(i)
        }
    }
    val answers = TreeSet<Long>()
    for(f in factors){
        val g = k/f;
        if((f+g)%2L!=0L){
            continue;
        }
        val m = (f+g)/2L
        val n = g - m
        if(n!=0L && m!=0L) {
            answers.add(n * n)
            answers.add(-(m * m))
        }
    }
    var i = 1L
    while(i*i<k){
        val sq = i*i
        if(isSquare(k - sq)){
            if(k-sq != 0L) {
                answers.add(-sq)
                answers.add(-(k - sq))
            }
        }
        i++
    }
    println(answers.size)
    println(answers.joinToString(" "))
}