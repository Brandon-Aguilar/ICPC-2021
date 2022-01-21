#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

int main(){

    long long players;
    cin >> players;

    for(long long i = 0; i < players; i++){
        long long a;
        long long b;
        long long c;
        long long d;

        cin>> a;
        cin>> b;
        cin>> c;
        cin>> d;

        for(long long j = 0; j < d; j++){
            long long aCalc = (a+1) * (a+1) + b*b + c*c + (7 * min(min(a+1,b),c));
            long long bCalc = a*a + (b+1) * (b+1) + c*c + (7 * min(min(a, b + 1), c));
            long long cCalc = a*a + b*b + (c+1) * (c+1) + (7 * min(min(a, b), c + 1));
            if(aCalc > bCalc and aCalc >  cCalc)
                a++;
            else if(bCalc > aCalc and bCalc > cCalc)
                b++;
            else
                c++;
        }
        cout << a*a + b*b + c*c + (7 * min(min(a, b), c)) << endl;
    }


    return 0;
}