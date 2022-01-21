#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(!cin.eof()){
        cout << n <<  " ";
        for(int i = 0; i < n-1; i++){
            cout << 1;
        }
        cout << 0 << endl;
        cin >> n;
    }
    return 0;
}