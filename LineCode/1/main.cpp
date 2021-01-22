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

void solve() {
    map<string, string> dic;
    int n; cin >> n;
    cin.ignore(256, '\n');
    for (int i = 0; i < n; i++) {
        string in;
        getline(cin, in);
        int pos = in.find(":");
        string key = in.substr(0, pos);
        string value = in.substr(pos + 1, in.size());
        dic.insert(pair<string, string>(key, value));
    }
    string searchWord; cin >> searchWord;
    map<string, string>::iterator it = dic.find(searchWord);
    if (it == dic.end()) {
        cout << "no data" << endl;
    } else {
        int cnt = 0;
        while (it != dic.end() && cnt < 5) {
            cout << it->first << ":" << it->second << endl;
            it++;
            cnt++;
        }
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


