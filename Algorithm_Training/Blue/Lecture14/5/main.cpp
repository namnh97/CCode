//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3781
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int MAX = 26;
struct Node {
    Node* child[MAX];
    int countLeaf;
};
ll suffixCount = 0;
ll startWith[MAX];

Node* createNode() {
    Node *temp = new Node();
    for (int i = 0; i < MAX; i++) {
        temp->child[i] = NULL;
    }
    temp->countLeaf = 0;
    return temp;
}

void addWord(Node* root, string s) {
    int index;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++) { 
        index = s[i] - 'a';
        if (temp->child[index] == NULL) {
            temp->child[index] = createNode();
        }
        temp = temp->child[index];
    }
    temp->countLeaf++;
}

void clearTrie(Node* root) {
    for (int i = 0; i < MAX; i++) {
        if (root->child[i] == NULL) {
            continue;
        }
        clearTrie(root->child[i]);
        delete root->child[i];
    }
}

void suffixTravel(Node *root, int level) {
    suffixCount++;
    for (int i = 0; i < MAX; i++) {
        if (root->child[i] == NULL) continue;
        if (level > 0) {
            startWith[i]++;
        }
        suffixTravel(root->child[i], level + 1);
    }
}

ll prefixTravel(Node *root, int level) {
    ll result = 0;
    if (level > 0) result += suffixCount;
    for (int i = 0; i < MAX; i++) {
        if (root->child[i] == NULL) continue;
        if (level > 0) {
            result -= startWith[i];
        }
        result += prefixTravel(root->child[i], level + 1);
    }
    return result;
}

void solve() {
    int p, s;
    while (cin >> p >> s && p != 0 && s != 0) {
        for (int i = 0; i < MAX; i++) {
            startWith[i] = 0;
        }
        suffixCount = 0;
        Node *suffixTrie = createNode();
        Node *prefixTrie = createNode();
        for (int i = 0; i < p; i++) {
            string por; cin >> por;
            addWord(prefixTrie, por);
        }
        for (int i = 0; i < s; i++) {
            string spa; cin >> spa;
            reverse(spa.begin(), spa.end());
            addWord(suffixTrie, spa);
        }
        suffixTravel(suffixTrie, 0);
        suffixCount--;
        cout << prefixTravel(prefixTrie, 0) << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}