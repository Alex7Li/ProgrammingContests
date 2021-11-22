# include <bits/stdc++.h>
//https://codeforces.com/problemset/problem/1280/F
using namespace std;

void print(int *a[], int k) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 * k + 1; j++) {
            printf("%.2d ", a[i][j]);
        }
        printf("\n");
    }
}

void rotate(int *a[], int k, int mid) {
    for (int j = 2 * k; j > mid; j--) {
        a[1][j] = a[1][j - 1];
    }
    a[1][mid] = a[0][mid];
    for (int j = mid; j < 2 * k; j++) {
        a[0][j] = a[0][j + 1];
    }
    a[0][2 * k] = a[1][2 * k];
    a[1][2 * k] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char move;
    int k;
    cout << "Enter k" << endl;
    cin >> k;
    int *a[2];
    for (int i = 0; i < 2; i++) {
        a[i] = (int *) malloc((2 * k + 1) * sizeof(int));
        for (int j = 0; j < 2 * k + 1; j++) {
            if (i == 0) {
                a[i][j] = j + 1;
            } else {
                a[i][j] = (4 * k + 1) - j;
            }
        }
    }
    a[1][2 * k] = 0;
    while (true) {
        cin >> move;
        switch (move) {
            case 'p':
                print(a, k);
                break;
            case 'a':
                rotate(a, k, k);
                break;
            case 'b':
                rotate(a, k, 0);
                break;
            case 'A':
                for (int i = 0; i < 2*k; i++) {
                    rotate(a, k, k);
                }
                break;
            case 'B':
                for (int i = 0; i < 4*k; i++) {
                    rotate(a, k, 0);
                }
                break;
        }
    }
    return 0;
}