//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/
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
    Node *child[MAX];
    int countWord;
    int max;
};

Node *createNode() {
    Node *node = new Node();
    for (int i = 0; i < MAX; i++) {
        node->child[i] = NULL;

    }
    node->countWord = 0;
    node->max = 0;
    return node;
}

void addWord(Node *root, string s, int len) {
    char ch;
    Node *tmp = root;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i] - 'a';
        if (tmp->child[ch] == NULL) {
            tmp->child[ch] = createNode();
        }
        tmp->max = max(tmp->max, len);
        tmp = tmp->child[ch];
    }
    tmp->countWord++;
}

int searchWord(Node *root, string s, int len) {
    int ch;
    Node *temp = root;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL) {
            return -1;
        }
        temp = temp->child[ch];
    }
    return temp->max;
}


int n, q;
void solve() {
    cin >> n >> q;
    Node *root = createNode();
    for (int i = 0; i < n; i++) {
        string word; int len;
        cin >> word >> len;
        addWord(root, word, len);
    }
    for (int i = 0; i < q; i++) {
        string search;
        cin >> search;
        cout << searchWord(root, search, search.size()) << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


