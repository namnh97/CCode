#include<bits/stdc++.h>
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

long long int n, m; 
vector<int> a;
long long int cutWood(long long int height) {
    long long int res = 0;
    for (long long int i = 0; i < (long long int)a.size(); i++) {
        if (a[i] > height) res += a[i] - height;
    }
    return res;
}
void solve() {
    cin >> n >> m;
    long long int maxTree = 0;
    for (int i = 0; i < n; i++) {
        long long int tmp;
        cin >> tmp;
        a.pb(tmp);
        maxTree = max(maxTree, tmp);
    }
    long long int left = 0, right = maxTree, mid;
    long long int h = 0;
    while (left <= right) {
        mid = left + ((right - left) / 2);
        long long int cutted = cutWood(mid);

        if (cutted > m) {
            left = mid + 1;
            if (mid > h) {
                h = mid;
            }
        } else if (cutted < m) {
            right = mid - 1;
        } else {
            h = mid;
            break;
        }
    }
    cout << h;
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


