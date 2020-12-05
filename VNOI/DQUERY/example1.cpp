#include <iostream>
#include <vector>
#include <algorithm>
	
using namespace std;
	
const int N = 30003;
	
struct Node {
    int l, r;
    int sum;
    Node *L, *R;
	
    Node(int l, int r) {
        this->l = l; this->r = r;
        sum = 0;
        L = R = nullptr;
    }
	
    Node* update(int i) {
        Node* cur = new Node(l, r);
        if (l == r) {
            cur->sum = sum + 1;
        } else {
            if (i <= (l + r >> 1)) {
                cur->L = L->update(i);
                cur->R = R;
            } else {
                cur->R = R->update(i);
                cur->L = L;
            }
            cur->sum = cur->L->sum + cur->R->sum;
        }
        return cur;
    }

    int getPrefixSum(int i) {
        if (i < l) return 0;
        if (r <= i) return sum;
        return L->getPrefixSum(i) + R->getPrefixSum(i);
    }
	
};
	
 
	
Node* build(int i, int j) {
    Node* cur = new Node(i, j);
    if (i != j) {
        cur->L = build(i, i + j >> 1);
        cur->R = build((i + j >> 1) + 1, j);
    }
    return cur;
}
	
 
	
void compress(int a[], int n) {
    vector<int> b (a + 1, a + 1 + n);
    sort(begin(b), end(b));
    b.resize(unique(begin(b), end(b)) - begin(b));
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(begin(b), end(b), a[i]) - begin(b) + 1;
}
	
int a[N];
int last[N];
Node* root[N];
	
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    compress(a, n);
    for (int i = 1; i <= n; ++i) last[a[i]] = n + 1;
    root[n + 1] = build(1, n + 1);
    for (int i = n; i >= 1; --i) {
        root[i] = root[i + 1]->update(last[a[i]]);
        last[a[i]] = i;
    }
	
    int q; cin >> q;
    while (q--) {
        int i, j; cin >> i >> j;
        cout << (j - i + 1) - root[i]->getPrefixSum(j) << '\n';
    }
	
    return 0;
}