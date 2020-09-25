#include <iostream>
#include <vector>

using namespace std;

struct POS{
    int x,y;
};

POS house[100];
POS chicken[13];
int visited[13]={0,};
int N,M;

int hcnt=0;
int chi_cnt=0;//chicken count
int MIN=1e9;

void solve()
{
    int dis =0;
    
    for(int i=0;i<hcnt;i++){
        
        int hx = house[i].x;
        int hy = house[i].y;
        int len =1e9;
        
        for(int j=0;j<chi_cnt;j++)
        {
            if(!visited[j]) continue;
            
            int cx = chicken[j].x;
            int cy = chicken[j].y;
            
            int dx = hx > cx ? hx-cx : cx-hx;
            int dy = hy > cy ? hy-cy : cy-hy;
            
            if(len > dx+dy )    len=dx+dy;
        }
        
        dis+= len;
    }
    
    if(MIN > dis)   MIN=dis;
    
}
void DFS(int cnt,int idx)
{
    if(cnt == M){
        solve();
        return ;
    }
    
    for(int i=idx;i<chi_cnt;i++){
        
        visited[i]=1;
        DFS(cnt+1, i+1);
        visited[i]=0;
    }
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int num;
            scanf("%d",&num);
            if(num==1)  house[hcnt++]={i,j};
            else if(num==2) chicken[chi_cnt++]={i,j};
        }
    }
    DFS(0,0);
    printf("%d\n",MIN);
    
    return 0;
    
}

