#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

struct Node {
    ll minValue;
    ll lazyValue;
    Node() {
        this->minValue = 0;
        this->lazyValue = 0;
    }
    Node(ll _minValue, ll _lazyValue) {
        this->minValue = _minValue;
        this->lazyValue = _lazyValue;
    }
};

struct SegmentTree {
    vector<int> a;
    vector<Node> treeValue;

    SegmentTree(vector<int> _a) {
        this->a = _a;

        int h = (int)ceil(log2(_a.size()));
        int treeSize =  2 * pow(2, h) - 1;
        this->treeValue = vector<Node>(treeSize);

        build(0, _a.size() - 1, 0);
    }

    void build(int left, int right, int index) {
        if (left == right) {
            treeValue[index].minValue = a[left];
            return;
        }

        int mid = (left + right) / 2;
        build(left, mid, 2 * index + 1);
        build(mid + 1, right, 2 * index + 2);

        treeValue[index].minValue = min(treeValue[2 * index + 1].minValue, treeValue[2 * index + 2].minValue);
    }

    void updateRange(int left, int right, int from, int to, int value, int index) {
        if (left > right) { 
            return;
        }

        if (treeValue[index].lazyValue != 0) {
            treeValue[index].minValue += treeValue[index].lazyValue;
            if (left != right) {
                treeValue[2 * index + 1].lazyValue += treeValue[index].lazyValue;
                treeValue[2 * index + 2].lazyValue += treeValue[index].lazyValue;
            }
            treeValue[index].lazyValue = 0;
        }

        if (from > right || to < left) {
            return;
        }

        if (from <= left && right <= to) {
            treeValue[index].minValue += value;
            if (left != right) {
                treeValue[2 * index + 1].lazyValue += value;
                treeValue[2 * index + 2].lazyValue += value;
            }
            return;
        }

        int mid = (left + right) / 2;
        updateRange(left, mid, from, to, value, 2 * index + 1);
        updateRange(mid + 1, right, from, to, value, 2 * index + 2);

        treeValue[index].minValue = min(treeValue[2 * index + 1].minValue, treeValue[2 * index + 2].minValue);
    }

    void update(int from, int to, int value) {
        int n = this->a.size();

        if (from <= to) {
            updateRange(0, n - 1, from, to, value, 0);
            return;
        }

        updateRange(0, n - 1, from, n - 1, value, 0);
        updateRange(0, n - 1, 0, to, value, 0);
    }

    ll queryRange(int left, int right, int from, int to, int index) {
        if (left > right) {
            return INT_MAX;
        }

        if (treeValue[index].lazyValue != 0) {
            treeValue[index].minValue += treeValue[index].lazyValue;
            if (left != right) {
                treeValue[2 * index + 1].lazyValue += treeValue[index].lazyValue;
                treeValue[2 * index + 2].lazyValue += treeValue[index].lazyValue;
            }
            treeValue[index].lazyValue = 0;
        }

        if (from > right || to < left) {
            return INT_MAX;
        }

        if (from <= left && right <= to) {
            return treeValue[index].minValue;
        }

        int mid = (left + right) / 2;
        ll leftValue = queryRange(left, mid, from, to, 2 * index + 1);
        ll rightValue = queryRange(mid + 1, right, from, to, 2 * index + 2);

        return min(leftValue, rightValue);
    }

    ll query(int from, int to) {
        int n = this->a.size();

        if (from <= to) {
            return queryRange(0, n - 1, from, to, 0);
        }

        ll left = queryRange(0, n - 1, from, n - 1, 0);
        ll right = queryRange(0, n - 1, 0, to, 0);

        return min(left, right);
    }
};

vector<int> readOperation() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    string tmp;
    vector<int> result;

    while (ss >> tmp) {
        result.pb(atoi(tmp.c_str()));
    }
    
    return result;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTree tree(a);

    int m; cin >> m;
    string line;
    cin.get();
    for (int i = 0; i < m; i++) {
        vector<int> operation = readOperation();
        if (operation.size() == 3) {
            tree.update(operation[0], operation[1], operation[2]);
        } else {
            cout << tree.query(operation[0], operation[1]) << endl;
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


