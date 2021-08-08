#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

void findLIS(const vector<int> a, vector<int>& LIS, vector<int>& cntLIS, int i) {
    int j = 0;
    if (!LIS.empty()) {
        int j = *lower_bound(LIS.begin(), LIS.end(), a[i]);
    }
    if (j == LIS.size()) {
        LIS.pb(a[i]);
    } else if (a[i] < LIS[j]) {
        LIS[j] = a[i];
    }
    cntLIS[i] = j;
}

void findLDS(const vector<int> a, vector<int>& LDS, vector<int>& cntLDS, int i) {
    int j = 0;
    if (!LDS.empty()) {
        while (a[i] > LDS[j] && j < LDS.size()) j++;
    }
    if (j == LDS.size()) {
        LDS.pb(a[i]);
    } else if (a[i] < LDS[j]) {
        LDS[j] = a[i];
    }
    cntLDS[i] = j;
}

void solve() {
    int n;
    vector<int> a;

    while (cin >> n) {
        a.clear();
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            a.pb(tmp);
        }

        vector<int> LIS, LDS;
        vector<int> cntLIS(a.size(), 1), cntLDS(a.size(), 1);
        for (int i = 0, j = a.size() - 1; i < a.size(); i++, j--) {
            findLIS(a, LIS, cntLIS, i);
            findLDS(a, LDS, cntLDS, j);
        }

        int mx = 0;
        for (int i = 0; i < a.size(); i++) {
            mx = max(mx, 2 * min(cntLIS[i], cntLDS[i]) + 1);

        }
        cout << mx << endl;
    }
}   

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


