//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3146
#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
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

void solve() {
    int n;
    stack<int> s;
    queue<int> q;
    priority_queue<int, vector<int>> pq;
    while (cin >> n) {
        bool isQueue = true, isStack = true, isPQ = true;
        while (!s.empty()) s.pop();
        while (!q.empty()) q.pop();
        while (!pq.empty()) pq.pop();
        for (int i = 0; i < n; i++) {
            int type, value; cin >> type; cin >> value;
            if (type == 1) {
                s.push(value);
                q.push(value);
                pq.push(value);
            } else {
                if (s.empty() || q.empty() || pq.empty()) {
                    isStack = false;
                    isQueue = false;
                    isPQ = false;
                    continue;
                }

                if (s.top() != value) {
                    isStack = false;
                }
                if (q.front() != value) {
                    isQueue = false;
                }
                if (pq.top() != value) {
                    isPQ = false;
                }
                s.pop(); q.pop(); pq.pop();
            }
        }
        if (isQueue == false && isStack == false && isPQ == false) {
            cout << "impossible" << endl;
        } else if (isQueue + isStack + isPQ > 1) {
            cout << "not sure" << endl;
        } else if (isStack == true) {
            cout << "stack" << endl;
        } else if (isQueue == true) {
            cout << "queue" << endl;
        } else {
            cout << "priority queue" << endl;
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
