
/* Given a Binary Search Tree and a target sum.
Check whether there's a pair of Nodes in the BST
with value summing up to the target sum.
*/


#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

Node* NewNode(int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node* insert(Node* root, int key) {
	if (root == NULL) {
		return NewNode(key);
	}
	if (key < root->data) {
		root->left = insert(root->left, key);
	}
	else {
		root->right = insert(root->right, key);
	}
	return root;
}


int inorder(struct Node *root, int target, unordered_set<int>& set) {
	if (root == nullptr) {
		return 0;
	}
	if (inorder(root->left, target, set)) {
		return 1;
	}
	if (set.find(target - root->data) != set.end()) {
		return 1;
	}
	else {
		set.insert(root->data);
	}
	return inorder(root->right, target, set);
}

int isPairPresent(struct Node *root, int target) {
	unordered_set<int> st;
	return inorder(root, target, st);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Node* root = NULL;
	root = insert(root, 15);
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 8);
	root = insert(root, 12);
	root = insert(root, 16);
	root = insert(root, 25);
	root = insert(root, 10);

	int target = 33;
	cout << isPairPresent(root, target);
}