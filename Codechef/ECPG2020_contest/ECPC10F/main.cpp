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
struct node {
	int freq;
	int xor_value;
	int l,  r;
};
const int N = 2e5 + 5;
int last, root[N];
node segt[10 * N];
int actual[N], mapped[N];
vector<pair<int ,int>> A, Temp;

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
	int mid = (l + r) / 2;
	segt[i].l = initialize(l, mid, segt[i].l);
	segt[i].r = initialize(mid + 1, r, segt[i].r);
	return i;
}

int insert(int l, int r, int x, int v, int i) {
	if (l > x || r < x) return i;
	i = new_vertex(i);
	if (l == r) {
		segt[i].freq++;
		segt[i].xor_value = v;
		return i;
	}
	int mid = (l + r) / 2;
	segt[i].l = insert(l, mid, x, v, segt[i].l);
	segt[i].r = insert(mid + 1, r, x, v, segt[i].r);
	segt[i].freq = segt[segt[i].l].freq + segt[segt[i].r].freq;
	segt[i].xor_value = (segt[segt[i].l].xor_value ^ segt[segt[i].r].xor_value);
	return i;
}



void solve() {
	int n, q, l, r, k;
	cin >> n;
	A = vector<pair<int ,int>>(n);
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
	for (int i = 1; i <= n; ;i++) {
		root[i] = insert(0, n - 1, mapped[A[i - 1].second], A[i - 1].first, root[i - 1]);
	}
}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}


