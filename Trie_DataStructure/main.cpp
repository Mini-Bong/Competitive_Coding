#include<bits/stdc++.h>

using namespace std;

const int alphabetSize = 26;
// trie_Data structure
struct TrieNode{
    struct TrieNode* children[alphabetSize];
    bool isEndOfWord;
};
TrieNode *NewNode(void){
    TrieNode *new_node = new TrieNode;
    new_node->isEndOfWord = false;
    for(int i=0; i<alphabetSize; i++){
        new_node->children[i] = NULL;
    }
    return new_node;
}
void insertNode(TrieNode *root, string key){
    TrieNode *new_node = root;
    for(int i=0; i<key.size(); i++)
    {
        int index = key[i] - 'a';
        if(!new_node->children[index]){
            new_node->children[index] = NewNode();
        }
        new_node = new_node->children[index];
    }
    new_node->isEndOfWord = true;
}
// Return true if key present in trie else false
bool searchWord(TrieNode *root, string key){
    TrieNode *node = root;
    for(int i=0; i<key.size(); i++)
    {
        int index = key[i] - 'a';
        if(!node->children[index]){
            return false;
        }
        node = node->children[index];
    }
    return (node!=NULL && node->isEndOfWord);
}
int main()
{
    string key[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
    int n = sizeof(key)/sizeof(key[0]);
    TrieNode *root = NewNode();
    for(int i=0; i<n; i++)
    {
        insertNode(root, key[i]);
    }
    searchWord(root, "ther")?cout<<"Yes\n":cout<<"No\n";
    return 0;
}
