
#include <iostream>

#define MAX 101

using namespace std;

struct FISH{
    int x,y,s,d,z;
    bool die;
};

int R,C,M;
int score=0;
int map[MAX][MAX]={0,};
FISH fish[MAX*MAX];
int idx =0;

int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,1,-1};


void move()
{
    
    int visited[MAX][MAX]={0,};
    
    for(int i=1;i<=M;i++){
        
        if(fish[i].die) continue;

        int dir = fish[i].d;
        int x = fish[i].x;
        int y = fish[i].y;
        int s = fish[i].s;
        int nx;
        int ny;
        
        while(1){
            
            nx = x+ dx[dir] * s;
            ny = y+ dy[dir] * s;
            
            if( nx >=1 && ny >=1 && nx <= R && ny <= C) break;
            else if ( dir == 1 )    {
                s = s - (x-1);
                x = 1;
                dir = 2;
                
            }
            else if ( dir == 2 )    {
                s = s - (R-x);
                x = R;
                dir =1;
            }
            else if ( dir == 3 )    {
                s = s - (C-y);
                y = C;
                dir = 4;
            }
            else if ( dir == 4 )    {
                s = s- (y-1);
                y =1;
                dir= 3;
            }
            fish[i].d = dir;
            
        }
        
        fish[i].x = nx;
        fish[i].y = ny;
        
        if(visited[nx][ny] != 0)
        {
            int num = visited[nx][ny];
            
            if( fish[i].z < fish[num].z)    fish[i].die = true;
            else{
                visited[nx][ny]=i;
                fish[num].die = true;
            }
        }
        else    visited[nx][ny]=i;
    }
    
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++)   map[i][j]= visited[i][j];
    }
    
}


void fishing()
{
    for(int i=1;i<=R;i++)
    {
        if(map[i][idx] != 0){
            
            int num = map[i][idx];
            map[i][idx]=0;
            score += fish[num].z;
            fish[num].die = true;
            return ;
        }
    }
}

int main(void)
{
    
    cin >> R >> C >> M;
    
    for(int i=1;i<=M;i++){
        cin >> fish[i].x >> fish[i].y >> fish[i].s >> fish[i].d >> fish[i].z;
        map[fish[i].x][fish[i].y]=i;
        fish[i].die = false;
    }
    
    for(int i=1;i<=C;i++){
        idx++; // 낚시왕 이동
        fishing();
        move();
    }

    cout << score ;
    
    return 0;
    
}

#include <iostream>

#define MAX 101

using namespace std;

struct FISH{
    int x,y,s,d,z;
    bool die;
};

int R,C,M;
int score=0;
int map[MAX][MAX]={0,};
FISH fish[MAX*MAX];
int idx =0;

int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,1,-1};


void move()
{
    
    int visited[MAX][MAX]={0,};
    
    for(int i=1;i<=M;i++){
        
        if(fish[i].die) continue;

        int dir = fish[i].d;
        int x = fish[i].x;
        int y = fish[i].y;
        int s = fish[i].s;
        int nx;
        int ny;
        
        while(1){
            
            nx = x+ dx[dir] * s;
            ny = y+ dy[dir] * s;
            
            if( nx >=1 && ny >=1 && nx <= R && ny <= C) break;
            else if ( dir == 1 )    {
                s = s - (x-1);
                x = 1;
                dir = 2;
                
            }
            else if ( dir == 2 )    {
                s = s - (R-x);
                x = R;
                dir =1;
            }
            else if ( dir == 3 )    {
                s = s - (C-y);
                y = C;
                dir = 4;
            }
            else if ( dir == 4 )    {
                s = s- (y-1);
                y =1;
                dir= 3;
            }
            fish[i].d = dir;
            
        }
        
        fish[i].x = nx;
        fish[i].y = ny;
        
        if(visited[nx][ny] != 0)
        {
            int num = visited[nx][ny];
            
            if( fish[i].z < fish[num].z)    fish[i].die = true;
            else{
                visited[nx][ny]=i;
                fish[num].die = true;
            }
        }
        else    visited[nx][ny]=i;
    }
    
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++)   map[i][j]= visited[i][j];
    }
    
}


void fishing()
{
    for(int i=1;i<=R;i++)
    {
        if(map[i][idx] != 0){
            
            int num = map[i][idx];
            map[i][idx]=0;
            score += fish[num].z;
            fish[num].die = true;
            return ;
        }
    }
}

int main(void)
{
    
    cin >> R >> C >> M;
    
    for(int i=1;i<=M;i++){
        cin >> fish[i].x >> fish[i].y >> fish[i].s >> fish[i].d >> fish[i].z;
        map[fish[i].x][fish[i].y]=i;
        fish[i].die = false;
    }
    
    for(int i=1;i<=C;i++){
        idx++; // 낚시왕 이동
        fishing();
        move();
    }

    cout << score ;
    
    return 0;
    
}

