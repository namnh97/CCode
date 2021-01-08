#include<bits/stdc++.h>
#define ll long long 
#define fori(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define ford(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define pb push_back
#define mp make_pair
using namespace std;

#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
void debugOut() {
    cerr << endl;
}


const int MAX = 26;
struct Node {
    Node* child[MAX];
    int countWord; 
};


struct Node* newNode() {
    Node* node = new Node();
    node->countWord = 0;
    for (int i = 0; i < MAX; i++) {
        node->child[i] = NULL;
    }
    return node;
}

void addWord(Node *root, string s) {
    int ch; 
    Node *temp = root;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL) {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
    }
    temp->countWord++;
}

bool findWord(Node* root, string s) {
    int ch;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL) {
            return false;
        }
        temp = temp->child[ch];
    }
    return temp->countWord > 0;
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

bool removeWord(Node* root, string s, int level, int len) {
    if (!root) {
        return false;
    }
    int ch = s[level] - 'a';
    if (level == len) {
        if (root->countWord > 0) {
            root->countWord--;
            return true;
        }
        return false;
    }
    int flag = removeWord(root->child[ch], s, level + 1, len);
    if (flag && !isWord(root->child[ch]) && isEmpty(root->child[ch])) {
        delete root->child[ch];
        root->child[ch] = NULL;
    }
    return flag;
}


void printWord(Node* root, string s) {
    if (isWord(root)) {
        cout << s << endl;
    }
    for (int i = 0; i < MAX; i++) {
        if (root->child[i]) {
            printWord(root->child[i], s + (char)('a' + i));
        }
    }
}

void solve() {
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}



