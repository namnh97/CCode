#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };
#define MAX 1000100

char s[MAX];
int delay[MAX];
int prev[MAX];
int nmale[MAX];
int n;

void maximize(int &x, const int &y){
	if(x < y) x = y;
}

void init(void){
	scanf("%d", &n);
	scanf("%s", &s[1]);
	prev[1] = 0;
	nmale[1] = 0;
	for(int i = 2; i <= n; i++){
		if(s[i - 1] == '<') prev[i] = i - 1;
		else prev[i] = prev[i - 1];
		nmale[i] = nmale[i - 1] +  (s[i - 1] == '>');
	}
}

void count(void){
	for(int i = 1; i <= n; i++){
		if(s[i] == '<'){
			if(nmale[i] == 0) delay[i] = 0;
			else{
				if(prev[i] == 0) delay[i] = 0;
				else{
					delay[i] = delay[prev[i]] + 1 - (i - prev[i] + 1);
				}
				if(delay[i] < 0) delay[i] = 0;
			}
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '<' && nmale[i] > 0){
			maximize(res, delay[i] + nmale[i]);
		}
	}
	printf("%d", res);
}
int main(void){
	init();
	count();
	return 0;
}
