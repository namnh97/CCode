#include<bits/stdc++.h>
using namespace std;

struct node {
    int freq;
    int xor_value;
    int l;
    int r;
};
const int N = 2e5 + 5;
int last, root[N];
node segt[10*N];

int new_vertex(int i) {
    segt[++last].freq = segt[i].freq;
    segt[last].l = segt[i].l;
    segt[last].r = segt[i].r;
    segt[last].xor_value = segt[i].xor_value;
    return last;
}

int initialize(int l, int r, int i) {
    i = new_vertex(i);
    if (l == r) {
        segt[i].l = segt[i].r = -1;
        return i;
    }
    int mid = (l + r) /2;
    segt[i].l = initialize(l, mid, segt[i].l);
    segt[i].r = initialize(mid + 1, r, segt[i].r);
    return i;
}

int Insert(int l, int r, int x, int v, int i) {
    if (l > x || r < x) return i;
    i = new_vertex(i);
    if (l == r) {
        segt[i].freq++;
		cerr << i << " " << segt[i].freq << endl << endl;
        segt[i].xor_value = v;
        return i;
    }
    int mid = (l + r) /2;
    segt[i].l = Insert(l, mid, x, v, segt[i].l);
    segt[i].r = Insert(mid + 1, r, x, v, segt[i].r);
    segt[i].freq = segt[segt[i].l].freq + segt[segt[i].r].freq;
	cerr << i << " " << segt[i].freq << endl;
    segt[i].xor_value = (segt[segt[i].l].xor_value ^ segt[segt[i].r].xor_value);
    return i;
}

int query(int id_l, int id_r, int l, int r, int k) {
    if (l == r) return l;
    int freq_left = segt[segt[id_r].l].freq - segt[segt[id_l].l].freq;
    int mid = (l + r) /2;
    if (freq_left >= k)
        return query(segt[id_l].l, segt[id_r].l, l, mid, k);
    else
        return query(segt[id_l].r, segt[id_r].r, mid + 1, r, k - freq_left);
}

int query_xor(int ids, int l, int r, int a, int b) {
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) return segt[ids].xor_value;
    int mid = (l + r) /2;
    return (query_xor(segt[ids].l, l, mid, a, b) ^ query_xor(segt[ids].r, mid + 1, r, a, b)) ;
}
int actual[N], mapped[N];

vector <pair<int, int> > A, Temp;

int main() {
    int n, q , l, r, k;
    cin >> n;
    A = vector<pair<int, int>>(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    Temp = A;
    sort(A.rbegin(), A.rend());
    for (int i = 0; i < n; i++) {
        mapped[A[i].second] = i, actual[i] = A[i].second;
    }
    last = -1;
    root[0] = initialize(0, n - 1, 0);
    A = Temp;
    for (int i = 1; i <= n; i++) {
        //// Build a tree for each prefix using segment tree of previous prefix
        root[i] = Insert(0, n - 1, mapped[A[i - 1].second], A[i - 1].first, root[i - 1]);
    }
    cin >> q;
    while (q--) {
        cin >> l >> r >> k;
        int kth = query(root[l - 1], root[r], 0, n - 1, k);
        int l_part = query_xor(root[l - 1], 0, n - 1, 0, kth);
        int r_part = query_xor(root[r], 0, n - 1, 0, kth);
        int ans = l_part ^ r_part;
        cout << ans << "\n";
    }
    return 0;
}
