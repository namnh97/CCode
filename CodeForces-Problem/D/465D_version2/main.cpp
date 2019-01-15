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

const int M = 1e5 + 10;

struct TnT{
  	TnT *next[27];
  	int vis;
  	TnT():vis(0){
  	 	memset(next, 0, sizeof next);
  	}
};

void build(TnT * root, char s[]){
 	int len = strlen(s);
 	TnT *p = root;
	for(int i=0; i<len; i++){
	 	int id = s[i] - 'a';
	 	if(p->next[id] == null){
	 	 	p->next[id] = new TnT();
	 	}
	 	p = p->next[id];
	 	p->vis++;
	}
}

void de(TnT *root){
 	if(root == null) return;
 	for(int i=0; i<26; i++){
 	 	de(root->next[i]);
 	}
 	delete root;
}

void find(TnT *root, int &x, int &y){
 	TnT *p = root;
 	x = 0, y = 0;
 	int u, v;
 	bool flag = true;
 	for(int i=0; i<26; i++){
 	 	if(p->next[i]){
 	 	 	flag = false;
 	 	 	find(root->next[i], u, v);
 	 	 	if(!u) x = 1;
 	 	 	if(!v) y = 1;
 	 	}
 	}
 	if(flag) x = 0,  y = 1;
}



int main(void){
 	return 0;
}