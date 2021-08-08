//https://www.hackerrank.com/challenges/contacts/problem
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 26;
struct Node {
    Node *child[MAX];
    int cnt;
};

Node *createNode() {
    Node *temp = new Node();
    temp->cnt = 0;
    for (int i = 0; i < MAX; i++) {
        temp->child[i] = NULL;
    }
    return temp;
}


void addWord(Node *node, string s) {
    int index;
    Node *temp = node;
    for (int i = 0; i < s.size(); i++) {
        index = s[i] - 'a';
        if (temp->child[index] == NULL) {
            temp->child[index] = createNode();
        }
        temp = temp->child[index];
        temp->cnt++;
    }
}

int findWord(Node *node, string s) {
    int index, res;
    Node *temp = node;
    for (int i = 0; i < s.size(); i++) {
        index = s[i] - 'a';
        if (temp->child[index] == NULL) {
            return 0;
        }
        temp = temp->child[index];
        res = temp->cnt;
    }
    return res;
}


void solve() {
    int t; cin >> t;
    Node *root = createNode();
    while (t--) {
        string op, value;
        cin >> op >> value;
        if (op == "add") {
            addWord(root, value);
        } else {
            int res = findWord(root, value);
            cout << res << endl;
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


