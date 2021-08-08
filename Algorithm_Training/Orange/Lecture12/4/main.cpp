#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>

using namespace std;
struct People {
    int s, b;
    int id;

    bool operator < (const People other) const {
        if (this->s == other.s) {
            return this->b > other.b;
        }
        return this->s < other.s;
    }
};

int lowerBound(vector<People> &people, vector<int> &sub, int n, int x) {
    int left = 1;
    int right = n;
    int pos = right;
    while (left < right) {
        int mid = (left + right) >> 1;
        int index = sub[mid];
        if (people[index].b >= x) {
            pos = mid;
            right = mid;
        } else {
            left = mid - 1;
        }
    }
    return pos;
}

int LIS(vector<People> &people, vector<int> &res) {
    vector<int> increasingSub(people.size());
    vector<int> path(people.size(), -1);

    int length = 1;
    increasingSub[1] = 1;
    for (int i = 2; i < people.size(); i++) {
        if (people[i].b > people[increasingSub[length]].b) {
            length++;
            increasingSub[length] = i;
            path[i] = increasingSub[length - 1];
        } else {
            int pos = lowerBound(people, increasingSub, length, people[i].b);
            path[i] = increasingSub[pos - 1];
            increasingSub[pos] = i;
        }
    }

    int i = increasingSub[length];
    while (i > 0) {
        res.pb(people[i].id);
        i = path[i];
    }
    
    return length;
}

void solve() {
    int n; cin >> n;
    vector<People> people(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> people[i].s >> people[i].b;
        people[i].id = i;
    }
    sort(people.begin() + 1, people.end());
    vector<int> res;
    cout << LIS(people, res) << endl;
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
}

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}