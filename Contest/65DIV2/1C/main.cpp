#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;


int n;
int m[100007];

int main(void){
	memset(m, 0, sizeof m);
	while(~scanf("%d",&n)){
		for(int i = 0; i < n; i++){
			scanf("%d", &m[i]);
		}
		int x = n;
		bool flag = false;
		for(int i = 1; i <= n / 3; i++){
			if(n % i) continue;
			for(int j = 0; j < i; j++){
				bool mark = true;
				int k = j;
				while(k < n + i){
					int x = k % n;
					if(!m[x]){
						mark = false;
						break;
					}
					k += i;
				}
				if(mark){
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		if(flag) cout << "YES";
		else cout << "NO";
	}

	return 0;
}
