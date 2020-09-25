#include <iostream>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <set>

#define ll long long
// Problem: find some cool looking set of natural numbers whose recipricoal sum is 1
using namespace std;

// Fraction class
// operator+ to add
class Fraction {
public:
    ll num;
    ll den;

    ll gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    ll lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

    Fraction &reduce() {
        ll new_den = gcd(num, den);
        den = den / new_den;
        num = num / new_den;
        return *this;
    }

    Fraction(int numerator, int denominator) : num(numerator), den(denominator) { reduce(); }

    Fraction operator+(const Fraction &b) {
        ll lcd = lcm(den, b.den);
        if (lcd > INT32_MAX) {
            cerr << "There will be overflow soon.";
        }
        ll new_num = (num * (lcd / den)) + (b.num * (lcd / b.den));
        return Fraction(new_num, lcd).reduce();
    }

    bool operator==(Fraction b) {
        reduce();
        b.reduce();
        return (num == b.num) && (den == b.den);
    }
};

ostream &operator<<(ostream &os, const Fraction &b) {
    os << b.num << '/' << b.den;
    return os;
}


// convert a set to fractions
vector<Fraction> convertSetToReciprocals(vector<int> vals) {
    vector<Fraction> reciprocals;
    for (int v: vals) {
        Fraction frac(1, v);
        reciprocals.push_back(frac);
    }
    return reciprocals;
}

// add the set of fractions together
Fraction sumFractions(vector<Fraction> vals) {
    Fraction sum(0, 1);
    for (Fraction v: vals) {
        sum = sum + v;
    }
    return sum;
}

Fraction sumReciprocals(vector<int> vals) {
    return sumFractions(convertSetToReciprocals(vals));
}

// function to determine sum of a set
// return sum

// function to check if prime
bool isPrime(const int &n) {
    if(n==1){
        return false;
    }
    int factors = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ++factors;
        }
    }
    if (factors > 1) {
        return false;
    }
    return true;
}


// return the number of primes
int numPrimes(const vector<int> &set) {
    int num = 0;
    for (int i = 0; i < set.size(); ++i) {
        if (isPrime(set[i])) {
            ++num;
        }
    }
    return num;
}


// Generate Table of Seeds
// 1/2 + 1/3 + 1/6
vector<vector<int>> seeds = {
        {2, 3, 6},
        {2, 4, 10, 12, 15},
        {3, 4, 5,  6,  20},
};

// Brute force set selection: takes in set size and value range
// Generate several 'seeds'
void generateSeeds(int min, int max, int depth, vector<int> cur) {
    if (depth == 0) {
        if (sumReciprocals(cur) == Fraction(1, 1)) {
            seeds.push_back(cur);
        }
        return;
    }
    for (int i = min + 1; i <= max; i++) {
        cur.push_back(i);
        generateSeeds(i, max, depth - 1, cur);
        cur.pop_back();
    }
}


// Apply Alex's technique with a seed to get more
/**
 * v is a sorted set of integers that recpiri-sum to 1.
 * seeds are more sorted sets of integers that recipri-sum to 1.
 */
/**
 * v is a sorted set of integers that recpiri-sum to 1.
 * seeds are more sorted sets of integers that recipri-sum to 1.
 */
vector<ll> improve(vector<ll> v, vector<vector<int>> &seeds) {
    set<ll> vSet(v.begin(), v.end());
    assert(v.size() == vSet.size() && "Sets the same size");
   // assert(sumReciprocals(v) == Fraction(1, 1) && "Set sums to 1");
    for (int i = 0; i < v.size(); i++) {
        if (isPrime(v[i])) {
            continue;
        } else if (isPrime(v[i] + 1) && vSet.find(v[i] + 1) == vSet.end()) {
            // Split it up.
            for (int j = 0; j < seeds.size(); j++) {
                // Elements to add.
                set<ll> newSet;
                ll base = v[i] * (v[i] + 1);
                bool pos = true;
                // Add all the elements.
                for (int k = 0; k < seeds[j].size(); k++) {
                    ll newVal = base * seeds[j][k];
                    if (vSet.find(newVal) == vSet.end()) {
                        newSet.insert(base * seeds[j][k]);
                    } else {
                        pos = false;
                    }
                }
                if (!pos) {
                    continue;
                }
                // Union has no conflicts, merge.
                // First replace the value with the one higher
                v[i] = v[i] + 1;
                // Add in values that recipri-sum to v[i]*(v[i]+1)
                for (ll newEl : newSet) {
                    v.push_back(newEl);
                }
                sort(v.begin(), v.end());
                return v;
            }
        }
    }
    // Could not improve it.
    return v;
};

int main() {
    vector<int> temp;
    generateSeeds(0, 70, 4, temp);
    vector<ll> start(1, 1);
    for (int i = 0; i < 22; i++) {
        start = improve(start, seeds);
    }
    cout << '{';
    for (int i = 0; i < start.size(); i++) {
        cout << start[i] << ", ";
    }
    cout << '}' << endl;
    return 0;
}
