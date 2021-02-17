//https://www.spoj.com/problems/PRO/
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

struct Bill {
    int index;
    int value; 
};

int duration;
const int MAX = 1e6 + 5;
struct AscendingOrder {
    bool operator() (const Bill& a, const Bill& b) {
        return a.value < b.value;
    }
};

struct DescendingOrder {
    bool operator() (const Bill& a, const Bill &b) {
        return a.value > b.value;
    }
};

void solve() {
    int nbills = 0;
    priority_queue<Bill, vector<Bill>, DescendingOrder> minHeap;
    priority_queue<Bill, vector<Bill>, AscendingOrder> maxHeap;
    long long money = 0;
    bool taken[MAX] = {false};
    cin >> duration;
    while (duration--) {
        int receipts; cin >> receipts;
        for (int i = 0; i < receipts; i++) {
            int receipt; cin >> receipt;
            nbills++;
            minHeap.push((Bill){nbills, receipt});
            maxHeap.push((Bill){nbills, receipt});
        }
        while (taken[minHeap.top().index]) {
            minHeap.pop();
        }
        while (taken[maxHeap.top().index]) {
            maxHeap.pop();
        }
        money += maxHeap.top().value - minHeap.top().value;
        taken[minHeap.top().index] = taken[maxHeap.top().index] = true;
        minHeap.pop(); maxHeap.pop();
    }
    cout << money;
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


