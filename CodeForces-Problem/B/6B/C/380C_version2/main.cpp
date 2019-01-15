#include<bits/stdc++.h>
#define int64 long long 

using namespace std;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>


void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

typedef pair<int, int>  pii;
typedef pair<int , pii> node;
typedef vector<int> vi;

struct SegmentTree{
	int n; string s;
	vi t, o, c;
	int l, r;
	SegmentTree(int _n, string _s){
		this->n = _n;
		this->s = _s;
		t = vi(n * 2, 0);
		o = vi(n * 2, 0);
		c = vi(n * 2, 0);
		l = 0;
		r = n - 1;
	}

	void build(int id, int  l, int r){
		if(r - l < 2){
			if(s[l] == '('){
				o[id] = 1;
			}else{
				c[id] = 1;
			}
		}
		int mid = (l + r) / 2;
		build(2 * id, l, mid);
		build(2 * id + 1, mid, r);
		int tmp = min(o[2 * id], c[2 * id + 1]);
		t[id] = t[2 * id] + t[2 * id + 1] + tmp;
		o[id] = o[2 * id] + o[2 * id + 1] - tmp;
		c[id] = c[2 * id] + c[2 * id + 1] - tmp;	
	}

	node segment(int x, int y, int id, int l, int r){
		if(l >= y || x >= r) return node(0, pii(0, 0));
		if(x <= l && y >= r){
			return node(t[id], pii(o[id], c[id]));
		}
		int mid = (l + r) / 2;
		node a = segment(x, y, 2 * id, l, mid);
		node b = segment(x, y, 2 * id + 1, mid, r);
		int T, tmp, O, C;
		tmp = min(a.second.first, b.second.second);
		T = a.first + b.first + tmp;
		O = a.second.first + b.second.first - tmp;
		C = a.second.second + b.second.second - tmp;
		
		return node(T, pii(O, C));
	}
};

int main(void){
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	string s; cin >> s;
	int n = s.length();
	SegmentTree ST(n, s);
	ST.build(1, 0, n);

	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		l--; r--;
		node result = ST.segment(l, r, 1, 0, n-1);
		cout << result.first << endl;
	}
	


	return 0;
}