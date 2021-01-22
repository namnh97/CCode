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

Node *newNode() {
    Node *temp = new Node();
    for (int i = 0; i < MAX; i++) {
        temp->child[i] = NULL;
    }
    temp->countWord = 0;
    return temp;
}

bool isWord(Node* node) {
    return (node->countWord != 0);
}

bool isEmpty(Node *node) {
    for (int i = 0; i < MAX; i++) {
        if (node->child[i] != NULL) {
            return false;
        }
    }
    return true;
}
bool addWord(Node *root, string s) {
    int ch;
    Node *temp = root;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i] - '0';
        if (temp->child[ch] == NULL) {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
        if (isWord(temp)) {
            return false;
        }
    }
    temp->countWord++;
    if (!isEmpty(temp)) {
        return false;
    }
    return true;
}



void solve() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string number;
        bool res;
        Node *root = new Node();
        int flag = true;
        for (int i = 0; i < n; i++) {
            cin >> number;
            res = addWord(root, number);
            if (res == false) {
                flag = false;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}
