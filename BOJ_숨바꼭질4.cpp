#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

int n[2] = {-1,1};
int visited[MAX]={0,};
int N,K;
vector <int> ans;

void BFS()
{
    queue<int> q;
    q.push(N);
    visited[N]=1;
    
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        
        if(idx == K ){
            int idx =K;
            int pos=0;
            while(idx != N){
                ans.push_back(idx);
                pos = visited[idx];
                idx = pos;
            }
            return ;
        }
        for(int i=0;i<3;i++){
            int nidx =0;
            if(i==2)    nidx = idx*2;
            else nidx = idx+n[i];
            
            if(nidx < 0 || nidx >= MAX || visited[nidx] !=0) continue;
            
            q.push(nidx);
            visited[nidx] = idx;
        }
    }
}

int main(void)
{
    cin >> N >> K;
    BFS();
    

    cout << ans.size() << "\n";
    if(ans.size()==0)   return 0;

    cout << N << " ";

    for(int i=ans.size()-1 ; i>=0 ; i--)
        cout << ans[i]<< " ";
    
    return 0;
}

