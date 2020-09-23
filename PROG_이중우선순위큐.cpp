
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector <int> v;

bool comp(int a, int b){
    return a>b;
}

void solve(string str)
{
    string num = str.substr(2);
    int tmp = stoi(num);
    if(str[0] == 'I')   v.push_back(tmp);
    else if(str[0]=='D'){
        if(v.size()==0) return;
        if(tmp==1)  sort(v.begin(),v.end()); // 최댓값 삭제
        else    sort(v.begin(),v.end(),comp);
        v.pop_back();
    }
}


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    int osize = operations.size();
    
    for(int i=0;i<osize;i++){
        string oper = operations[i];
        solve(oper);
    }
    
    if(v.size() == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        sort(v.begin(),v.end());
        answer.push_back(v[v.size()-1]);
        answer.push_back(v[0]);
    }
    return answer;
    
}

