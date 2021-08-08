//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=48
#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
using namespace std;

string sExpression;

bool numberCheck(char value) {
    return isdigit(value) || value == '-';
}

int getInterger(int it) {
    string temp = "";
    while(numberCheck(sExpression[it])) {
        temp += sExpression[it];
        it++;
    }

    return stoi(temp);
}

int leftChild(int it) {
    while (numberCheck(sExpression[it])) {
        it++;
    }

    if (!numberCheck(sExpression[it + 1])) {
        return -1;
    }

    return it + 1;
}

int rightChild(int it) {
    while(numberCheck(sExpression[it])) {
        it++;
    }

    int nBrackets = 1;
    it++;

    while(nBrackets > 0) {
        if (sExpression[it] == '(') {
            nBrackets++;
        } else if(sExpression[it] == ')') {
            nBrackets--;
        }
        it++;
    }

    if (!numberCheck(sExpression[it + 1])) {
        return -1;
    }

    return it + 1;
}

bool check(int it, int target, int current) {
    if (numberCheck(sExpression[it])) {
        current += getInterger(it);
    } else {
        return false;
    }

    int left = leftChild(it);
    int right = rightChild(it);

    if (left == -1 && right == -1) {
        return target == current;
    }

    bool leftPath = false, rightPath = false;
    if (left != -1) {
        leftPath = check(left, target, current);
    } 

    if (right != -1) {
        rightPath = check(right, target, current);
    }

    return leftPath || rightPath;

}

void solve() {
   int sum;
   while (cin >> sum) {
       sExpression = "";
       int nBracker = 0;
       string temp;
       while(cin >> temp) {
           for (int i = 0; i < temp.size(); i++) {
               if (temp[i] == '(') {
                   nBracker++;
               } else if (temp[i] == ')') {
                   nBracker--;
               }
            }
            sExpression += temp;
            if (nBracker == 0) {
                break;
            }
       }
       if (check(1, sum, 0)) {
           cout << "yes" << endl;
       } else {
           cout << "no" << endl;
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


