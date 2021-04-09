# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1280/F
using namespace std;

bool evenPairity(vector<int> p, int k) {
    bool even = true;
    for (auto i = 0u; i < p.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (p[j] > p[j + 1]) {
                swap(p[j], p[j + 1]);
                // tricky case: We don't actually care about the pairity of permutation
                // with the 'E', just the numbers of the permutation
                if (p[j] != 2 * k + 1 && p[j + 1] != 2 * k + 1) {
                    even = !even;
                }
            }
        }
    }
    return even;
}

void printRotation(int dist) {
    for (int i = 0; i < dist; i++) {
        printf("l");
    }
    printf("u");
    for (int i = 0; i < dist; i++) {
        printf("r");
    }
    printf("d");

}

void simR(vector<int> &a) {
    swap(a[0], a[1]);
    swap(a[1], a[2]);
}

void simB(vector<int> &a, int k) {
    int tmp = a[2 * k + 2];
    for (int i = 2 * k + 2; i != 2 * k; i = (i + 1) % (4 * k + 2)) {
        a[i] = a[(i + 1) % (4 * k + 2)];
    }
    a[2 * k] = tmp;
}

void simD(vector<int> &a, int k) {
    int tmp = a[2 * k];
    for (int i = 2 * k; i != 2 * k + 2; i = (4 * k + 1 + i) % (4 * k + 2)) {
        a[i] = a[(4 * k + 1 + i) % (4 * k + 2)];
    }
    a[2 * k + 2] = tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases, k;
    cin >> cases;
    for (int t = 0; t < cases; t++) {
        cin >> k;
        vector<int> perm = vector<int>(4 * k + 2, 0);
        int Eloc = -1;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2 * k + 1; j++) {
                int ind;
                if (i == 0) {
                    ind = j;
                } else {
                    ind = (4 * k + 1) - j;
                }
                string nxt;
                cin >> nxt;
                if (nxt == "E") {
                    perm[ind] = 2 * k + 1;
                    Eloc = ind;
                } else {
                    perm[ind] = stoi(nxt) - 1;
                    if (perm[ind] >= 2 * k + 1) {
                        perm[ind] = 6 * k + 2 - perm[ind];
                    }
                }
            }
        }
        if (!evenPairity(perm, k)) {
            printf("SURGERY FAILED\n");
            continue;
        }
        printf("SURGERY COMPLETE\n");
        // put E at bottom right
        if (Eloc > 2 * k + 1) {
            while (perm[2 * k + 1] != 2 * k + 1) {
                swap(perm[Eloc], perm[Eloc - 1]);
                Eloc--;
                printf("r");
            }
        } else if (Eloc <= 2 * k) {
            while (perm[2 * k] != 2 * k + 1) {
                swap(perm[Eloc], perm[Eloc + 1]);
                Eloc++;
                printf("r");
            }
            swap(perm[2 * k + 1], perm[2 * k]);
            printf("d");
        }
        while (perm[4 * k + 1] != 4 * k + 1) {
            printf("D");
            simD(perm, k);
        }
        for (int i = 4 * k; i >= 2; i--) {
            if (i == perm[i]) {
                continue;
            }
            assert(i + 1 == perm[i + 1]);
            int successor = i == 2 * k ? i + 2 : i + 1;
            int succLoc = successor;
            while ((k > 1 && succLoc != 3) || (k == 1 && succLoc != 4)) {
                assert(perm[succLoc] == successor);
                if (perm[0] == i) {
                    printf("R");
                    simR(perm);
                }
                printf("B");
                simB(perm, k);
                succLoc = (succLoc + 4 * k + 1) % (4 * k + 2);
                if (succLoc == 2 * k + 1) {
                    succLoc--;
                }
            }
            while (perm[2] != i) {
                printf("R");
                simR(perm);
            }
            while (perm[4 * k + 1] != 4 * k + 1) {
                printf("D");
                simD(perm, k);
            }
            assert(i == perm[i]);
        }
        printf("\nA ");
        printRotation(k);
        printf("\nB ");
        printRotation(2 * k);
        printf("\nC ");
        for (int i = 0; i < 2 * k; i++) {
            printf("A");
        }
        printf("\nD ");
        for (int i = 0; i < 4 * k; i++) {
            printf("B");
        }
        printf("\nR ");
        for (int i = 0; i < k + 2; i++) {
            printf("B");
        }
        printf("CBCDAA");
        for (int i = 0; i < k + 2; i++) {
            printf("D");
        }
        printf("\nDONE\n");
    }
    return 0;
}