#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

int t, n;
char mc[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

void solve() {
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0;
        string str = "";
        while (n > 0) {
            int number = n % 10;
            sum += number;
            str += mc[number];
            n = n / 10;
        }
        reverse(str.begin(), str.end());
        int len = str.length();
        int num = 0;
        string temp = "";
        if (sum < len) {
            num = sum % len;
            for (int i = 0; i < num; i++) {
                temp += str[i];
            }
        } else {
            num = sum;
            while (num >= len) {
                temp += str;
                num -= len;

            }
            for (int i = 0; i < num; i++) {
                temp += str[i];
            }
        }
        string res = temp;
        reverse(temp.begin(), temp.end());
        bool flag = true;
        for (int i = 0; i < res.length(); i++) {
            if (temp[i] != res[i]) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}



