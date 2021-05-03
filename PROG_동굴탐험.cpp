#include <string>
#include <vector>
#include <map>
#define MAX 200000

using namespace std;

vector<int> v[MAX];
int hang[MAX]={0,};
bool visited[MAX]={0,};
map <int,int> post;

void DFS(int idx)
{
    if(visited[idx])    return;
    if(post.find(idx) != post.end())
    {
        int pre = post.at(idx);
        if(!visited[pre])
        {
            hang[pre] = idx;
            return ;
        }
    }
    visited[idx]=true;
    DFS(hang[idx]);
    for(int i=0;i<v[idx].size();i++)    DFS(v[idx][i]);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;

    for(auto tmp : path)
    {
        v[tmp[0]].push_back(tmp[1]);
        v[tmp[1]].push_back(tmp[0]);
    }
    
    for(auto tmp : order)    post.insert(make_pair(tmp[1], tmp[0]));
    
    if(post.find(0) != post.end() )   return false;
   
    visited[0]=true;
    for(int idx : v[0]) DFS(idx);
   
    for(int i=0;i<n;i++)    if(!visited[i]) answer= false;
    
    return answer;
}
