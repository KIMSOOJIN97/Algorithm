#include <iostream>

using namespace std;

int dx[9]={0,-1,-1,0,1,1,1,0,-1};
int dy[9]={0,0,-1,-1,-1,0,1,1,1};

int map[4][4]={0,};

struct FISH{
    int x,y,dir;
    bool die;
};

FISH fish[17];
int MAX =0;

void copy_fish(FISH tmp1[17], FISH tmp2[17])
{
    for(int i=1;i<=16;i++)  tmp2[i] = tmp1[i];
}

void copy_map(int tmp1[4][4], int tmp2[4][4])
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)    tmp2[i][j]= tmp1[i][j];
    }
}

void fish_move()
{
    for(int i=1;i<=16 ; i++){
        
        if(fish[i].die) continue;
        
        int x= fish[i].x;
        int y= fish[i].y;
        int dir= fish[i].dir;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        bool flag = false;
        int j=0;
        
        if(nx < 0 || ny <0 || nx >= 4 || ny >= 4 || map[nx][ny] == -1)
        {
        
            for(j=0;j<8;j++){
                if(dir == 8)    dir =1;
                else    dir++;
                
                nx = x+dx[dir];
                ny = y+dy[dir];
                
                if(nx >= 0 && ny >=0 && nx < 4 && ny < 4 && map[nx][ny] != -1)  break;
                if(j==7)    flag = true;
            }
        }
        
        if(flag)    continue;
        
        if(map[nx][ny]==0){ // 바꾸려고 하는 위치에 물고기가 없는 경우
            map[x][y]=0;
        }
        else{
            map[x][y]=map[nx][ny];
            fish[map[x][y]].x = x;
            fish[map[x][y]].y = y;
        }
        
        map[nx][ny]=i;
        fish[i].x = nx;
        fish[i].y = ny;
        fish[i].dir = dir;
    }
}

void DFS(int len,int sx,int sy, int sdir)
{
    
    if(MAX < len )  MAX = len;
    
    int tmp_map[4][4]={0,};
    FISH tmp_fish[17];
    
    map[sx][sy]=0;

    copy_map(map , tmp_map);
    copy_fish(fish, tmp_fish);
    
    fish_move();
    
    int nx, ny;
    

    for(int k=1;k<=3;k++)
    {
        nx = sx+ k*dx[sdir];
        ny = sy+ k*dy[sdir];
        
        if( nx < 0 || ny < 0 || nx >=4  || ny >= 4) continue;
                
        if(map[nx][ny]<=0)  continue;
        
        int idx = map[nx][ny];
        
        map[nx][ny]=-1;
        
        fish[idx].die = true;
        
        DFS(len+idx , nx, ny,fish[idx].dir);
        
        fish[idx].die = false;
        map[nx][ny]=idx;
    }
    copy_map( tmp_map, map);
    copy_fish(tmp_fish, fish);

}

int main(void)
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            
            int idx,dir;
            cin >> idx >> dir;
            
            map[i][j] = idx;
            
            fish[idx].x = i;
            fish[idx].y = j;
            fish[idx].dir = dir;
            fish[idx].die = false;
        }
    }
    
    int idx = map[0][0];

    fish[idx].die = true;
    
    map[0][0]=-1;
    
    DFS(idx,0,0,fish[idx].dir);
    
    cout << MAX;
    
    return 0;
}

