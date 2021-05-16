#include <string>
#include <vector>
#include <iostream>

using namespace std;

string ans ="";

void upperTolower()
{
    for(int i=0;i<ans.size();i++)
        if(ans[i] >= 'A' && ans[i] <= 'Z')  ans[i] = ans[i] + 32;
}

void remove()
{
    vector <char> v;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i] >= 'a' && ans[i] <= 'z')  v.push_back(ans[i]);
        else if(ans[i] >= '0' && ans[i] <= '9')  v.push_back(ans[i]);
        else if(ans[i] == '_' || ans[i] == '-' || ans[i] == '.')    v.push_back(ans[i]);
    }
    ans.clear();
    for(int i=0;i<v.size();i++) ans+=v[i];
}

void rep_remove()
{
    vector <char> v;
    int idx =0;
    while(idx < ans.size())
    {
        if(ans[idx] == '.')
        {
            if(ans[idx+1]=='.'){
                while(ans[idx+1] == '.' && idx < ans.size()-1)  idx++;
            }
        }
        v.push_back(ans[idx]);
        idx++;
    }
    ans.clear();
    for(int i=0;i<v.size();i++) ans+=v[i];
}

void resize()
{
    if(ans.size()>15){
        ans = ans.substr(0,15);
        if(ans[ans.size()-1] == '.')    ans = ans.substr(0,ans.size()-1);
    }
    else if(ans.size() < 3){
        if(ans.size()==1){
            for(int i=0;i<2;i++)    ans+=ans[0];
        }
        else    ans+=ans[1];
    }
}

string solution(string new_id) {
    string answer = "";
    
    ans = new_id;
    
    upperTolower();
    remove();
    rep_remove();
    if(ans[0] == '.')   ans = ans.substr(1,ans.size()-1);
    if(ans[ans.size()-1] == '.')    ans = ans.substr(0,ans.size()-1);
    if(ans=="") ans+="aaa";
    resize();
    return ans;
}
