#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

void solve() {
    int k;
    string s;
    cin >> k >> s;
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
    }
    sort(s.begin(), s.end());
    if (sum >= k) {
        cout << 0;
        return;
    }
    
    int count = 0;
    for (char c : s) {
        int number = c - '0';
        sum += 9 - number;
        count++;
        if (sum >= k) {
            break;
        }
    }
    cout << count;
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}
