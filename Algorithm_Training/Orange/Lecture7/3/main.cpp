#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
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

const int MAX = 50001;
int phiCache[MAX] = {0};

int findPhi(int m) {
    if (phiCache[m] > 0) {
        return phiCache[m];
    }

    int n = m;
    int result = m;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result = result / i * (i - 1);
        }
    }
    if (n > 1) {
        result = result / n * (n - 1);
    }
    phiCache[m] = result;
    return result;
}

void solve() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        int res = 1;
        for (int i = 2; i <= n; i++) {
            res += findPhi(i) * 2;
        }
        cout << res << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


