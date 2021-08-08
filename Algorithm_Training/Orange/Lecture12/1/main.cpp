#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

vector<int> missles;
int missle;

void solve() {
    int nTests = 0;
    while(1) {
        cin >> missle;
        if (missle == -1) {
            break;
        }

        missles.clear();
        missles.pb(missle);
        while (1) {
            cin >> missle;
            if (missle == -1) break;
            missles.pb(missle);
        }
        vector<int> result(missles.size(), 1);
        int maxLength = 1;
        for (int i = 1; i <= missles.size() - 1; i++) {
            for (int j = 0; j < i; j++) {
                if (missles[i] <= missles[j] && result[i] < result[j] + 1) {
                    result[i] = result[j] + 1;
                    maxLength = max(maxLength, result[i]);
                }
            }
        }
        cout << "Test #" << ++nTests << ":" << endl;
        cout << "  maximum possible interceptions: " << maxLength << endl;
        cout << endl;
    }   
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


