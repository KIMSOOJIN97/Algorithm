// 10시 53분

#include <iostream>
#include <queue>

#define MAX 21
using namespace std;

struct Person{
    int sx,sy,dx,dy,score;
    bool finished=false;
};

int tx,ty,fuel;

int N,M;
int map[MAX][MAX]={0,};
Person person[MAX*MAX]={0,};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int BFS()
{
    int x,y;
    int visited[MAX][MAX]={0,};
    
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)   visited[i][j]=-1;
    }
    
    queue <pair<int ,int>> q;
    q.push({tx,ty});
    visited[tx][ty]=0;
    while(!q.empty()){
        
        x = q.front().first;
        y = q.front().second;
        
        q.pop();
        
        for(int i=0;i<4;i++){
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny])    continue;
            if(visited[nx][ny]!=-1 && visited[nx][ny] <= visited[x][y]+1)  continue;
            
            visited[nx][ny]=visited[x][y]+1;
            q.push({nx,ny});
        }
    }

    int len = MAX * MAX;
    int idx =0;
    
    for(int i=0;i<M;i++){
        
        if(person[i].finished)    continue;
        
        x = person[i].sx;
        y = person[i].sy;
        
        if(visited[x][y] == -1) continue;
        
        if(visited[x][y] < len){
            idx = i;
            len = visited[x][y];
        }
        else if( visited[x][y] == len ) {
            if ( person[idx].score > person[i].score)   idx = i;
        }
    }
    
    if(len == MAX*MAX)  return -1;
    
    fuel = fuel - len;
    
    tx =person[idx].sx;
    ty =person[idx].sy;
    
    return idx;
    
}

bool solve()
{
                
    for(int i=0;i<M;i++){
                
        int idx = BFS();
        
        if(idx == -1 )  return false;
        if(fuel <= 0)   return false;

        
        int x,y;
        int visited[MAX][MAX]={0,};
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)   visited[i][j]=-1;
        }
        queue <pair<int ,int>> q;
        q.push({tx,ty});
        visited[tx][ty]=0;
        
        while(!q.empty()){
            
            x = q.front().first;
            y = q.front().second;
            if(x == person[idx].dx && y ==person[idx].dy)   break;
            q.pop();
            
            for(int i=0;i<4;i++){
                
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny])    continue;
                if(visited[nx][ny]!=-1 && visited[nx][ny] <= visited[x][y]+1)  continue;
                
                visited[nx][ny]=visited[x][y]+1;
                q.push({nx,ny});
            }
        }
        
        int dest_x = person[idx].dx;
        int dest_y = person[idx].dy;
        
        int len = visited[dest_x][dest_y];
        if(len == -1)   return false;
        
        fuel = fuel - len;
        if(fuel < 0 )   return false;
        
        person[idx].finished = true;
        
        tx = dest_x;
        ty = dest_y;

        fuel += len*2;
    }
    
    return true;
    
}

int main(void)
{
    cin >> N >> M >> fuel;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> map[i][j];
        }
    }
    
    cin >> tx>> ty;
    
    for(int i=0;i<M;i++){
        cin >> person[i].sx >> person[i].sy >> person[i].dx >> person[i].dy;
        person[i].score = ( person[i].sx  << 10 ) + ( person[i].sy << 5 );
    }
    
    if(solve()) cout << fuel;
    else cout << "-1";
    
    return 0;
}

