#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

struct SegmentTree {
    vector<int> values;
    vector<int> segTree;

    SegmentTree(vector<int> _values) {
        this->values = _values;

        int n = _values.size();
        int h = (int)ceil(log2(n));
        int sizeTree = 2 * (int)pow(2, h) - 1;
        segTree = vector<int>(sizeTree, 0);
        build(0, n - 1, 0);
    }

    void build(int left, int right, int index) {
        if (left == right) {
            segTree[index] = values[left];
            return;
        }

        int mid = (left + right) / 2;

        build(left, mid, 2 * index + 1);
        build(mid + 1, right, 2 * index + 2);

        segTree[index] = segTree[2 * index + 1] * segTree[2 * index + 2];
    }

    void update(int left, int right, int index, int pos, int value) {
        if (pos < left || pos > right) {
            return;
        }

        if (left == right) {
            if (left == pos) {
                values[left] = value;
                segTree[index] = value;
            }
            return;
        }

        int mid = (left + right) / 2;

        if (pos <= mid) {
            update(left, mid, 2 * index + 1, pos, value);
        } else {
            update(mid + 1, right, 2 * index + 2, pos, value);
        }

        segTree[index] = segTree[2 * index + 1] * segTree[2 * index + 2];
    }

    int query(int left, int right, int from, int to, int index) {
        if (left > to || right < from) {
            return 1;
        }

        if (from <= left && right <= to) {
            return segTree[index];
        }

        int mid = (left + right) / 2;

        int leftValue = query(left, mid, from, to, 2 * index + 1);
        int rightValue = query(mid + 1, right, from, to, 2 * index + 2);

        return leftValue * rightValue;
    }
};

char convertResult(int result) {
    if (result == 0) {
        return '0';
    }

    if (result < 1) {
        return '-';
    }

    return '+';
}

int convert(int value) {
    if (value == 0) {
        return 0;
    }

    if (value < 0) {
        return -1;
    }

    return 1;
}

void solve() {
    int n, k;
    while (cin >> n >> k) {
        vi values(n);
        for (int i = 0; i < n; i++) {
            int temp; cin >> temp;
            values[i] = convert(temp);
        }

        SegmentTree tree(values);
        for (int i = 0; i < k; i++) {
            char command; cin >> command;
            if (command == 'C') {
                int pos, value; cin >> pos >> value;
                int temp = convert(value);
                tree.update(0, n - 1, 0, --pos, temp);
            } 
            
            if (command == 'P') {
                int from, to; cin >> from >> to;
                int result = tree.query(0, n - 1, --from, --to, 0);
                cout << convertResult(result);
            }
        }
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


