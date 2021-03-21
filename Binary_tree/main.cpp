#include<bits/stdc++.h>
using namespace std;

struct Binary_tree
{
    int data;
    Binary_tree *left, *right;
};
class bst
{
    Binary_tree *root;
public:
    bst()
    {
        root = NULL;
    }
    bool isempty()
    {
        return (root==NULL);
    }
    void insert_item(int item);
    void display_tree();
    void printBinaryTree(Binary_tree*);

};
void bst::insert_item(int item)
{
    Binary_tree *new_node = new Binary_tree;
    Binary_tree *parent;
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    parent = NULL;
    if(isempty())
    {
        root = new_node;
    }
    else{
        Binary_tree *ptr;
        ptr = root;
        while(ptr!=NULL)
        {
            parent = ptr;
            if(item>ptr->data)
            {
                ptr = ptr->right;
            }
            else{
                ptr = ptr->left;
            }
        }
        if(item<parent->data)
        {
            parent->left = new_node;
        }
        else{
            parent->right = new_node;
        }
    }
}
void bst::display_tree()
{
    printBinaryTree(root);
}
void bst::printBinaryTree(Binary_tree *ptr)
{
    if(ptr!=NULL)
    {
        printBinaryTree(ptr->left);
        cout<<" "<<ptr->data;
        printBinaryTree(ptr->right);
    }
}
int main()
{
    bst b;
    b.insert_item(2);
    b.insert_item(24);
    b.insert_item(9);
    b.insert_item(10);
    b.insert_item(1);
    b.insert_item(15);
    b.insert_item(100);
    cout<<"the binary tree created....\n";
    b.display_tree();
}
