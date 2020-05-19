package medium.standard

// https://codeforces.com/gym/102219/problem/J
// This problem asks to topological sort 5 elements.
// I implemented topological sort rather than brute force,
// which made it take much longer than it should rightfully have.
// Otherwise, this problem would be in easy
private class Plate(val index: Int) {
    var order = 0;
    val smallerPlates = mutableListOf<Plate>();
}

fun main() {
    val plates = Array(5) { Plate(it) }
    for (i in 0..4) {
        var (a, b, c) = readLine()!!.toCharArray()
        if (b == '<') {
            val temp = c
            c = a;
            a = temp;
        }
        plates[a - 'A'].smallerPlates.add(plates[c - 'A'])
    }
    if (!topSort(plates)) {
        println("impossible")
    } else {
        plates.sortBy { it.order }
        for (plate in plates) {
            print('A' + plate.index)
        }
    }
    println()
}

private var order = 0

private fun topSort(plates: Array<Plate>): Boolean {
    val seen = Array(5) { 0 };
    for (i in 0..4) {
        if (seen[i] == 0) {
            if (!dfs(plates[i], seen)) {
                return false
            }
        }
    }
    return true
}

private fun dfs(plate: Plate, seen: Array<Int>): Boolean {
    seen[plate.index] = 1
    for (p in plate.smallerPlates) {
        if (seen[p.index] == 1) {
            return false
        } else if (seen[p.index] == 0) {
            if(!dfs(p, seen)){
                return false
            }
        }
    }
    plate.order = order++;
    seen[plate.index] = 2
    return true;
}
