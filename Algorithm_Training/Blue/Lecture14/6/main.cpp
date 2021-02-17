//https://www.hackerrank.com/challenges/no-prefix-set/problem
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 26;
struct Node {
    Node *child[MAX];
    int countWord;
};

Node* createNode() {
    Node *temp = new Node();
    for (int i = 0; i < MAX; i++) {
        temp->child[i] = NULL;
    }
    temp->countWord = 0;
    return temp;
}

bool isWord(Node *root) {
    return root->countWord > 0;
}

bool isEmpty(Node *root) {
    for (int i = 0; i < MAX; i++) {
        if (root->child[i] != NULL) {
            return false;
        }
    }
    return true;
}

bool addWord(Node *root, string s) {
    bool res = true;
    int index;
    Node *temp = root;
    for (int i = 0; i < s.size(); i++) {
        index = s[i] - 'a';
        if (temp->child[index] == NULL) {
            temp->child[index] = createNode();
        }
        temp = temp->child[index];
        if (isWord(temp)) {
            res = false;
        }
    }
    temp->countWord++;
    if (!isEmpty(temp)) {
        res = false;
    }
    return res;
}

void solve() {
    int t; cin >> t;
    string res = "";
    Node *root = createNode();
    bool first = true;
    while (t--) {
        string in; cin >> in;
        bool check = addWord(root, in);
        if (check == false && first) {
            res = in;
            first = false;
        }
    }
    if (res == "") {
        cout << "GOOD SET" << endl;
    } else {
        cout << "BAD SET" << endl;
        cout << res << endl;
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}