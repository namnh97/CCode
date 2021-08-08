#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

const int MAX = 100000007;
vector<int> digits;

vector<int> findPrimes(int n) {
    vector<int> mark(n + 1, true);
    mark[0] = false;
    mark[1] = true;
    for (int i = 2; i * i <= n; i++) {
        if (mark[i] == true)
            for (int j = i; j * 2 <= n; j += i) {
                mark[j] = false;
            }
    }
    return mark;
}

bool isAna(int n, vector<int> primes) {
    vector<int> a;
    while (n > 0) {
        a.pb(n % 10);
        n /= 10;
    }

    for (auto &it : a) {
        if (it % 2 == 0 || it == 5) {
            return false;
        }
    }

    do {
        int number = 0;
        for (int i = 0; i < a.size(); i++) {
            number += number * 10 + a[i];
        }
        if (primes[number]) return true;
    } while(std::next_permutation(a.begin(), a.end()));
    return true;
}

vector<int> findAnas(int n) {
    vector<int> primes = findPrimes(n);
    vector<int> anas;

    for (int i = 3; i <= n; i += 2) {
        if (primes[i]) {
            if (isAna(i, primes)) {
                anas.pb(i);
            }
        }
    }

    return anas;
}

void solve() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> anas = findAnas(n);
        int m = anas.size();
        int index = m - 1;
        for (; index > 0 && anas[index] > n; index--)
        index++;
        if (index < m) {
            int pow10 = 1;
            while (n > 0) {
                n /= 10;
                pow10 *= 10;
            }
            if (anas[index] < pow10) {
                cout << anas[index] << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }
} 

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


