#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;

struct node{
    char ch;
    int freq;
    node *left,*right;
};

node *getnode(char ch,int freq,node *left,node *right){
    node *p =new node();
    p->ch=ch;
    p->freq=freq;
    p->left=left;
    p->right=right;

    return p;
}
struct comp{
    bool operator()(node *l,node *r){
        return l->freq>r->freq;
    }
};
//traverse the huffman tree and store huffman codes in amap
void encode(node *root,string str,unordered_map<char,string>&huffmanCode){
    if(root==nullptr){
        return;
    }
    if(!root->left && !root->right){
        huffmanCode[root->ch]=str;
    }
    encode(root->left,str +"0",huffmanCode);
    encode(root->right,str+"1",huffmanCode);
}
//traverse the huffman tree an decode the encoded string
void decode(node *root,int &top_index,string str){
    if(root==nullptr){
        return;
    }
    if(!root->left && !root->right){
        cout<<root->ch;
        return;
    }
    top_index++;
    if(str[top_index]=='0'){
        decode(root->left,top_index,str);
    }
    else{
        decode(root->right,top_index,str);
    }

}
//builds huffman tree and decode given input text
void buildhuffmantree(string text){
    //count frequrncy of appearance of each character and store it in a map
    unordered_map<char,int>freq;
    for(char ch:text){
        freq[ch]++;
    }
    //create a priority queue to store leaf nodes of huffman tree
    priority_queue<node*,vector<node*>,comp>pq;
    //create a leaf node for each character and add it to the priority queue
    for(auto pair:freq){
        pq.push(getnode(pair.first,pair.second,nullptr,nullptr));
    }
    //do till there is more than one node in the queue
    while(pq.size()!=1){
        //remove the two nodes of highest frequency
        //(lowest frequency) from the queue
        node *left=pq.top(); pq.pop();
        node *right =pq.top(); pq.pop();

        //create a new internal nodes with these two nodes as children with frequency equal to the sum
        //of the two nodes frequencies add the new node to the priority queue
        int sum=left->freq+right->freq;
        pq.push(getnode('\0',sum,left,right));
    }
    //root stores pointer to root of huffman tree
    node *root=pq.top();
    //traverse the huffman tree and store huffman codes in a map also prints them
    unordered_map<char,string>huffmanCode;
    encode(root,"",huffmanCode);

    cout<<"Huffman Codes are :\n"<<'\n';
    for(auto pair:huffmanCode){
        cout<<pair.first<<" "<<pair.second<<'\n';
    }
    cout<<"\n Original string was:\n"<<text<<'\n';
    //print encoded string
    string str="";
    for(char ch:text){
        str+=huffmanCode[ch];
    }
    cout<<"\n encoded string is:\n"<<str<<'\n';
    //traverse the huffman tree again and this time decode the encoded string
    int top_index=-1;
    cout<<"\n decoded string is:\n";
    while(top_index<(int)str.size()-2){
        decode(root,top_index,str);
    }




}
//huffman coding algorithm
int main(){
    string text="Huffman coding is a data compression algorithm";
    buildhuffmantree(text);
}