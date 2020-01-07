#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
cin>>n;
int a[n];
int num  ,res=0;
for(int i = 0; i<n ; i++){
    cin>>num;
    a[i] = num;
    res = res^num;
}
int temp = res;
//res = a^b
//checking where is first set bit in res
int  pos=0;
while((temp&1)!=1){
pos++;
temp =temp>>1;
}
//the first bit in res is at postion pos
int mask = (1<<pos);
int x =0 ;
int y=0;
for(int i = 0 ;i< n ; i++){
 if((a[i]&mask) > 0){
     x = x^a[i];
 }
}
y = x^res;

cout<<min(x,y)<<" "<<max(x,y);

}

