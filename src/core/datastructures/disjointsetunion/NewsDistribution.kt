package core.datastructures.disjointsetunion

// https://codeforces.com/problemset/problem/1167/C
fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val groupSize = IntArray(n) { _ -> 1 }
    val parent = IntArray(n) { i -> i }
    for (i in 0 until k) {
        val group = readLine()!!.split(" ").map { it.toInt() - 1 }.drop(1).sorted()
        for (j in group) {
            mergeGroups(j, group[0], parent, groupSize);
        }
    }
    print(groupSize.mapIndexed { index, _ -> groupSize[getAncestor(index, parent)] }.joinToString(" ") + "\n")
}

private fun getAncestor(ind: Int, parent: IntArray): Int {
    if (parent[ind] != ind) {
        parent[ind] = getAncestor(parent[ind], parent)
    }
    return parent[ind]
}

private fun mergeGroups(ind1: Int, ind2: Int, parent: IntArray, groupSize: IntArray) {
    var root1 = getAncestor(ind1, parent)
    var root2 = getAncestor(ind2, parent)
    if (root1 != root2) {
        if (groupSize[root1] > groupSize[root2]) {
            root1 = root2.also { root2 = root1 } // fancy swap
        }
        groupSize[root1] += groupSize[root2];
        parent[root2] = root1;
    }
}
