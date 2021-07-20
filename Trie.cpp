#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    vector<TrieNode> children(26);
    bool endofWord;
    TrieNode(){
        endofWord=false;
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie();
    void insert(string);
    bool deletion(string);
    bool search(string);
    void printAll();
}
Trie::Trie(){
    root=new TrieNode();
}
void Trie::insert(string s){
    TrieNode* p=root;
    for(int i=0;i<s.length();i++){
        int ind=int(s[i]-'a');
        if(!p->children[ind]){
            p->children[ind]=new TrieNode();
        }
        p=p->children[ind];
    }
    p->endofWord=true;
}
bool Trie::search(string s){
    TrieNode* p=root;
    for(int i=0;i<s.length();i++){
        int ind=int(s[i]-'a');
        if(!p->children[ind]){
            return false;
        }
        p=p->children[ind];
    }
    return (p->endofWord&&p!=NULL);
}
bool Trie::deletion(string s){
    return true;
}
int main(){
    Trie t;
    while(1){
        int n;
        cout<<"SELECT THE OPERATIONS YOU WANT TO PERFORM \n1. Insert String\n2.Search for String \n3.Delete a String\n";
        cin>>n;
        switch(n){
            case 1:{
                string s;
                cout<<"ENTER THE STRING(WITHOUT SPACES)\n";
                cin>>s;
                t.insert(s);
                cout<<"String has been inserted\n";
                break;
            }
            case 2:{
                string s;
                cout<<"ENTER THE STRING(WITHOUT SPACES)\n";
                cin>>s;
                if(t.search(s)){
                    cout<<"String is present in Storage\n";
                }
                else{
                    cout<<"String absent\n";
                }
                break;
            }
            case 3:{
                string s;
                cout<<"ENTER THE STRING(WITHOUT SPACES)\n";
                cin>>s;
                if(t.deletion(s)){
                    cout<<"String has been deleted\n";
                }
                else{
                    cout<<"String absent\n";
                }
                break;
            }
            case 4:{
                cout<<"ALL PRESENT STRINGS(WITHOUT SPACES)\n";
                t.printAll();
                break;
            }
            default:{
                cout<<"Enter a valid operation\n";
            }
        }
        cout<<"Enter q for quit\n";
        char c;
        cin>>c;
        if(c=='q'){
            cout<<"Thanks for visiting\n";
            break;
        }
    }

}