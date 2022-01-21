#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <sstream>
#define FOR0(a,b) for(int a=0;a<b;a++)

using namespace std;

string to_lower(string s){
    string n;
    for(char c : s){
        n += tolower(c);
    }
    return n;
}

struct T {
    string name;
    string email;
};

int main(){
    string first, last, email, n;
    vector<T> system1, system2;
    set<string> names1, names2;
    set<string> emails1, emails2;
    
    int i = 0;
    while(getline(cin, n)){
        if(n.empty())
            break;
        
        istringstream iss(n);
        iss >> first >> last >> email;
        
        system1.push_back({last + " " + first, email});
        names1.insert(to_lower(last + " " + first));
        emails1.insert(to_lower(email));
    }
    
    i = 0;
    while(getline(cin, n)){
        if(n.empty())
            break;
        
        istringstream iss(n);
        iss >> first >> last >> email;
        
        system2.push_back({last + " " + first, email});
        names2.insert(to_lower(last + " " + first));
        emails2.insert(to_lower(email));
    }
    
    sort(system1.begin(), system1.end(), [](T a, T b) {return to_lower(a.email) < to_lower(b.email);});
    sort(system2.begin(), system2.end(), [](T a, T b) {return to_lower(a.email) < to_lower(b.email);});
    
    bool perfectMatch = true;
    for(T entry : system1){
        auto it = names2.lower_bound(to_lower(entry.name));
        
        if(it == names2.end() || *it != to_lower(entry.name)){
            auto it2 = emails2.lower_bound(to_lower(entry.email));
            
            if(it2 == emails2.end() || *it2 != to_lower(entry.email)){
                cout << "I " << entry.email << " " << entry.name << endl;
                perfectMatch = false;
            }
        }
    }
    
    for(T entry : system2){
        auto it = names1.lower_bound(to_lower(entry.name));
        
        if(it == names1.end() || *it != to_lower(entry.name)){
            auto it2 = emails1.lower_bound(to_lower(entry.email));
            
            if(it2 == emails1.end() || *it2 != to_lower(entry.email)){
                cout << "O " << entry.email << " " << entry.name << endl;
                perfectMatch = false;
            }
        }
    }
    
    if(perfectMatch)
        cout << "No mismatches." << endl;
}