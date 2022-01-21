#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string n;
    int answer = 0;
    
    while(cin >> n){
        set<string> answers;
        int unique = 0;
        vector<bool> stringSet(256, 0);
        for(int i = 0; i < n.size(); i++){
            stringSet[n[i]] = 1;
        }
        for(int i = 0; i < stringSet.size(); i++){

            if(stringSet[i] == 1)
                unique++;
        }

        
        for(int i = 0; i < n.size(); i++){
            string possible = "";
            possible += n[i];
            int subUnique = 1;
            vector<bool> subSet(256, 0);
            subSet[n[i]] = 1;
            if(unique == subUnique and answers.find(possible) == answers.end()){
                if(possible.size() == n.size())
                    answer--;
                answer++;
                answers.emplace(possible);
            }
            for(int j = i+1; j < n.size(); j++){
                    if(n[i] == n[j])
                        break;
                    possible += n[j];
                    if(subSet[n[j]] == 0){
                        subUnique++;
                    }
                   
                    
                    
                    if(unique == subUnique and answers.find(possible) == answers.end()){
                        if(subSet[n[j]] == 1 or possible.size() == n.size())
                            break;
                        answer++;
                        answers.emplace(possible);
                    }
                    subSet[n[j]] = 1; 
                
            }
        }
        cout << answer << endl;
        answer = 0;
    }
    
    return 0;
}