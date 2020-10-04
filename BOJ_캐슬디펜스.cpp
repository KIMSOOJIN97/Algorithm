#include <iostream>
#include <vector>

#define MAX 15
using namespace std;

int N,M,D;
int map[MAX][MAX]={0,};
int res =0;
int visited[MAX]={0,};


struct pos{
    int x,y;
    bool die;
};

pos enemy[MAX*MAX];
int num=0;


void solve()
{
    int cnt = num;
    int killed=0;
    
    pos tmp[MAX*MAX];
    for(int i=0;i<num;i++)  tmp[i] = enemy[i];
    
    while(cnt > 0)
    {
        vector <int> v;
        
        for(int i=0;i<M;i++)
        {
            if(visited[i] == 0) continue;
            
            int idx = num;
            pos info;
            
            int dis = 1e9;
            
            for(int j=0;j<num;j++){
                
                if(tmp[j].die)    continue;
                int x = tmp[j].x;
                int y = tmp[j].y;
                
                int dy = y > i ? y-i : i-y;
                if(N-x+dy > D)  continue;
                
                if(dis > N-x+dy ){
                    info.x = x;
                    info.y = y;
                    dis = N-x+dy;
                    idx = j;
                }
                else if(dis == N-x+dy ){
                    if(info.y > y)
                    {
                        info.x = x;
                        info.y = y;
                        idx = j;
                    }
                }
            }
            if(idx!=num)  v.push_back(idx);
        }
        
        for(int i=0;i<v.size();i++){
            if(tmp[v[i]].die) continue;
            cnt--;
            killed++;
            tmp[v[i]].die = true;
        }
        
        for(int i=0;i<num;i++)
        {
            if(tmp[i].die)    continue;
            tmp[i].x+=1;
            if(tmp[i].x == N) {
                cnt--;
                tmp[i].die=true;
            }
        }
    }
    
    if(killed > res )   res = killed;
    return ;
}



void DFS(int cnt, int idx)
{
    if(cnt == 3)
    {
        solve();
        return;
    }
    
    for(int i=idx;i<M;i++){
        if(visited[i] ==0)
        {
            visited[i] =1;
            DFS(cnt+1,i+1);
            visited[i]=0;
        }
    }
}
int main(void)
{
    scanf("%d %d %d",&N,&M,&D);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
        scanf("%d",&map[i][j]);
        if(map[i][j]==1)    enemy[num++]={i,j,false};
        }
    }
    DFS(0,0);
          
    printf("%d",res);
    return 0;
}


