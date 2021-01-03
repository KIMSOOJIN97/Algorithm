#include <iostream>
#include <queue>
#define MAX 200001

using namespace std;

int n[2] = {-1,1};
int visited[MAX]={0,};
int parent[MAX]={0,};
int N,K;
vector <int> ans;

void bfs()
{
    queue<int> q;
    q.push(N);
    
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        
        if(idx == K ){
            cout << visited[idx] << "\n";
            while(idx != N){
                ans.push_back(idx);
                idx= parent[idx];
            }
            ans.push_back(N);
            return ;
        }
        for(int i=0;i<3;i++){
            int nidx =0;
            if(i==2)    nidx = idx*2;
            else nidx = idx+n[i];
            
            if(nidx < 0 || nidx > MAX || visited[nidx] ) continue;
            
            q.push(nidx);
            visited[nidx]=visited[idx]+1;
            parent[nidx] = idx;
        }
    }

int main(void)
{
    cin >> N >> K;
    bfs();
    int _size = ans.size()-1;
    for(int i=_size; i>=0 ; i--)
        cout << ans[i]<< " ";
    return 0;
}


