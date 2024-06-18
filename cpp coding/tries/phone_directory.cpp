#include <iostream>
#include <vector>
#include <string>
#include <limits>
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

    trie() {
        root = new trienode('\0');
    }

    void insertutil(trienode* root, string word) {
        if (word.length() == 0) {
            root->isterminal = true;
            return;
        }
        int index = word[0] - 'a';
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

    void printsuggestions(trienode *curr, vector<string> &temp, string prefix) {
        if (curr->isterminal) {
            temp.push_back(prefix);
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            trienode *next = curr->children[ch - 'a'];
            if (next != NULL) {
                prefix.push_back(ch);
                printsuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getsuggestions(string str) {
        trienode *prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for (int i = 0; i < str.length(); i++) {
            char lastch = str[i];
            prefix.push_back(lastch);
            trienode *curr = prev->children[lastch - 'a'];

            if (curr == NULL) {
                break;
            }
            vector<string> temp;
            printsuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string &queryStr) {
    trie *t = new trie();
    for (string str : contactList) {
        t->insertword(str);
    }
    return t->getsuggestions(queryStr);
}
int main(){
    int numberOfContacts;
    cout << "Enter the number of contacts: ";
    cin >> numberOfContacts;

    // Initialize an empty vector to store the contacts
    vector<string> contactList;

    // Temporarily store each contact name
    string contactName;

    cout << "Enter the contact names:" << endl;
    // Ignore the newline character left in the input stream
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Loop to get contact names from the user
    for (int i = 0; i < numberOfContacts; i++) {
        getline(cin, contactName);
        contactList.push_back(contactName);
    }

    // Get the query string from the user
    string queryStr;
    cout << "Enter the query string: ";
    getline(cin, queryStr);
    vector<vector<string>> suggestions = phoneDirectory(contactList,queryStr);

    for (int i = 0; i<suggestions.size(); i++) {
        cout << "Suggestions for \"" << queryStr.substr(0, i + 1) << "\": ";
        for (string s : suggestions[i]) {
            cout << s << " ";
        }
        cout << endl;
    }
}