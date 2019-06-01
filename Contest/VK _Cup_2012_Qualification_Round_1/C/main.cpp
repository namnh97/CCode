#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

int main(void){
	int n; cin >> n;
	string com, par;
	vector<string> pat;
	while (n--){
		cin >> com;
		if (com == "pwd"){
			cout << "/";
			for (int i = 0; i < pat.size(); i++){
				cout << pat[i] << "/";
			}
			cout << endl;
		} else { 
			cin >> par;
			int pos = 0;
			if (par[0] == '/'){
				pat.clear();
				pos = 1;
			}
			while (true){
				size_t nxt_pos = par.find('/', pos);
				if (nxt_pos != string::npos){
					string dir = par.substr(pos, nxt_pos - pos);
					if (dir != ".."){
						pat.push_back(dir);
					} else {
						if (!pat.empty()){
							pat.pop_back();
						}
					}
					pos = nxt_pos + 1;
				} else {
					string dir = par.substr(pos, string::npos);
					if (dir != ".."){
						pat.push_back(dir);
					} else{
						if(!pat.empty()){
							pat.pop_back();
						}
					}
					break;
				}
			}
		}
	}
	return 0;
}
