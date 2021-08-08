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

const int MAXN = 100;
struct node {
	int val;
	node *left, *right;
	node() {}
	node(node *l, node *r, int v) {
		left = l;
		right = r;
		val = v;
	}
};


int arr[MAXN];
node* version[MAXN];

void build(node *n, int low, int high) {
	if (low == high) {
		n->val = arr[low];
		return;
	}
	int mid = (low + high) / 2;
	n->left = new node(NULL, NULL, 0);
	n->right = new node(NULL, NULL, 0);
	build(n->left, low, mid);
	build(n->right, mid + 1, high);
	n->val = n->left->val + n->right->val;
}

void solve() {

}



int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	solve();
	return 0;
}

