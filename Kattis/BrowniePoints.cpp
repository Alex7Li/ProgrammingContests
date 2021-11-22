# include <bits/stdc++.h>

using namespace std;
const int N = 200003;
int n;
int t[2 * N] = {};// init to 0

void modify(int p, int increment) {  // increase value at position p by increment
    for (t[p += n] += increment; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += t[l++];
        if (r & 1) res += t[--r];
    }
    return res;
}

struct Point {
    int x, y;
};

int cmpx(const void *a, const void *b) {
    const Point *ap = (Point *) a, *bp = (Point *) b;
    if (ap->x == bp->x && ap->y == bp->y)
        return 0;
    if (ap->x < bp->x || (ap->x == bp->x && ap->y < bp->y))
        return -1;
    return 1;
}

int cmpy(const void *a, const void *b) {
    const Point *ap = (Point *) a, *bp = (Point *) b;
    if (ap->x == bp->x && ap->y == bp->y)
        return 0;
    if (ap->y < bp->y || (ap->y == bp->y && ap->x < bp->x))
        return -1;
    return 1;
}

//https://open.kattis.com/contests/hxegw8/problems/browniepoints2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Point points[N];
    int yMap[N];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { scanf("%d %d", &points[i].x, &points[i].y); }
    qsort(points, n, sizeof(Point), cmpy);
    for (int i = 0; i < n; ++i) {
        yMap[points[i].y] = i;

    }
    qsort(points, n, sizeof(Point), cmpx);
    int prevXInd = 0;
    int nextXInd = 0;
    map<int, int> sameYsoFar;
    for (int i = 0; i < n; i++) {
        sameYsoFar[points[i].y]++;
        if (nextXInd == i) {
            prevXInd = nextXInd;
            while (nextXInd < n && points[nextXInd].x == points[i].x) { nextXInd++; };
        }
        int botLeft = query(0, points[i].x); // points strictly to the bottom left of the point
        int left = nextXInd; // points (not strictly) to the left of the point
        int bottom = yMap[points[i].y]; // points (not strictly) below the point
        int upLine = i - prevXInd; //points on the line strictly above the point
        int leftLine = sameYsoFar[points[i].y]; //point on the line to the left of the point, inclusive
        int topRight = n - (left + bottom - botLeft -upLine - leftLine); //points strictly above and to the right of the point
        int stanScore = botLeft + topRight;
        modify(points[i].y, 1);
    }
    vector<int> ans;
    printf("Stan: %d; Ollie: ", ans[0]);
    for (unsigned int j = 0; j < ans.size(); ++j) {
        printf("%d ", ans[j]);
    }
    printf(";\n");
    return 0;
}