#include<iostream>
using namespace std;

int gcd(int a , int b){
    if(b == 0){
        return a;
    }else{
        gcd(b, a%b);
    }
}
int x , y , gd;
void extended_euclid(int a , int m){
    if(m == 0){
        x = 1;
        y =0;
        gd = a;
    }else{
        extended_euclid(m , a%m);
        int cX = y;
        int cY = x - (a/m)*y;

        x = cX;
        y = cY;
    }
}

int moduloInverse(int a , int m){
    if(gcd(a, m) == 1){
        extended_euclid(a ,m);
        return (x+m)%m;
    }
}

int main(){
   cout<<moduloInverse(6 , 7) ;
}