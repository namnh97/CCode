#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

bool comp(ll a, ll b, ll c, ll d) {
    ll first = a * d;
    ll second = b * c;
    return first < second;
}

void check(vector<ll> &a, vector<ll> &indices, vector<ll> &ans, vector<ll> &minn) {
    ll num = abs( (a[indices[0]] * a[indices[3]]) - (a[indices[1]] * a[indices[2]]) );
    ll denom = a[indices[1]] * a[indices[3]];

    if (comp(num, denom, minn[0], minn[1])) {
        minn[0] = num;
        minn[1] = denom;
        for (int i = 0; i < 4; i++) {
            ans[i] = indices[i];
        }
    }
}

void permutation(vector<ll> &a, int index, vector<ll> &visited, vector<ll> &indices, vector<ll> &ans, vector<ll> &minn) {
    for (int i = 0; i < 5; i++) {
        if (visited[i] ==  false) {
            visited[i] = true;
            indices[index] = i;
            if (index == 3) {
                check(a, indices, ans, minn);
            } else {
                permutation(a, index + 1, visited, indices, ans, minn);
            }
            visited[i] = false;
        }
    }
}

void solve() {
    vector<ll> a(5);
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }

    vector<ll> visited(5, false);
    vector<ll> indices(5);
    vector<ll> ans(4, 0);

    for (int i = 0; i < 5; i++) {
        indices[i] = i;
    }

    vector<ll> minn(2); 
    minn[0] = INT_MAX; minn[1] = 1;

    permutation(a, 0, visited, indices, ans, minn);

    for (int i = 0; i < 4; i++) {
        cout << ans[i] << " ";
    }
}


int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


