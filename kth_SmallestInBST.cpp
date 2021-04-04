#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* temp = root;
        stack<TreeNode*>s;
        s.push(root);
        vector<int> res;
        while(!s.empty()){
            temp = s.top();
            s.pop();
            if(temp->right!=nullptr)
                s.push(temp->right);
            if(temp->left!=nullptr){
                s.push(temp->left);
            }
            res.push_back(temp->val);
        }
        sort(res.begin(), res.end());
        return res[k-1];
    }
    /* using vector
    vector<int> res;
    
    void inorder(TreeNode* root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return res[k-1];
    }*/
    
};