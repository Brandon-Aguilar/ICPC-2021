#include <iostream>
#include <cmath>
#define dd double
#define FOR0(a,b) for(ll a=0;a<b;a++)
#define FOR0B(a,b) for(ll a=b-1;a>=0;a--)
#define FOR1(a,b) for(ll a=1;a<=b;a++)
#define FOR(a,b,c) for(ll a=b;a<c;a++)

using namespace std;

int main(){
    dd tf, tr;
    dd s, lastS = 0;
    cin >> tf >> tr;
    bool outside = 0;
    bool outOne = false;
    
    while(cin >> s){
        if(s > 0 && s < 1){
            cout << 1 << endl;
            outOne = true;
        }
        if(fmod(s, 1.0) < tf){
            if(!outOne)
                cout << floor(s) << endl;
            outside = 0;
        }
        else if(fmod(s, 1.0) > tr){
            if(!outOne)
                cout << ceil(s) << endl;
            outside = 1;
        }
        else {
            if(!outOne){
                if(outside){
                    cout << ceil(s) << endl;
                }
                else{
                    cout << floor(s) << endl; 
                }
            }
        }
        outOne = false;
    }
    return 0;
}