#include <iostream>

using namespace std;

struct binary_tree{
    int data;
    binary_tree* left;
    binary_tree* right;
};

class bst{
    binary_tree *root;
public:
    bst()
    {
        root = NULL;
    }
    bool isempty(root)
    {
        return (root==NULL);
    }
    void insert_node(int item);
    void print_tree();
    void print_binaryTree(binary_tree *);
};
void bst::insert_node(int item)
{
    struct binary_tree *new_node = new binary_tree;
    struct binary_tree *parent;
    parent = NULL;
    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;
    if(isempty())
    {
        root = new_node;
    }
    else
    {
        binary_tree *ptr;
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


































