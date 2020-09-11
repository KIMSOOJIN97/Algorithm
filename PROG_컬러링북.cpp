#include <vector>
#include <queue>

#define MAX 100

using namespace std;

struct pos{
    int x,y;
};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    int visited[MAX][MAX]={0,};
    int cnt=0;
    queue <pos> q;
        
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int num =0;
            
            if(visited[i][j]==0 && picture[i][j] !=0 ){
                q.push({i,j});
                cnt++;
            }
            
            while(!q.empty()){
                num++;
                int x = q.front().x;
                int y = q.front().y;
                
                visited[x][y]=cnt;
                q.pop();
                
                for(int k=0;k<4;k++){
                    
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    
                    if( nx < 0 || ny < 0 || nx >=m || ny >= n || visited[nx][ny] || !picture[nx][ny] )   continue;
                    if( picture[nx][ny] != picture[x][y])   continue;
                    
                    q.push({nx,ny});
                    visited[nx][ny] = cnt;
                }
            }
            
            if(num !=0){
                if(max_size_of_one_area < num)  max_size_of_one_area = num;
            }
        }
    }
    
    
    number_of_area = cnt;
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

