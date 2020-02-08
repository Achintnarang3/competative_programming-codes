#include<iostream>
using namespace std;
int number_of_people(float p){
	float num = 365;
	float denom = 365;
	float prob = 1; //probabilty that some people have same birthday
	int people = 0;
	while(prob > p){
		prob = prob*(num)/denom;
		num--;
		people++;
	}
	return people;
}
int main() {
	float p;
	cin>>p;
	if(p == 1.0){
		cout<<366;
	}else{
	cout<<number_of_people(1-p);
	}
	return 0;
}