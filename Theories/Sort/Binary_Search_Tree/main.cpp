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
struct Node {
	int key;
	Node *left;
	Node *right;
};

//O(1)
Node *createNode(int x) {
	Node *newNode = new Node;
	newNode->key = x;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//THe worst case is O(n)
Node* insertNode(Node *root, int x) {
	if (root == NULL) {
		return createNode(x);
	}
	if (x < root->key) {
		root->left = insertNode(root->left, x);
	} else if (x > root->key) {
		root->right = insertNode(root->right, x);
	} 
	return root;
}

//O(N*h)
void createTree(Node *&root, int a[], int n) {
	for (int i = 0; i < n; i++) {
		root = insertNode(root, a[i]);
	}
}

// O(h)
Node *searchNode(Node *root, int x) {
	if (root == NULL || root->key == x) {
		return root;	
	}
	if (root->key < x) {
		return searchNode(root->right, x);
	}
	return searchNode(root->left, x);
}

//The worst case is (O(n))
Node *deleteNode(Node *&root, int x) {
	if (root == NULL) {
		return root;
	}
	if (x < root->key) {
		root->left = deleteNode(root->left, x);
	} else if (x > root->key) {
		root->right = deleteNode(root->right, x);
	} else {
		if (root->left == NULL) {
			Node *temp = root->right;
			delete root;
			return temp;
		} else if (root->right == NULL) {
			Node *temp = root->left;
			delete root;
			return temp;
		}
		Node *temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

Node* minValueNode(Node* node) {
	Node* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

void traversalTree(Node *root) {
	if (root != NULL) {
		traversalTree(root->left);
		cout << root->key << " ";
		traversalTree(root->right);
	}
}

int size(Node* node) {
	if (node == NULL) return 0;
	return  (size(node->left) + 1 + size(node->right));
}

void deleteTree(Node *root) {
	if (root == NULL) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

int main(int argc, char** argv){
	#ifndef ONLINE_JUDGE
	freopen(argv[1], "r", stdin);
	#endif
	solve();
	return 0;
}



