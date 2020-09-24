#include <string>
#include <vector>
#include <queue>


using namespace std;

struct Pos{
    int x,y,px,py;
}pos;

int cost[25][25] ={0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int solution(vector<vector<int>> board) {
    
    int answer = 0;
    int N = board.size();
    cout << N << endl;
    
    queue <Pos> q;
    q.push({0,0,0,0});
    
   // cost[0][0]=100;
    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int px = q.front().px;
        int py = q.front().py;
        
        q.pop();
        for(int i=0;i<4;i++){
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if( nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if( board[nx][ny] == 1) continue;
            
            int ncost = cost[x][y];
            
            if((px == nx - 1) && (py == ny-1)) ncost += 600;
            else if((px == nx - 1) && (py == ny+1)) ncost += 600;
            else if((px == nx + 1) && (py == ny+1)) ncost += 600;
            else if((px == nx + 1) && (py == ny-1)) ncost += 600;
            else    ncost += 100;
            
            
            if(cost[nx][ny] != 0 && cost[nx][ny] < ncost )  continue; //부등호 한번 생각해봐야돼
            cost[nx][ny] = ncost;
            q.push({nx,ny,x,y});
        }
    }
    answer = cost[N-1][N-1];
    return answer;
}


