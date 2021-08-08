//https://codeforces.com/problemset/problem/448/C
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>


using namespace std;

bool canFill(vector<int> vessels, ll capacity, int m) {
    int nContainers = 0;
    ll container = 0;
    for (int i = 0; i < vessels.size(); i++) {
        if (capacity < vessels[i]) return false;
        if (container + vessels[i] > capacity) {
            container = 0;
        }
        if (container == 0) nContainers++;

        if (nContainers > m) return false;

        container += vessels[i];
    }
    return true;
}

ll search(vector<int> vessels, ll total, int m) {
    ll left = 0;
    ll right = total;
    ll result = 0;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (canFill(vessels, mid, m)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

void solve() {
    int m, n;
    while (cin >> n >> m) {
        vector<int> vessels;
        ll total = 0;
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            vessels.pb(tmp);
            total += tmp;
        }

        ll result = search(vessels, total, m);
        cout << result << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


