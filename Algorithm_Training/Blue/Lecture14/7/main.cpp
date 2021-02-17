//https://www.codechef.com/problems/BANKPASS
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
    temp->countWord = 0;
    for (int i = 0; i < MAX; i++) {
        temp->child[i] = NULL;
    }
    return temp;
}

bool isWord(Node *root) {
    return root->countWord > 0;
}

bool isEmpty(Node *root) {
    for (int i = 0; i < MAX; i++) {
        if (root->child[i] != NULL) return false;
    }
    return true;
}

bool addWord(Node *root, string s) {
    int index;
    Node *temp = root;
    for (int i = 0; i < s.size(); i++) {
        index = s[i] - 'a';
        if (temp->child[index] == NULL) {
            temp->child[index] = createNode();
        }
        temp = temp->child[index];
        if (isWord(temp)) return false;
    }
    temp->countWord++;
    if (!isEmpty(temp)) return false;
    return true;
}

void solve() {
    int t; cin >> t;
    Node *root = createNode();
    while (t--) {
        string in; cin >> in;
        bool check = addWord(root, in);
        if (check == false) {
            cout << "vulnerable" << endl;
            return;
        }
    }
    cout << "non vulnerable" << endl;
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}