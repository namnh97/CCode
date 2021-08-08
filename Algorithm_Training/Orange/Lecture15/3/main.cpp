#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

const char CLOSE = ')';
const char OPEN = '(';
struct Node {
    int close;
    int open;
    int match;
    Node(int _open, int _close, int _match) {
        this->open = _open;
        this->close = _close;
        this->match = _match;
    }

    Node() {
        this->open = 0;
        this->close = 0;
        this->match = 0;
    }

    Node operator+ (const Node other) const {
        int totalOpen = this->open + other.open;
        int totalClose = this->close + other.close;
        int totalMatch = min(this->open - this->match, other.close - other.match) + this->match + other.match;

        return Node(totalOpen, totalClose, totalMatch);
    }
};

struct SegmentTree {
    string word;
    vector<Node> segTree;
    
    SegmentTree(string _word) {
        this->word = _word;

        int n = _word.size();
        int h = (int)ceil(log2(n));
        int treeSize =  2 * (int)pow(2, h) - 1;

        segTree = vector<Node>(treeSize);
        build(0, n - 1, 0);
    }

    void build(int left, int right, int index) {
        if (left == right) {
            if (word[left] == OPEN) {
                segTree[index] = Node(1, 0, 0);
            } else {
                segTree[index] = Node(0, 1, 0);
            }
            return;
        }
        
        int mid = (left + right) / 2;

        build(left, mid, 2 * index + 1);
        build(mid + 1, right, 2 * index + 2);

        segTree[index] = segTree[2 * index + 1]  + segTree[2 * index + 2];
    }

    void updateWhole(int pos) {
        update(0, word.size() - 1, pos, 0);
    }

    void update(int left, int right, int pos, int index) {
        if (pos < left || pos > right) {
            return;
        }

        if (left == right) {
            if (left == pos) {
                if (word[pos] == OPEN) {
                    segTree[index] = Node(0, 1, 0);
                    word[pos] = CLOSE;
                } else {
                    segTree[index] = Node(1, 0, 0);
                    word[pos] = OPEN;
                }
            }
            return;
        }

        int mid = (left + right) / 2;

        if (pos <= mid) {
            update(left, mid, pos, 2 * index + 1);
        } else {
            update(mid + 1, right, pos, 2 * index + 2);
        }

        segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2];
    }

    bool isCorrect() {
        int n = word.size();
        return (segTree[0].match == n / 2 && n % 2 == 0);
    }
};

void solve() {
    int nTest = 10;
    for (int test = 1; test <= nTest; test++) {
        cout << "Test " << test << ":" << endl;

        int temp; cin >> temp;
        string word; cin >> word;
        SegmentTree tree(word);

        int nQuery; cin >> nQuery;
        for (int i = 0; i < nQuery; i++) {
            int k; cin >> k;
            if (k == 0) {
                if (tree.isCorrect()) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else {
                k = k - 1;
                tree.updateWhole(k);
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


