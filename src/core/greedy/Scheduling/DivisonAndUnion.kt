package core.greedy.Scheduling

import java.util.*

// https://codeforces.com/contest/1171/problem/F
class Event(val type: Int, val time: Int, val index: Int) : Comparable<Event> {
    override fun compareTo(other: Event): Int {
        return time.compareTo(other.time)
    }
}

fun main() {
    val T = readLine()!!.toInt()
    for (t in 0 until T) {
        val n = readLine()!!.toInt()
        val group = IntArray(n) { _ -> 2 }
        val Q: PriorityQueue<Event> = PriorityQueue()
        for (i in 0 until n) {
            val (st, end) = readLine()!!.split(" ").map { it.toInt() }
            Q.add(Event(1, st * 2 - 1, i))
            Q.add(Event(-1, end * 2, i))
        }
        var sum = 0
        do {
            val event = Q.remove()
            group[event.index] = 1
            sum += event.type
        } while (sum > 0 && !Q.isEmpty())
        if (group.contains(2)) {
            print(group.joinToString(" ") + "\n")
        } else {
            print("${-1}\n");
        }
    }
}