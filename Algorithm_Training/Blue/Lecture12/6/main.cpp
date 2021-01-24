#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 10000;
const int MAX_A = 1000;
const double eps = 1e-7;


void solve() {
    int n, k; cin >> n >> k;
    int energy[MAX];

    double sumEnergy = 0;
    for (int i = 0; i < n; i++) {
        cin >> energy[i];
        sumEnergy += energy[i];
    }

    double left = 0, right = MAX_A;

    while (right - left > eps) {
        double mid = left + (right - left) / 2;
        double sumLost = 0;
        for (int i = 0; i < n; i++) {
            if (energy[i] > mid) {
                sumLost += energy[i] - mid;
            }
        }
        if (mid * n < sumEnergy - sumLost * k / 100) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%.9f", left);
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}