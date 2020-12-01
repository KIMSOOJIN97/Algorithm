#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {

    string answer = "";

    vector <int> v;
    string tmp="";
    
    for(int i=0;i<s.size();i++){
        
        if(s[i]==' '){
            v.push_back(stoi(tmp));
            tmp="";
        }
        else    tmp+=s[i];
    }
    v.push_back(stoi(tmp));
    sort(v.begin(),v.end());
    answer = to_string(v[0]) + " " + to_string(v[v.size()-1]);
    return answer;
}
