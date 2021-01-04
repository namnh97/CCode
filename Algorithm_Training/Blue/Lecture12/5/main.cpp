#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
void debugOut() {
    cerr << endl;
}

vector<int> a;
vector<int> jumps;
int t, n;

bool canReach(int k) {
    for (auto &it : jumps) {
        if (it > k)  return false;
        if (it == k) k--;
    }
    return true;
}

void solve() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        a.clear();
        jumps.clear();

        cout << "Case " << i << ": ";
        cin >> n;

        a.resize(n);
        jumps.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        jumps[0] = a[0];
        for (int i = 1; i < n; i++) {
            jumps[i] = a[i] - a[i - 1];
        }
        int left = 0, right = a[n - 1];
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canReach(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << ans << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


