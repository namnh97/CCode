//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/samu-and-her-birthday-party-1/
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

int count1(int value) {
    int result = 0;
    while (value) {
        if (value & 1) {
            result++;
        }
        value = value >> 1;
    }
    return result;
}

void solve() {
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int maxDish = pow(2, k);

        vector<string> friendDishes;
        for (int i = 0; i < n; i++) {
            string tmp; cin >> tmp;
            friendDishes.pb(tmp);
        }
        
        int result = INT_MAX;
        for (int cas = 1; cas < maxDish; cas++) {
            bool satisfied = true;
            for (int friendDish = 0; friendDish < n; friendDish++) {
                bool flag = false;
                for (int dish = 0; dish < friendDishes[friendDish].size(); dish++) {
                    if (friendDishes[friendDish][dish] == '1' && (cas & (1 << dish))) {
                        flag = true;
                        break;
                    }
                }
                if (flag == false) {
                    satisfied = false;
                    break;
                }
            }
            if (satisfied) {
                result = min(result, count1(cas));
            }
        }
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


