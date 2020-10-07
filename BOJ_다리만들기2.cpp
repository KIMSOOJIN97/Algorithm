#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 11

using namespace std;

int N,M;
int map[MAX][MAX]={0,};
int A[7][7]={0,};// 도시간의 연결 정보
int MIN = 1e9;
int cnt =0;

int dx[4] ={-1,0,1,0};
int dy[4] ={0,1,0,-1};

int parent[7];

struct Node{
    int start;
    int end;
};
Node node [36];
vector <pair<int,int>> len;
int link=0;

struct pos{
    int x,y;
};

int Find(int idx)
{
    if(idx == parent[idx])  return idx;
    else{
        parent[idx]= Find(parent[idx]);
        return parent[idx];
    }
}

void Union(int idx1 , int idx2)
{
    idx1 = Find(idx1);
    idx2 = Find(idx2);
    
    if(idx1 != idx2)    parent[idx2]=idx1;
}

int Kruskal()
{
    int ans =0;
    sort(len.begin(),len.end());
    
    for(int i=0;i<link;i++)
    {
        int idx= len[i].second;
        int dis = len[i].first;
        
        if(Find(node[idx].start) ==Find(node[idx].end ))    continue;
        ans += dis;
        Union(node[idx].start,node[idx].end);
    }
    
    int idx = Find(1);
    
    for(int i=2;i<=cnt;i++)
        if(idx !=Find(i))   return -1;
    
    return ans;
}


void DISTANCE() { //섬끼리 최단 거리 구하기
   int i, j, count, a, b;
   for (i = 0; i < N; i++) {
      a = -1;
      for (j = 0; j < M - 1; j++) {
         if (map[i][j] > 0 && map[i][j + 1] == 0) {
            a = map[i][j];
            count = 0;
         }
         if (map[i][j] == 0) count++;
         if (a != -1 && map[i][j] == 0 && map[i][j + 1] > 0) {
            b = map[i][j + 1];
            if (a != b && count > 1 && (A[a][b] == 0 || A[a][b] > count)) {
               A[a][b] = count;
               A[b][a] = count;
            }
         }
      }
   }
///////////////////////////가로/////////////////
   for (i = 0; i < M; i++) {
      a = -1;
      for (j = 0; j < N - 1; j++) {
         if (map[j][i] > 0 && map[j + 1][i] == 0) {
            a = map[j][i];
            count = 0;
         }
         if (map[j][i] == 0) count++;
         if (a != -1 && map[j][i] == 0 && map[j + 1][i] > 0) {
            b = map[j + 1][i];
            if (a != b && count > 1 && (A[a][b] == 0 || A[a][b] > count)) {
               A[a][b] = count;
               A[b][a] = count;
            }
         }
      }
   }

    for(int i=1;i<cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            if(A[i][j] != 0)    {
                node[link].start = i;
                node[link].end = j;
                len.push_back({A[i][j], link});
                link++;
            }
        }
    }
}
void BFS()
{
    int visited[MAX][MAX]={0,};
    
    queue <pos> q;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            
            if(visited[i][j]==0 && map[i][j] !=0 ){
                q.push({i,j});
                cnt++;
            }
            
            while(!q.empty()){
                
                int x = q.front().x;
                int y = q.front().y;
                
                map[x][y] = cnt;
                q.pop();
                
                for(int k=0;k<4;k++){
                    
                    int nx = x +dx[k];
                    int ny = y+ dy[k];
                    
                    if(nx < 0 || ny <0 || nx >= N || ny >= M || visited[nx][ny]!=0 )  continue;
                    if(map[nx][ny] ==0) continue;
                    q.push({nx,ny});
                    visited[nx][ny]=1;
                }
            }
        }
    }
}

int main(void)
{
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)    scanf("%d",&map[i][j]);
    }
    for(int i=1;i<7;i++)    parent[i] = i;
    
    BFS();
    DISTANCE();
    cout << Kruskal();

    return 0;
}

