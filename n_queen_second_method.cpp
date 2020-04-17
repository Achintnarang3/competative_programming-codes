#include <iostream>
using namespace std;
int n  , DONE;
int ans = 0;
int board[100][100] ={0};
int get_position(int p){
	int ans=0;
	while(p>0){
		ans++;
		p = p>>1;
	}
	return ans-1;
}
void solve(int rowmask , int ld , int rd  , int row){
    if(rowmask == DONE){
    	for(int i=0 ; i<n ; i++){
    		for(int j=0 ; j<n ; j++){
    		cout<<board[i][j]<<" ";
    	}
    	cout<<endl;
    	}
    	cout<<endl;
        ans++;
    }
   int safe = DONE & (~(rowmask|ld|rd));
   while(safe){
        int p = safe & (-safe);
        int col = get_position(p);
        board[row][col]=1;
        safe = safe - p;
        solve(rowmask|p , (ld|p)<<1 , (rd|p)>>1 , row+1);
        board[row][col] = 0;
   }
   
}
int main() {
    cin>>n;
    DONE = (1<<n)-1;
    solve(0 ,0 , 0,0);
    cout<<ans;
    return 0;
}
