#include <iostream>
using namespace std;
int x, y, gcd;
void extendedEulid(int a ,int b){
   //base case
   if(b == 0){
       x =1;
       y=0;
       gcd =a;
       return;
   }else{
   //recursive case
   extendedEulid(b , a%b);
   int cX = y;
   int cY = x-(a/b)*y;

   cout<<cX<<" , "<<cY<<endl;

   x = cX;
   y =cY;
}
}
   int main() {
    //18x + 30y = 6
    extendedEulid(18 , 30);
    cout<<"final answer :"<<x<<" , "<<y<<endl;
return 0;
}