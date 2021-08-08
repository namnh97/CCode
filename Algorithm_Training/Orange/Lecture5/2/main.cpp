#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

int n, k;
void solve() {
    cin >> n >> k;
    int *a = new int[n];
    int mini = INT_MAX;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res += a[i];
        mini = min(mini, abs(a[i]));
    }
    int ki = 1, index = 0;
    for (; ki <= k; ki++) {
        if (index >= n || a[index] >= 0) {
            break;
        }
        res += a[index] * -2;
        index++;
    }
    ki--;
    if (ki <= k) {
        if ((k - ki) % 2 != 0) {
            res -= mini * 2;
        }
    }
    cout << res;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


