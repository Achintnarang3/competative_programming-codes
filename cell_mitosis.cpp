/*There's a scientist named Brook who is interested in budding of cells. 
He has one container which initially contains only a single cell. 
Now Brook wants n number of cells in his container. So he can change the number of cells in container in 3 different ways -:
-->Double the number of cells present in the container.
-->Increase the number of cells in the container by 1.
-->Decrease the number of cells in the container by 1.
Now, all the above operations have different costs associated with them x,y,z respectively for above operations.
 Help brook in finding the minimum cost to generate n cells in the container starting from one cell .
 */

/*
Input Format
Each test case contains 2 lines. First lines contains an integer n Second lines contains 3 space separated integers x, y, and z
*/
/*
Output Format
Output an integer denoting the minimum cost incurred to create n cells
*/
 #include<iostream>
 using namespace std;
int cell_mitosis(int n , int x , int y , int z){
    int dp[n+1] ;
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2 ; i<=n ;i++){
       
       if(i%2 == 0){
           dp[i] = min(dp[i/2]+x , dp[i-1]+y);
       }else{
           dp[i] = min(dp[i-1]+y , dp[(i+1)/2] + x + z);
       }
    }
    return dp[n];
}
 int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x , y, z;
        cin>>x>>y>>z;
        cout<<cell_mitosis(n , x, y , z)<<endl;;
    }
  return 0;
 }