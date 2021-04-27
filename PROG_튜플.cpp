#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.second > b.second) return true;
	return false;
}
vector<int> solution(string s) {
    vector<int> answer;
    map<int,int> m;
        
    string num = "";

    for(int i=1;i<s.size()-1;i++)
    {
        if(s[i] == ',' || s[i] == '}' || s[i]=='{')
        {
            if(num=="") continue;
            m[stoi(num)]++;
            num="";
        }
        else    num+=s[i];
    }
    vector<pair<int,int>> v( m.begin(), m.end() );
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++) answer.push_back(v[i].first);
    return answer;
}
