#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };
const int maxn = 1000 * 100 + 10;

using namespace std;

struct node {
	node *left, *right;
	int stop;
	node() { 
		left = right = NULL;
		stop = 0;
	}
};
int n;
int bin[40];
node *root;
int a[maxn];

inline void make_binary(int x) { 
	for (int i = 0; i < 40; i++) {
		bin[i] = x % 2;
		x /= 2;
	}
}

inline void add(int index, node *root) {
	if (bin[index] == 0) {
		if (root->left == NULL) {
			root->left = new node();
		}
		if (index != 0) add(index - 1, root->left);
		else root->left->stop = 1;
	} else {
		if (root->right == NULL) {
			root->right = new node();
		}
		if (index != 0) add(index - 1, root->right);
		else root->right->stop = 1;
	}
}

inline long long query(int index, node *root) {
	if (index == -1) return 0LL;
	long long ret = 0;
	if (bin[index] == 0) { 
		if (root->right != NULL){
			ret = query(index - 1, root->right);
			ret += (long long)(1) << (long long) index;
		} else {
			ret = query(index - 1, root->left);
		}
	} else {
		if (root->left != NULL) {
			ret = query(index - 1, root->left);
			ret += (long long)(1) << (long long) index;
		} else {
			ret = query(index - 1, root->right);
		}
	}
	return ret;
}

int main(void){
	cin >> n;
	root = new node();
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll mask = 0;
	for (int i = 0; i <= n; i++) {
		mask = mask ^ a[i];
		make_binary(mask);
		add(39, root);
	}
	mask = 0;
	ll ans = 0;
	for (int i = n + 1; i >= 1; i--){
		mask = mask ^ a[i];
		make_binary(mask);
		ll p = query(39, root);
		ans = max(ans, p);
	}
	cout << ans;
	return 0;
}
