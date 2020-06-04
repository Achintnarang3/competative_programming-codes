/*
Sayan's friend has left a gamefield organized as an N∗N grid.Each square in the grid 
either has or does not have a gold coin. He has to divide the gamefield with his 
three other friends as follows: he will draw one horizontal line and one vertical 
line to divide the field into four rectangles. His friends will choose three of 
the four smaller fields and he gets the last one.He wants to divide the field 
so that he gets the maximum number of goldcoins, assuming that his friends 
will pick the best three rectangles.

Input Format
The first line contains 2 integers N and M, the size of the gamefield and 
the number of gold coins in the field respectively.
The next M lines contain two integers, Xi and Yi, 
giving the coordinated of the i-th gold coin. 
It is guaranteed that all Xi and Yi are pairwise distinct.

Constraints
1 ≤ N ≤ 1000
0 ≤ M ≤ N^2
1 ≤ Xi,Yi ≤ N

Output Format
Output one integer, the maximum number of gold coins Sayan can get.

Sample Input
6 13
1 2
1 3
2 1
2 4
2 5
3 2
4 2
4 3
4 6
5 1
5 4
5 5
6 2
Sample Output
3
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
     int dp[n][n];
    int c;
    cin >> c;
    int grid[n][n];
    memset(grid , 0 , sizeof(grid));
   for(int i=0;i<c;i++){
       int x , y ;
       cin >> x >> y;
       grid[x-1][y-1] = 1;
   }
    dp[0][0]=grid[0][0];
    for(int i=1;i<n;i++){
        dp[0][i] = dp[0][i-1]+grid[0][i];
    }
     for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0]+grid[i][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=dp[i][j-1]+dp[i-1][j] - dp[i-1][j-1];
            if(grid[i][j]==1){
                dp[i][j]+=grid[i][j];
            }
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a= dp[i][j];
            int b= dp[i][n-1]-a;
            int c = dp[n-1][j]-a;
            int d= (dp[n-1][n-1]-a-b-c);

             ans= max(ans,min(a,min(b,min(c,d))));
        }
    }
    cout << ans << endl;
   
}
