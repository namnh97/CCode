#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

int query(int left, int right) {
    if (left >= right) return -1;
    cout << "? " << left + 1 << " " << right + 1 << endl;
    int ans; cin >> ans;
    return ans - 1;
}

void solve() {
    int n; cin >> n;
    int left = 0, right = n;
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        int smax = query(left, right - 1);
        if (smax < mid) { // check from left to mid - 1
            int tmp = query(left, mid - 1);
            if (tmp == smax) {
                right = mid;
            } else {
                left = mid;
            }
        } else { // check from mid to right - 1
            int tmp = query(mid, right - 1);
            if (tmp == smax) {
                left = mid;
            } else {
                right = mid;
            }
        }
    }
    cout << "! " << right << endl;
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}