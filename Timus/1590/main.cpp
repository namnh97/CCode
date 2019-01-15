#include<bits\stdc++.h>
#define int64 long long

using namespace std;

void preprocess(string &s, vector<int> &p){
    int n = s.length();
    p.resize(n, 0);
    for(int i=1; i<n; i++){
        int j = p[i-1];
        while(j > 0 && s[i] != s[j]) j = p[j-1];
        if(s[i] == s[j]) ++j;
        p[i] = j;
    }
}

void sol(){
    string str, s;
    cin >> str;
    int ans = 0;
    vector<int> p;
    for(int i=1; i<=str.size(); i++){
        s = str.substr(0, i);
        reverse(s.begin(), s.end());
        preprocess(s, p);
        ans += (int)s.size() - (*max_element(p.begin(), p.end()));
    }
    cout << ans;
}

int main()
{
    #ifndef ONELINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONELINE_JUDGE
    sol();
    return 0;
}
