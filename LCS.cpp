//LONGEST COMMON SUBSEQUENCE
#include<bits/stdc++.h>
using namespace std;

int LCS(char *s1 , char *s2){

    int dp[100][100];
    int m = strlen(s1) ; 
    int n = strlen(s2) ;
    for(int i=0 ; i<=m ; i++){
        dp[i][0] = 0;
    }
    for(int j=0 ; j<=n ; j++){
        dp[0][j] = 0;
    }

    for(int i=1 ; i<=m ; i++){
        for(int j=1 ; j<=n ; j++){
            int q=0;
            if(s1[i-1] == s2[j-1]){
                q = 1 + dp[i-1][j-1];
            }else{
                q = max(dp[i][j-1] , dp[i-1][j]);
            }
            dp[i][j] = q;
        }
    }
    return dp[m][n];
}
int main(){
    char s1[100] , s2[100];
    cin>>s1>>s2;
    cout<<LCS(s1, s2)<<endl;
    return 0;
}
