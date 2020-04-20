/* INPUT
6
0 0 
0 1
1 0
0 2
1 1
1 2
*/
/* OUTPUT
0 0
0 1
0 2
1 0
1 1
1 2
*/
#include <bits/stdc++.h>
using namespace std;
struct point{
  int x , y;
  bool operator < (point &o){
      if(o.x == x) return y < o.y;
      else return x < o.x;
  }
  bool operator == (point &o){
      return (o.x == x && o.y == y);
  }
};
bool clock_wise(point a , point b , point c){
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) > 0; 
}
bool counter_clock_wise(point a , point b , point c){
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) < 0; 
}
bool collinear(point a , point b , point c){
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) == 0; 
}

void convex_hull(vector<point> &p){
    if(p.size() <= 2){
        return ;
    }
    sort(p.begin() , p.end());
    //p[0] is point p1 and p[n-1] is point p2
    int i , n = p.size();
    point p1 = p[0] , p2 = p[n-1];
    //actually p1 is bottom left point and p2 is top right point
    vector<point> up , down;
    up.push_back(p1);
    down.push_back(p1);
    for(i=1 ; i<n ; i++){
        //now we have to check whether current point is 
        //in lower half or right half
        if( i == n-1 || !counter_clock_wise(p1 , p[i] , p2)){
          // p[i] is in upper half
          while(up.size() >= 2 && counter_clock_wise(up[up.size()-2] , up[up.size()-1] , p[i])){
              up.pop_back();
          }
          up.push_back(p[i]);
        }
        if(i == n-1 || !clock_wise(p1 , p[i] , p2)){
          // p[i] is in lower half
           while(down.size() >= 2 && clock_wise(down[down.size()-2] , down[down.size()-1] , p[i])){
              down.pop_back();
          }
          down.push_back(p[i]);
        }
    }
   // now at this point up nd down vector contains all the points including p1 nd p2 repetedly
   p.clear();
   for(int i=0 ; i<up.size() ; i++){
       p.push_back(up[i]);
   }
   for(int i=0 ; i<down.size() ; i++){
       p.push_back(down[i]);
   }
   //p vector contains all the points of up and down vector
   sort(p.begin() , p.end());
   p.resize(unique(p.begin() , p.end()) - p.begin());
}
int main() {
    int n;
    cin>>n;
    vector<point> p(n);
    for(int i=0 ; i<n ; i++){
        cin>>p[i].x >> p[i].y;
    }
    convex_hull(p);
    //now p contains convex hull points
    for(auto f : p){
       cout<<f.x<<" "<<f.y<<endl;
    }
    return 0;
}
