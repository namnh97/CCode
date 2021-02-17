//https://vjudge.net/problem/LightOJ-1224
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

vector<char> dna = {'A', 'C', 'G', 'T'};
int res = 0;

struct Node {
    Node *child[4];
    int cnt;
};

Node *createNode() {
    Node *temp = new Node();
    for (int i = 0; i < (int)dna.size(); i++) {
        temp->child[i] = NULL;
    }
    temp->cnt = 0;
    return temp;
}

void addWord(Node *root, string s) {
    int ch;
    Node *temp = root;
    for (int i = 0; i < (int)s.size(); i++) {
        ch = find(dna.begin(), dna.end(), s[i]) - dna.begin();
        if (temp->child[ch] == NULL) {
            temp->child[ch] = createNode();
        }
        temp = temp->child[ch];
        temp->cnt++;
        res = max(res, temp->cnt * (i + 1));
    }
}



void solve() {
    int testcases; cin >> testcases;
    for (int i = 1; i <= testcases; i++) {
        cout << "Case " << i << ": ";
        int n; cin >> n;
        res = 0;
        Node *root = createNode();
        while (n--) {
            string input; cin >> input;
            addWord(root, input);
        }
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
