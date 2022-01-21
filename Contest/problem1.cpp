#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string to_lower(string s){
    string n = "";
    for(int i = 0; i < s.size(); i++){
        n+=  tolower(s[i]);
    }
    return n;
}

struct entry{
    string first;
    string last;
    string email;
    string flow;
    string llow;
    string elow;
    bool match = false;
};

bool ecompare(entry a, entry b){return a.elow < b.elow;}

int main(){
    string n;
    vector<entry> cases;
    vector<entry> ans;

    while(getline(cin, n)){
        if(n.empty())
            break;
        
        istringstream iss(n);
        entry input;
        string f;
        string l;
        string e;
        iss >> f;
        iss >> l;
        iss >> e;
        input.first = f;
        input.last = l;
        input.email = e;
        f = to_lower(f);
        l = to_lower(l);
        e = to_lower(e);
        input.flow = f;
        input.llow = l;
        input.elow = e;
        cases.push_back(input);
    }

    int right = 0;
    int outsides = 0;
    while(getline(cin, n)){
        outsides++;
        if(n.empty())
            break;
        
        string res = "";
        istringstream iss(n);
        string f;
        string l;
        string e;
        iss >> f;
        iss >> l;
        iss >> e;
        entry input;
        input.first = f;
        input.last = l;
        input.email = e;

        f = to_lower(f);
        l = to_lower(l);
        e = to_lower(e);
        input.flow = f;
        input.llow = l;
        input.elow = e;
        bool found = false;
        for(int i = 0; i < cases.size(); i++){
            if(input.flow == cases[i].flow and input.llow == cases[i].llow){
                found = true;
                    right++;
                    cases[i].match = true;
            } else if(input.elow == cases[i].elow){
                    found = true;
                    right++;
                    cases[i].match = true;
            }
        }
        if(!found){
            ans.push_back(input);
        }
    }

    if(right == max(int(cases.size()), outsides)){cout << "No mismatches." << endl; return 0;}
    sort(cases.begin(), cases.end(), ecompare);
    sort(ans.begin(), ans.end(), ecompare);
    


    for(int i = 0; i < cases.size(); i++){
        if(cases[i].match == false){
            cout << "I " << cases[i].email << " " <<  cases[i].last << " " << cases[i].first << endl;
        }
    }

    for(int i = 0; i < ans.size(); i++){

        cout << "O " << ans[i].email << " " <<  ans[i].last << " " << ans[i].first << endl;
    }


    return 0;
}