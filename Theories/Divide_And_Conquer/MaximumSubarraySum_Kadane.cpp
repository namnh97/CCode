#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

void maxSubArraySum(vector<int> a) {
    int result = a[0], max_ending_here = 0;
    int start = 0, end = 0, s = 0;
    for (int i = 0; i < a.size(); i++) {
        max_ending_here += a[i];
        if (result < max_ending_here) {
            result = max_ending_here;
            start = s;
            end = i;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum Subarray sum" << result << endl;
}
void solve() {
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


