#include <iostream>
#include <queue>

using namespace std;


/*
  X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된
 */
int visited[100001]={0,};

int N, K;


int main(void)
{
    
    cin >> N >> K;

    queue <int> q;
    q.push(N);
    
    while(!q.empty()){
        
        int idx = q.front();
        q.pop();
        
        if(idx==K)  {
            cout << visited[idx];
            return 0;
        }
                        
        int nx = idx + 1;
        
        for(int k=0;k<3;k++){
            
            if(k==0)    nx = idx+1;
            else if(k==1)   nx = idx-1;
            else    nx = idx*2;
            
            if(nx < 0 || nx > 100000 ) continue;
            if(visited[nx]!=0 )  continue;
            
            visited[nx]=visited[idx]+1;
            q.push(nx);
        }
        
    }
    
    return 0;
    
}

