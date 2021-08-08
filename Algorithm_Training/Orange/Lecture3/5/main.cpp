//https://codeforces.com/problemset/problem/476/B
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

int expected = 0;
int cases = 0, validCases = 0;
string s1, s2;

void find(int index, int val) {
    if (index == s2.size()) {
        if (val == expected) validCases++;
        cases++;
        return;
    }

    if (s2[index] != '+') find(index + 1, val - 1); // including '?' and '-'
    if (s2[index] != '-') find(index + 1, val + 1); // including '?' and '+'
}

void solve() {
    cin >> s1 >> s2;
    for (char &it : s1) {
        if (it == '+') expected++;
        else expected--;
    }
    find(0, 0);
    cout << fixed << setprecision(10) << (double) validCases / cases; 
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


