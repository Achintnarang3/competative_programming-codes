#include<iostream>
using namespace std;
void subsequences(char *ip , char *op , int i , int j){
    //base case
    if(ip[i] == '\0'){
        op[j] = '\0';
        cout<<op<<" , ";
        return;
    }
    //recursive case
    //include the character
    op[j] = ip[i];
    subsequences(ip , op , i+1 , j+1);
    //exclude the character
    subsequences(ip , op , i+1 , j);
}
int main(){
    char ip[100];
    char op[100];
    cin>>ip;
    subsequences(ip , op , 0 , 0);
    return 0;
}