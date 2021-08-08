#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

struct SegmentTree {
    vector<int> a;
    vector<int> segTree;
    int n;

    SegmentTree(vector<int> _a) {
        this->a = _a;
        this->n = _a.size();

        int h = (int)ceil(log2(this->n));
        int treeSize = 2 * (int) pow(2, h) - 1;
        segTree = vector<int>(treeSize);
        build(0, this->n - 1, 0);
    }

    void build(int left, int right, int index) {
        if (left == right) {
            segTree[index] = a[left];
            return;
        }

        int mid = (left + right) / 2;

        build(left, mid, 2 * index + 1);
        build(mid + 1, right, 2 * index + 2);

        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    void update(int left, int right, int index, int pos, int value) {
        if (pos < left || pos > right) {
            return;
        }

        if (left == right) {
            if (left == pos) {
                segTree[index] += value;
                a[pos] += value;
            }
            return;
        }

        int mid = (left + right) / 2;

        update(left, mid, 2 * index + 1, pos, value);
        update(mid + 1, right, 2 * index + 2, pos, value);

        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    int sumRange(int index, int left, int right, int from, int to) {
        if (left > to || right < from) {
            return 0;
        }

        if (from <= left && right <= to) {
            return segTree[index];
        }

        int mid = (left + right) / 2;;

        int sumLeft = sumRange(2 * index + 1, left, mid, from, to);
        int sumRight = sumRange(2 * index + 2, mid + 1, right, from, to);

        return sumLeft + sumRight;
    }
};

void solve() {
    int nTest; cin >> nTest;
    for (int test = 1; test <= nTest; test++) {
        cout << "Case " << test << ":" << endl;

        int n, q; cin >> n >> q;
        vector<int> sacks(n);
        for (int i = 0; i <= n - 1; i++) {
            cin >> sacks[i];
        }

        SegmentTree tree(sacks);
        int pos;
        for (int i = 0; i < q; i++) {
            int type; cin >> type;
            switch (type)
            {
                case 1:
                    cin >> pos;
                    cout << tree.a[pos] << endl;
                    tree.update(0, n - 1, 0, pos, -tree.a[pos]);
                    break;
                case 2:
                    cin >> pos;
                    int money; cin >> money;
                    tree.update(0, n - 1, 0, pos, money);
                    break;
                default:
                    int from, to; cin >> from >> to;
                    cout << tree.sumRange(0, 0, n - 1, from, to) << endl;
                    break;
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


