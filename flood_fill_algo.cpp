#include<iostream>
using namespace std;
int R = 15;
int C = 30;
void print(char mat[][50]){
    for(int i=0 ; i<R ;i++){
        for(int j=0 ;j<C ;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
//west , north, east ,south
int dx[] = {0, -1 , 0 , 1 };
int dy[] = {-1 , 0 , 1 , 0};
// ch-> is the character to be replaced
// colour-> is the character to be added
void flood_fill(char mat[][50] , int i , int j , char ch , char colour ){
   //base case for matrix bounds
   if(i<0 || j<0 || i>=R || j>=C){
       return ;
   }
   //figure boundary condition
   if(mat[i][j]!=ch){
       return ;
   }
   //recursive
   mat[i][j] = colour;
   for(int k=0 ; k<4 ; k++){
       flood_fill(mat , i+dx[k] ,j+dy[k] , ch , colour);
   }
}
int main(){
    cin>>R>>C;
    char input[50][50];
    for(int i=0 ; i<R ;i++){
        for(int j=0 ;j<C ; j++){
            cin>>input[i][j];
        }
    }
    print(input);
    cout<<endl;
    flood_fill(input , 5 , 7 , '$' ,'r');
    print(input);

}
/* INPUT 
# # # # # # # # # # # # # # 
# $ $ $ $ $ $ $ $ $ $ $ $ # 
# $ $ $ $ $ $ $ $ $ $ $ $ # 
# $ $ $ $ $ $ $ $ $ $ $ $ # 
# $ $ $ $ $ $ $ $ $ $ $ $ # 
# $ $ $ $ $ $ $ $ $ $ $ $ # 
# $ $ $ $ $ $ $ $ $ $ $ $ # 
# # # # # # # # # # # # # # 
OUTPUT
# # # # # # # # # # # # # # 
# r r r r r r r r r r r r # 
# r r r r r r r r r r r r # 
# r r r r r r r r r r r r # 
# r r r r r r r r r r r r # 
# r r r r r r r r r r r r # 
# r r r r r r r r r r r r # 
# # # # # # # # # # # # # # 
*/