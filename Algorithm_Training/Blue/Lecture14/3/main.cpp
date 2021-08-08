//https://lightoj.com/problem/consistency-checker
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 10;
struct Node {
    Node *child[MAX];
    int countWord;
};


Node *createNode() {
    Node *node = new Node();
    for (int i = 0; i < MAX; i++) {
        node->child[i] = NULL;
    }
    node->countWord = 0;
    return node;
}

bool isEmpty(Node *node) {
    for (int i = 0; i < MAX; i++) {
        if (node->child[i] != NULL) {
            return false;
        }
    }
    return true;
}


bool isWord(Node *node) {
    return node->countWord != 0;
}

bool addWord(Node *root, string s) {
    int ch;
    Node *temp = root;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i] - '0';
        if (temp->child[ch] == NULL) {
            temp->child[ch] = createNode();
        }
        temp = temp->child[ch];
        if (isWord(temp)) return false;
    }
    temp->countWord++;
    if (!isEmpty(temp)) return false;
    return true;
}

void solve() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int n; cin >> n;
        Node *node = createNode();
        bool flag = true;
        for (int j = 0; j < n; j++) {
            string number; cin >> number;
            bool res = addWord(node, number);
            if (res == false) {
                flag = false;
            }
        }
        cout << "Case " << i << ": ";
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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


