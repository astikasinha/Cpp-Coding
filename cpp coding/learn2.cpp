#include<iostream>
#include<string>
using namespace std;
int main(){
    string firststring="my first string";
    cout<<firststring<<endl;

    string name;
    cout<<"enter your name";
    cin>>name;
    cout<<name<<endl;

    int n=name.length();
    cout<<n;

    char firstchar=name[0];
    char secondchar=name.at(1);
    cout<<firstchar<<secondchar<<endl;

    string firstname="astika";
    string lastname="sinha";
    string fullname=firstname +" "+lastname;
    cout<<fullname<<endl;


    string base="money";
    cout<<base<<endl;
    base.append(" trail");
    cout<<base<<endl;

    string str1="best";
    string str2="least";
    if(str1==str2){
        cout<<"strings are equal"<<endl;
    }
    else{
        cout<<"strings are nott equal"<<endl;
    }


    int result=str1.compare(str2);
    if(result==0){
        cout<<"strings are equal"<<endl;
    }
    else if(result<0){
        cout<<"str1 comes before str2"<<endl;    
    }
    else{
        cout<<"str2 comes before str1"<<endl;
    }


    string text="since inception";
    cout<<text<<endl;
    string sub=text.substr(6,5);
    cout<<sub<<endl;


    string searchin="c++ programming";
    int position=searchin.find("programming");
    cout<<"found at position"<<position<<endl;

    string modified="i like pretty pets";
    modified.replace(2,4," redish");
    cout<<modified<<endl;
    modified.insert(6," blue");
    cout<<modified<<endl;
    modified.erase(6,4);
    cout<<modified<<endl;



    int k=100;
    string str;
    str=to_string(k);
    cout<<str<<endl;
}