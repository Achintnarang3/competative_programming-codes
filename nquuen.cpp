#include <iostream>
using namespace std;
int n;
bool grid[10][10];
bool isSafe(int row , int col){
    for(int i=0 ; i<row ; i++){
        if(grid[i][col] == 1){
            return false;
        }
    }
    int x = row;
    int y = col;
    while(x>=0 && y>=0){
        if(grid[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    x = row;
    y = col;
    while(x>=0 && y<n){
        if(grid[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}
void printgrid(){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(grid[i][j] == 1){
                cout<<"Q ";
            }else{
                cout<<"_ ";
            }
        }
        cout<<endl;
    }
}
int count =0;
void solve_n_queen(int row){
    if(row == n){
        printgrid();
        cout<<endl;
        count++;
        return ;
    }
    for(int col =0 ; col<n ; col++){
        if(isSafe(row , col)){
            grid[row][col] = 1;
            solve_n_queen(row+1);
            grid[row][col] = 0;
        }
    }
}
int main() {
    cin>>n;
    solve_n_queen(0);
    cout<<count;
}
