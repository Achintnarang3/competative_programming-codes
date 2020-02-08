#include <iostream>
using namespace std;
int count =0;
bool ratInMaze(char maze[10][10] , int soln[][10] , int i , int j , int m , int n){
    //base case
    if(i == m && j == n){
        soln[m][n] = 1;
        count++;
        //print 
        for(int i=0 ; i<=m ; i++){
            for(int j=0 ; j<=n; j++){
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    //rat should be inside the maze
    if(i>m  || j>n){
        return false;
    }
    if(maze[i][j] == 'X'){
        return false;
    }
    //assume the current position is correct
    soln[i][j] = 1;
    //recursive 
    bool rightSuccess = ratInMaze(maze , soln , i , j+1 , m , n);
    bool downSuccess = ratInMaze(maze , soln , i+1 , j , m , n);
    //backtrack
    soln[i][j] = 0 ; //in order to find all possible paths

    if(rightSuccess  || downSuccess){
        return true;
    }
    return false;
}
int main() {
    char maze[10][10] = {
                   "0000",
                   "00X0",
                   "000X",
                   "0X00",
                };
    int m =4 , n =4;
    int soln[10][10] = {0};
    bool result = ratInMaze(maze , soln , 0 , 0 , m-1 , n-1);
    if(result == false){
        cout<<"path doesn't exist"<<endl;
        cout<<count;
        return 0;
    }
    cout<<count;
    return 0;
}
