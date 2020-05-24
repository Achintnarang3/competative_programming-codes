/*INPUT
3 3
Rahul Ajay 100
Ajay  Neha 50
Neha Rahul 40
*/
/*OUTPUT
Rahul will pay 50 to Ajay
Rahul will pay 10 to Neha
2
*/
//money spiltwise algorithm
#include <bits/stdc++.h>
using namespace std;
class person_compare{
    public:
    bool operator()(pair<string , int>p1 , pair<string , int> p2){
        return p1.second < p2.second;
    }
};
int main() {
    int no_of_transcations , friends;
    cin>>no_of_transcations>>friends;
    string x , y ;
    int amount;
    map<string , int>net;
    while(no_of_transcations--){
         cin>>x>>y>>amount;
         if(net.count(x) == 0){
             net[x] = 0;
         }
         if(net.count(y) == 0){
             net[y] = 0;
         }
         net[x] -= amount;
         net[y] += amount;
    }
    multiset<pair<string ,int> , person_compare> m;
    //iterate over the persons add them in multiset who have non zero net
    for(auto x : net){
        string person = x.first;
        int amount = x.second;
        if(net[person] != 0){
            m.insert(make_pair(person , amount));
        }
    }
    int count = 0;
    //pop out two persons(one from left and one from right) and settle them
    while(!m.empty()){
        auto low = m.begin();
        auto high = prev(m.end());

        int debit = low->second;
        string debit_person = low->first;
        int credit = high->second;
        string credit_person = high->first;

        //erase them from the set
        m.erase(low);
        m.erase(high);

        //settlement
        int settle_amount = min(-debit , credit);
        count++;

        //settle amount from donar to acceptor
        debit += settle_amount;
        credit -= settle_amount;

        cout<<debit_person<<" will pay "<<settle_amount<<" to "<<credit_person<<endl;
        if(debit != 0){
            m.insert(make_pair(debit_person , debit));
        }
        if(credit != 0){
            m.insert(make_pair(credit_person , credit));
        }
    }
    cout<<count;
    return 0;
}
