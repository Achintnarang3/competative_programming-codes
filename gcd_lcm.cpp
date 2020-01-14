#include <iostream>
using namespace std;
int gcd(int a ,int b){

   //base case
   if(b == 0){
       return a;
   }else
   return gcd(b , a%b);
   
}
int main() {
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    int lcm = (a*b)/(gcd(a,b));
    cout<<lcm<<endl;
return 0;
}
