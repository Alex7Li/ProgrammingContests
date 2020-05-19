package tools

import java.util.*
import kotlin.math.abs

fun main() {
    println("Enter the number to estimate as a rational")
    val numToEstimate = readLine()!!.toDouble()
    var number = numToEstimate;
    println("Enter the accuracy coefficient (default = .0005). Higher values mean worse estimates")
    var accuracy = .0005
    try {
        accuracy = readLine()!!.toDouble()
    }catch (n:NumberFormatException){};
    val continuedFraction:Deque<Int> = ArrayDeque<Int>()
    var intPart = number.toInt();
    continuedFraction.push(intPart)
    number = number - intPart
    while (abs(numToEstimate- evaluateFraction(continuedFraction)) > accuracy) {
        number = 1/number;
        intPart = number.toInt()
        continuedFraction.addLast(intPart)
        number = number - intPart
    }
    print(continuedFraction)
    var num = continuedFraction.removeLast();
    var denom = 1;
    while(continuedFraction.isNotEmpty()){
        val temp = num
        num = denom
        denom = temp
        num = num + denom*continuedFraction.removeLast()
    }
    println("\n$num/$denom")
    println(num.toDouble()/denom)
}

fun evaluateFraction(contFraction:Deque<Int>):Double {
    val first:Int = contFraction.pollFirst() ?: 0
    val ans:Double;
    if(contFraction.size==0) {
        ans = first.toDouble()
    }else {
        ans = first + 1.0 / evaluateFraction(contFraction)
    }
    contFraction.addFirst(first)
    return ans;
}