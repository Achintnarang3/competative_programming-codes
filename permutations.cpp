#include <iostream>
using namespace std;
void permute(char *inp , int i){
    //base case
    if(inp[i] == '\0'){
        cout<<inp<<" , ";
        return;
    }
    //recursive case
    for(int j=i ; inp[j]!='\0'; j++){
        swap(inp[i] , inp[j]);
        permute(inp , i+1);
        //backtracking - to restore the original string
        swap(inp[i] , inp[j]);
    }
}
int main() {
    char inp[100];
    cin>>inp;
    permute(inp , 0);
    return 0;
}
