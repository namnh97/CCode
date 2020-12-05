#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }
#define x first
#define y second
using namespace std;

typedef vector<int> vi;
typedef vector< pair<int, int> > pii;

//380 Codeforces
//build segment tree


void build(int id = 1,int l = 0,int r = n){
    if(r - l < 2){
        if(s[l] == '(')
            o[id] = 1;
        else
            c[id] = 1;
        return ;
    }
    int mid = (l+r)/2;
    build(2 * id,l,mid);
    build(2 * id + 1,mid,r);
    int tmp = min(o[2 * id],c[2 * id + 1]);
    t[id] = t[2 * id] + t[2 * id + 1] + tmp;
    o[id] = o[2 * id] + o[2 * id + 1] - tmp;
    c[id] = c[2 * id] + c[2 * id + 1] - tmp;
}

//query segment tree

typedef pair<int,int>pii;
typedef pair<int,pii>   node;
node segment(int x,int y,int id = 1,int l = 0,int r = n){
    if(l >= y || x >= r)   return node(0,pii(0,0));
    if(x <= l && r <= y)
        return node(t[id],pii(o[id],c[id]));
    int mid = (l+r)/2;
    node a = segment(x,y,2 * id,l,mid), b = segment(x,y,2 * id + 1,mid,r);
    int T, temp, O, C;
    temp = min(a.y.x , b.y.y);
    T = a.x + b.x + temp;
    O = a.y.x + b.y.x - temp;
        C = a.y.y + b.y.y - temp;
    return node(T,pii(O,C));    
}

//method 2 to build segment tree
void build(int node, int left, int right) {
    if (left == right) {
        IT[node] = a[left];
        return;
    }
    int mid = (left + right) / 2;
    build(2 * node, left, mid);
    build(2 * node + 1, mid + 1, right);
    IT[node] = IT[2 * node] + IT[2 * node + 1];
}
int query(int node, int left, int right, int start, int end) {
    if (left <= end || right <= start) return;
    if (start <= left && right <= end) return IT[node];
    int mid = (left + right) >> 1;
    int leftValue = query(2 * node, left, mid, start, end);
    int rightValue = query(2 * node + 1, mid + 1, right, start, end);
    return leftValue + rightValue;
}
int main(void){
	return 0;
}