//https://www.codechef.com/problems/RRATING
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

void solve() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> topHeap;
    priority_queue<int, vector<int>> maxHeap;
    int nReviews = 0;
    for (int i = 0; i < n; i++) {
        int type; cin >> type;
        if (type == 1) {
            nReviews++;
            int value; cin >> value;
            if (!topHeap.empty() && value > topHeap.top()) {
                int tmp = topHeap.top(); topHeap.pop();
                maxHeap.push(tmp);
                topHeap.push(value);
            } else {
                maxHeap.push(value);
            }
            if (nReviews % 3 == 0) {
                topHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        } else {
            if (topHeap.empty()) {
                cout << "No reviews yet" << endl;
            } else {
                cout << topHeap.top() << endl;
            }
        }
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


