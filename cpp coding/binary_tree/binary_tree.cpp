#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    int level;
    int hd;
};

struct node *makenode(int x) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void createtree(struct node **root) {
    struct node *p;
    int x, choice;
    if ((*root) == nullptr) {
        cout << "Enter the data of the root node: ";
        cin >> x;
        (*root) = makenode(x);
    }

    cout << "Does the left of" << (*root)->data << " exist? (1 for Yes, 0 for No): ";
    cin >> choice;
    if (choice == 1) {
        cout << "Enter the data of the left node: ";
        cin >> x;
        p = makenode(x);
        (*root)->left = p;
        createtree(&((*root)->left));
    }

    cout << "Does the right of" << (*root)->data << " exist? (1 for Yes, 0 for No): ";
    cin >> choice;
    if (choice == 1) {
        cout << "Enter the data of the right node: ";
        cin >> x;
        p = makenode(x);
        (*root)->right = p;
        createtree(&((*root)->right));
    }
}

void levelordertraversal(struct node *t) {
    queue<struct node *> Q;
    Q.push(t);
    while (Q.size() != 0) {
        struct node *x;
        x = Q.front();
        Q.pop();
        cout << x->data << " ";
        if (x->left != nullptr) {
            Q.push(x->left);
        }
        if (x->right != nullptr) {
            Q.push(x->right);
        }
    }
}

int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int heightoftree(struct node *t) {
    if (t == NULL) {
        return 0;
    } else {
        if (t->left == NULL && t->right == NULL) {
            return 0;
        } else {
            return 1 + max(heightoftree(t->left), heightoftree(t->right));
        }
    }
}

/*void levelordertraversal2(struct node *t) {
    queue<struct node *> Q;
    Q.push(t);
    int h = heightoftree(t);
    vector<int> HT[h + 1];
    HT[0].push_back(t->data);
    while (Q.size() != 0) {
        struct node *x;
        x = Q.front();
        Q.pop();
        cout << x->data << " ";
        if (x->left != nullptr) {
            Q.push(x->left);
            x->left->level = x->level + 1;
            int i = x->left->level;
            HT[i].push_back(x->left->data);
        }
        if (x->right != nullptr) {
            Q.push(x->right);
            x->right->level = x->level + 1;
            int i = x->right->level;
            HT[i].push_back(x->right->data);
        }
    }
    cout<<endl;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j < HT[i].size(); j++) {
            cout << HT[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl<< "zigzag" << endl;
    for (int i = 0; i <= h; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < HT[i].size(); j++) {
                cout << HT[i][j] << " ";
            }
        } else {
            for (int j = HT[i].size() - 1; j >= 0; j--) {
                cout << HT[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout<<endl<<"left"<<endl;
    for (int i = 0; i <= h; i++) {
        cout << HT[i][0] << " ";
        cout << endl;
    }
    cout<<endl<<"right"<<endl;
    for (int i = 0; i <= h; i++) {
        cout << HT[i][HT[i].size()-1] << " ";
        cout << endl;
    }
}*/
void levelordertraversal3(struct node *t) {
    queue<struct node *> Q;
    Q.push(t);
    int h = heightoftree(t);
    vector<int> HT[2*h + 1];
    t->hd=0;
    while (Q.size() != 0) {
        struct node *x;
        x = Q.front();
        Q.pop();
        cout << x->data << " ";
        if (x->left != nullptr) {
            Q.push(x->left);
            x->left->hd = x->hd-1;
            int i = x->left->hd;
            HT[i+h].push_back(x->left->data);
        }
        if (x->right != nullptr) {
            Q.push(x->right);
            x->right->hd = x->hd+1;
            int i = x->right->hd;
            HT[i+h].push_back(x->right->data);
        }
    }
    cout<<endl<<"top view"<<endl;
    for (int i = 0; i <= 2*h; i++) {
        if(HT[i].size()!=0){
            cout << HT[i][0] << " ";
            cout << endl;

        }
    }
    cout<<endl<<"bottom"<<endl;
    for (int i = 0; i <= 2*h; i++) {
        if((HT[i].size()) != 0){
            cout << HT[i][HT[i].size()-1] << " ";
            cout << endl;
        }
    }
    cout<<endl<<"vertical"<<endl;
    for (int i = 0; i <= 2*h; i++) {
        if(HT[i].size()!=0){
            for(int j=0;j<HT[i].size();j++){
                cout << HT[i][j] << " ";
            }
            cout << endl;

        }
    }
}


int main() {
    struct node *root = nullptr;
    createtree(&root);
    levelordertraversal(root);
    cout << endl;
    /*levelordertraversal2(root);*/

    levelordertraversal3(root);

    return 0;
}
