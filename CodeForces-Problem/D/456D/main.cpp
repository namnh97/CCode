#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int maxn = 1e5;

int n, k, root, top, q[maxn][26];
char x[maxn];

void insert(){
 	int len = strlen(x);
 	int now = root;
 	for(int i=0; i<len; i++){
 	 	int temp = x[i] - 'a';
 	 	if(!q[now][temp]) q[now][temp] = ++top;
 	 	now = q[now][temp];
 	}
}

int dfs(int now){
	int flag = 1, ans;
	for(int i=0; i<26; i++){
	 	if(q[now][i]){
	 	 	flag = 0;
	 	 	ans = dfs(q[now][i]) ^ 3;
	 	 	cout << "now : " << now << "=== ans: " << ans << endl;
	 	}
	}
	if(flag) ans = 1;
	return ans;
}


int main(void){
	cin >> n >> k;
	while(n--){
		cin >> x;
		insert();
	}
	int ans = dfs(root);
	if(ans == 3 || ans == 2  && k && 1) cout << "First" << endl;
	else cout << "Second" << endl;                           
 	return 0;
}