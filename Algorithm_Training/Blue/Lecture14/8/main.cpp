//https://codeforces.com/problemset/problem/37/C
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 2;
struct Node {
    Node *child[MAX];
    Node *pre;
    int isBlocked;
};

Node *newNode() {
    Node *temp = new Node();
    for (int i = 0; i < MAX; i++) {
        temp->child[i] = NULL;
    }
    temp->pre = NULL;
    temp->isBlocked = 0;
    return temp;
}

string ans[100001];
string s;
Node *root = newNode();

bool add(int l) {
    Node *temp = root;
    if (root->isBlocked == 1) return false;
    s = "";
    for (int i = 0; i < l; i++) {
        int checkL = -1;
        bool canMove = false;
        for (int j = MAX - 1; j >= 0; j--) {
            if (temp->child[j] != NULL) {
                if (temp->child[j]->isBlocked == 0) {
                    s = s + (char)('0' + j);
                    temp = temp->child[j];
                    canMove = true;
                    break;
                }
            }
            if (temp->child[j] == NULL) {
                checkL = j;
            }
        }
        if (!canMove) {
            if (checkL == -1) {
                return false;
            }
            else {
                s = s + (char)('0' + checkL);
                temp->child[checkL] = newNode();
                temp->child[checkL]->pre = temp;
                temp = temp->child[checkL];
            }
        }     
    }
    temp->isBlocked = 1;
    while (temp != NULL) {
        if (temp->child[0] != NULL && temp->child[1] != NULL) {
            if (temp->child[0]->isBlocked * temp->child[1]->isBlocked == 1) {
                temp->isBlocked = 1;
            }
        }
        temp = temp->pre;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    pair<int, int> a[10000];
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        a[i] = {l ,i};
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        int l = a[i].first;
        if (add(l) == false) {
            cout << "NO" << endl;
            return;
        } else {
            ans[a[i].second] = s;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}


int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}