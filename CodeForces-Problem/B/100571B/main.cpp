#include<bits/stdc++.h>
#define int64 long long


using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5;

int64 a, b, n, q;
int64 f[MAXN];
int64 x[MAXN];
int64 s[MAXN];

void initial(){
    memset(s, 0, sizeof s);
    for(int64 i=3; i<=n; i++){
        f[i] = (a * f[i-2] + b * f[i-1]) % MOD;
    }
}

void sol(){
    cin >> n >> q;
    cin >> f[1] >> f[2];
    cin >> a >> b;
    for(int64 i=1; i<=n; i++){
        cin >> x[i];
    }
    initial();
    cout << endl;
    while(q--){
        int64 l, r;
        cin >> l >> r;
            (s[l] += f[1]) %= MOD;
            if( r - l >= 1 ) {
                (s[l + 1] += f[2]) %= MOD;
                s[l + 1] = (s[l + 1] - b * f[1]) % MOD;
                s[r + 1] = (s[r + 1] - f[r - l + 2]) % MOD;
                s[r + 2] = (s[r + 2] - a * f[r - l + 1]) % MOD;
            }
            else {
                s[r + 1] = (s[r + 1] - b * f[1]) % MOD;
                s[r + 2] = (s[r + 2] - a * f[1]) % MOD;
            }

    }
    for(int64 i=1; i<=n; i++){
        if( i>=2 ) (s[i] += a * s[i-2]) %= MOD;
        (s[i] += b * s[i-1]) %= MOD;
        (x[i] += s[i]) %= MOD;
    }
    for(int64 i=1; i<=n; i++){
        cout << x[i] << " ";
    }
}

int main()
{
    #ifndef ONELINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONELINE_JUDGE
    sol();
    return 0;
}
