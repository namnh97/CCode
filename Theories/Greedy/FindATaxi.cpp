#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

int findingTaxi(vector<char> a, int k) {
    int result = 0;
    vector<int> user;
    vector<int> taxi;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'U') {
            user.push_back(i);
        } else if (a[i] == 'T') {
            taxi.push_back(i);
        }
    }
    int i = 0, j = 0;
    while (j < taxi.size() && i < user.size()) {
        if (abs(user[i] - taxi[i]) <= k) {
            result++;
            i++;
            j++;
        } else if (user[i] > taxi[j]) {
            j++;
        } else {
            i++;
        }
    }
    return result;
}

void solve() {
    int k;
    vector<char>
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}