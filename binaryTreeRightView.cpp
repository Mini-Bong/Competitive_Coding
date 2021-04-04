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
    vector<int> rightSideView(TreeNode* root) {
        TreeNode *temp = root;
        queue<TreeNode*> q;
        vector<int> res;
        if(root==nullptr){
            return {};
        }
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                temp = q.front();
                q.pop();
                if(n==0){
                    res.push_back(temp->val);
                }
                if(temp->left!=nullptr){
                    q.push(temp->left);
                }
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }
            }
        }
        return res;
    }
};