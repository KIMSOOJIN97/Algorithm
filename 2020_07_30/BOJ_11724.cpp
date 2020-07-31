#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;
int visited[1001]={0,};

vector <int> v[1001];

int main(void)
{
    cin >> N >>M;
    for(int i=0;i<M;i++){
        int start,end;
        cin >> start >> end;
        v[start].push_back(end);
        v[end].push_back(start);
    }
    int cnt =0;
    
    
    queue <int> q;
    
    for(int i=1;i<=N;i++){
        if(visited[i] == 0 ){
            visited[i]=1;
            q.push(i);
            cnt++;
        }
        while(!q.empty()){
            
            int idx = q.front();
            q.pop();
                        
            for(int j=0;j<v[idx].size();j++){
                
                int tmp = v[idx][j];
                if(visited[tmp] == 0 ){
                    visited[tmp]=1;
                    q.push(tmp);
                }

                
            }
        }
    }
    cout << cnt;

    return 0;
    
}

