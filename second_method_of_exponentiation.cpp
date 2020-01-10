#include <iostream>
using namespace std;
int power(int a ,int b){
    //base case
    if(b == 0){
        return 1;
    }
    //recursive case check whether b is even or odd
    int smallerAns = power(a,b/2);
    smallerAns *= smallerAns;
    // check b is odd
    if(b&1){
        smallerAns = a*smallerAns;
    }
    return smallerAns;
}
int main() {
    int a , b ;
    cin>>a>>b;
    cout<<power(a , b);
}
