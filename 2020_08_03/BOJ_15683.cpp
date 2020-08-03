#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct CCTV{
    int x,y,type;
};

//0은 빈칸, 6은 벽, 1~5 CCTV
int N,M,K=0;
int map[8][8]={0,};
int MIN = 99999999;
vector <int> dir;
CCTV cctv[8];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void watched(int x, int y, int dir)
{
    while(1){
        
        x += dx[dir];
        y += dy[dir];
        
        if(x <0 || y <0 || x >= N || y >= M) break;
        if(map[x][y]==6)   break;
        map[x][y]=-1;
    }
}

void solve()
{
    for(int i=0;i<K;i++){
        
        if(cctv[i].type==1){
            watched(cctv[i].x,cctv[i].y,dir[i]);
        }
        
        else if(cctv[i].type == 2){
            watched(cctv[i].x,cctv[i].y,dir[i]);
            watched(cctv[i].x,cctv[i].y,dir[i]+2);
        }
        else if(cctv[i].type == 3){
            if(dir[i] == 3){
                watched(cctv[i].x,cctv[i].y,3);
                watched(cctv[i].x,cctv[i].y,0);
            }
            else{
                for(int j=0;j<2;j++)
                    watched(cctv[i].x,cctv[i].y,dir[i]+j);
            }
        }
        
        else if(cctv[i].type == 4){
            watched(cctv[i].x,cctv[i].y,dir[i]);
            watched(cctv[i].x,cctv[i].y,(dir[i]+1)%4);
            watched(cctv[i].x,cctv[i].y,(dir[i]+2)%4);
        }
        
        else{
            for(int j=0;j<4;j++)
                watched(cctv[i].x,cctv[i].y,j);
        }
    }
    
    return ;
}

void DFS(int cnt)
{
    if(cnt == K){
        int tmp[8][8];
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                tmp[i][j]=map[i][j];
            }
        }
        solve();
        int num=0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]== 0)   num++;
                map[i][j]=tmp[i][j];

            }
        }
        if(num < MIN)   MIN = num;
        return;
    }

    if(cctv[cnt].type == 5){
        dir.push_back(0);
        DFS(cnt+1);
        dir.pop_back();
    }
    
    else if(cctv[cnt].type == 2){
        for(int i=0;i<2;i++){
            dir.push_back(i);
            DFS(cnt+1);
            dir.pop_back();
        }
    }
    else{
        for(int i=0;i<4;i++){
            dir.push_back(i);
            DFS(cnt+1);
            dir.pop_back();
        }
    }
}


int main(void)
{
    K=0;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j] > 0  && map[i][j] < 6){
                cctv[K].x=i;
                cctv[K].y=j;
                cctv[K].type=map[i][j];
                ++K;
            }
        }
    }
    
    DFS(0);
    cout << MIN;
    
    return 0;
    
}

