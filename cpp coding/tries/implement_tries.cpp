#include<iostream>
using namespace std;

class trienode {
public:
    char data;
    trienode* children[26];
    bool isterminal;

    trienode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isterminal = false;
    }
};

class trie {
public:
    trienode* root;

    trie() { // Constructor to initialize the trie with root node.
        root = new trienode('\0'); // Root node doesn't hold any character.
    }

    void insertutil(trienode* root, string word) {
        //baae case
        if (word.length() == 0) {
            root->isterminal = true;
            return;
        }
        int index = word[0] - 'A'; // Adjust according to case sensitivity.
        trienode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new trienode(word[0]);
            root->children[index] = child;
        }
        insertutil(child, word.substr(1));
    }

    void insertword(string word) {
        insertutil(root, word);
    }

    bool searchutil(trienode* root, string word) {
        if (word.length() == 0) {
            return root->isterminal;
        }
         int index=word[0]-'A';
        trienode *child;
        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }
        //recursion
        return searchutil(child,word.substr(1));
        //return searchutil(root->children[index], word.substr(1));
    }

    bool searchword(string word) {
        return searchutil(root, word);
    }
};

int main() {
    trie* t = new trie();
    t->insertword("ABCD"); // Make sure to use uppercase for consistency with the assumptions.
    cout << "Present or not: " << t->searchword("BCD") << endl; // This should print 1 (true) if the word is found.
}
