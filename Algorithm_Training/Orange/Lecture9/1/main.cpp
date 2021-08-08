#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

int sumDigit(int number) {
    int result = 0;
    while (number != 0) {
        result += number % 10;
        number = number / 10;
    }
    return result;
}

int getHash(int number) {
    return number ^ sumDigit(number);
}

void solve() {
    int n; cin >> n;
    unordered_map<int, int> mp;
    int maxHashedValue = INT_MIN;

    for (int i = 0; i < n; i++) {
        int number; cin >> number;
        int hashedValue = getHash(number);
        maxHashedValue = max(maxHashedValue, hashedValue);
        mp[hashedValue]++;
    }

    int nCollision = 0;
    int maxFrequency = INT_MIN;
    for (auto &it : mp) {
        nCollision += it.second - 1;
        maxFrequency = max(maxFrequency, it.second);
    }

    int minHashedValue = INT_MAX;
    if (mp.size() == n) {
        cout << maxHashedValue;
    } else {
        for (auto &it : mp) {
            if (it.second == maxFrequency) {
                minHashedValue = min(minHashedValue, it.first);
            }
        }
        cout << minHashedValue;
    }
    cout << " " << nCollision;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


