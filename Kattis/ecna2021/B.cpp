#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int i;
    int j;
    int prev_i;
    int prev_j;
    int letters_used;
    int kinks_used;
} frame;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef vector<vvvb> vvvvb;
typedef vector<vvvvb> vvvvvb;

int main() {
    int rows, cols;
    cin >> rows;
    cin >> cols;
    vector<vector<char>> grid(rows, vector<char>(cols, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    int total_kinks;
    cin >> total_kinks;
    string word;
    cin >> word;
    int count = 0;
    vector<vvvvvb> explored(rows, vvvvvb(cols, vvvvb(3, vvvb(3,  vvb(1 + word.length(), vb(min(103, total_kinks + 1), false))))));

    for (int start_i = 0; start_i < rows; start_i++) {
        for (int start_j = 0; start_j < cols; start_j++) {
            if (grid[start_i][start_j] != word[0]) {
                continue;
            }
            vector<frame> stack;
            stack.push_back({start_i, start_j, start_i, start_j, 1, 0});
            while (stack.size()) {
                frame fr = stack[stack.size() - 1];
                stack.pop_back();
//cout << fr.letters_used << " " << fr.kinks_used << "\n";
                if (explored[fr.i][fr.j][fr.i - fr.prev_i + 1][fr.j - fr.prev_j + 1][fr.letters_used][fr.kinks_used]) {
                    continue;
                }
//                count++;
                explored[fr.i][fr.j][fr.i - fr.prev_i + 1][fr.j - fr.prev_j + 1][fr.letters_used][fr.kinks_used] = true;

                if (fr.letters_used == word.length()) {
                    if (fr.kinks_used == total_kinks) {
                        cout << "Yes\n";
                        return 0;
                    } else {
                        continue;
                    }
                }
                int i = fr.i, j = fr.j;
                vector<pair<int, int>> neighbors = {
                        {i,     j + 1},
                        {i,     j - 1},
                        {i + 1, j},
                        {i - 1, j},
                        {i + 1, j + 1},
                        {i + 1, j - 1},
                        {i - 1, j + 1},
                        {i - 1, j - 1}
                };
                for (auto p : neighbors) {
                    int ii = p.first, jj = p.second;
                    if (ii < 0 || jj < 0 || ii >= rows || jj >= cols) {
                        continue;
                    }
                    if (grid[ii][jj] != word[fr.letters_used]) {
                        continue;
                    }
                    if (count % 1000 == 0) {
                    }
                    int new_kinks = fr.kinks_used;
                    if (fr.letters_used > 1 &&
                        (ii - i != i - fr.prev_i || jj - j != j - fr.prev_j)) {
                        new_kinks++;
                        if (new_kinks > total_kinks) {
                            continue;
                        }
                    }
                    stack.push_back({ii, jj, i, j, fr.letters_used + 1, new_kinks});
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}
