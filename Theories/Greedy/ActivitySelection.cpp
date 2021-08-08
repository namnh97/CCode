#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

struct Activity {
    int start;
    int finish;
};

vector<Activity> res;
vector<Activity> a;

bool activityCompare(const Activity &s1, const Activity &s2) {
    return s1.finish < s2.finish;
}

void activitySelection() {
    sort(a.begin(), a.end(), activityCompare);
    Activity choice;
    int i = 0;
    res.push_back(a[0]);
    for (int j = 1; j < a.size(); j++) {
        if (a[j].start >= a[i].finish) {
            res.push_back(a[j]);
            i = j;
        }
    }
}

void printActivities() {
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].start << " - " << res[i].finish << endl;
    }
}

void solve() {
    int n, s, f;
    cin >> n;
    Activity temp;
    for (int i = 0; i < n; i++) {
        cin >> s >> f;
        temp.start = s;
        temp.finish = f;
        a.push_back(temp);
    }
    activitySelection();
    printActivities();
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}