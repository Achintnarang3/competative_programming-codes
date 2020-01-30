#include<iostream>
using namespace std;
int product(int n ,int m){

    if(n>0 && m<0){
        return product(m , n);
    }
    else if(n<0 && m<0){
        return product((-1*n) , (-1*m));
    }
    if(n>m){
        product(m ,n);
    }
    else if(m!=0){
        return (n += product(n , m-1));
    }
    else
    return 0;
}
int main(){
    cout<<product(5 , 3)<<endl;
    cout<<product(-5 , 3)<<endl;
    cout<<product(-5 , -3)<<endl;
    cout<<product(5 , -3)<<endl;
    return 0;
}