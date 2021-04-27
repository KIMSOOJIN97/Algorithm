#include <string>
#include <vector>
#include <set>
#define MAX 8

using namespace std;

vector<int> v[MAX];
set<string> s;
bool visited[MAX]={0,};
int bsize= 0;
int usize=0;
int res= 0;

void DFS(int cnt,int idx)
{
    if(cnt == bsize)
    {
        string tmp="";
        for(int i=0;i<usize;i++){
            if(visited[i])  tmp+=to_string(i);
        }
        s.insert(tmp);
        return ;
    }
    for(int i=0;i<v[idx].size();i++)
    {
        int num = v[idx][i];
        if(visited[num])    continue;
        visited[num]=true;
        DFS(cnt+1, idx+1);
        visited[num] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    bsize= banned_id.size();
    usize= user_id.size();
    for(int i=0;i<bsize;i++)
    {
        int len1= banned_id[i].size();
        for(int j=0;j<user_id.size();j++)
        {
            int len2 = user_id[j].size();
            if(len1 != len2)    continue;
            bool check = true;
            for(int k=0;k<len1;k++){
                if(banned_id[i][k] == '*')  continue;
                if(banned_id[i][k] != user_id[j][k]){
                    check = false;
                    break;
                }
            }
            if(check)   v[i].push_back(j);            
        }   
    }

    DFS(0,0);
    answer = s.size();
    return answer;
}
