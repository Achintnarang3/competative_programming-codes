#include <iostream>
#include<queue>
using namespace std;

class Car{
public:
    int id;
    int x;
    int y;

    Car(int id , int x , int y){
      this->id = id;
      this->x  = x;
      this->y = y;
    }
    int dist(int x , int y){
       return (x*x)+(y*y);
    }
    void print(){
      cout<<"id: "<<id<<endl;
      cout<<"x:  "<<x<<endl;
      cout<<"y:  "<<y<<endl;
    }
};
bool carCompare(Car a , Car b){
    if(a.dist() > b.dist()){
        return 1;
    }else{return 0;}
}

int main()
{
    priority_queue<Car , vector<Car> , carCompare>pq;
    int id;
    int x[10] = {5 , 6 ,17 , 18 , 9 , 11 , 0 ,3};
    int y[10] = {1, -2 , 8, 9, 10 , 11 , 1 , 2};

    for(int i=0 ; i<8 ; i++){
       Car c(id , x[i] , y[i]);
        pq.push(c);
    }

    while(pq!=empty()){
        Car P = pq.top();
        P.print();
    }
    return 0;
}
