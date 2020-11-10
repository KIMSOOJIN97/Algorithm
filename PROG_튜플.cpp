#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector <int> tmp;
    vector <pair<int , vector<int>>> v;
    int j=0;
    bool flag = false;
    
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='{')   continue;
        else if(s[i]=='}' || s[i] == ',')
        {
            if(flag){
                int num = stoi(s.substr(j,i-j));
                tmp.push_back(num);
                if(s[i]=='}'){
                    v.push_back({v.size(),tmp});
                    tmp.clear();
                }
                flag = false;
            }
        }
        else{
            if(!flag){
                flag = true;
                j = i;
            }
        }
    }
    
    sort(v.begin(),v.end());
    
    set <int> check;
    for (pair<int, vector<int>> p : v) {
        for (int num : p.second) {
            // 중복되지 않는 값만 넣어줌.
            if (check.find(num) == check.end()) {
                check.insert(num);
                answer.push_back(num);
            }
        }
    }

    return answer;
}

