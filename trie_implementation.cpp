#include<iostream>
#include<unordered_map>
using namespace std;
#define hashmap unordered_map<char , node*>
class node{
public:
      char data;
      bool isterminal;
      hashmap h;
      node(char d){
        data = d;
        isterminal = false;
      }
};
class trie{
    node* root;
    public:
    trie(){
        root = new node('\0');
    }
    void addWord(string str){
        node* temp = root;
        for(int i=0 ; i<str.size() ; i++){
            char ch = str[i];
            if(temp->h.count(ch) == 0){
                node* child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            }else{
                temp = temp->h[ch];
            }
        }
        temp->isterminal = true;
    }
    bool searchWord(string str){
        node* temp = root;
        for(int i=0 ; i<str.size() ; i++){
            char ch = str[i];
            if(temp->h.count(ch)){
                temp = temp->h[ch];
            }else{
                return false;
            }
        }
        return temp->isterminal;
    }
};
int main(){
    trie t;
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        t.addWord(str);
    }
    int q;
    cin>>q;
    while(q--){
        string str;
        cin>>str;
        cout<<t.searchWord(str)<<endl;
    }
return 0;
}