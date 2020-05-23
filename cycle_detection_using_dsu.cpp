#include <bits/stdc++.h>
using namespace std;
struct dsu{
  vector<int>par;
  void init(int n){
      par.resize(n);
      for(int i=0 ; i<n ;i++){
          par[i] = i;
      }
  }
  int get_super_parent(int x){
      if(x == par[x]){
          return x;
      }else{
          return par[x] = get_super_parent(par[x]);
      }
  }
  void unite(int x ,int y){
      int super_parent_x = get_super_parent(x);
      int super_parent_y = get_super_parent(y);
      if(super_parent_x != super_parent_y){
          par[super_parent_x] = super_parent_y;
      }
  }
};
int main() {
    int n , m;
    cin>>n>>m;
    dsu d;
    d.init(n);
    bool cycle = false;
    for(int i=0 ; i<m ; i++){
        int x ,y;
        cin>>x>>y;
        x-- ; y--;  // as there is zero based indexing used in the graph
        // and the inputs are in the one based indexing
        if(d.get_super_parent(x) != d.get_super_parent(y)){
            //they are in different components
            d.unite(x , y);
        }else{
            // they are in same component
            //there was an path from x to y
            cycle=true;
        }
    }
    if(cycle){
        cout<<"Cycle is present"<<endl;
    }else{
        cout<<"Cycle is not present"<<endl;
    }
   return 0;
}
