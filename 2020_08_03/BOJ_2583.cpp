#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N,M,K;
int map[100][100]={0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(void)
{
    cin >> M >> N>> K;
    
    for(int i=0;i<K;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2 ;
        
        int col = y2 - y1;
        int row = x2 - x1;
        
        for(int j=0;j<col; j++)
        {
            for(int k=0;k<row ;k++){
                map[M-y2 + j][x1 + k]=1;
            }
        }
    }

    queue <pair<int,int>> q;
    vector <int> area;
    
    int cnt = 0 ;
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            
            if(map[i][j] == 0){
                cnt ++;
                q.push(make_pair(i,j));
                map[i][j]=1;

            }
            
            int num =0;
            
            while(!q.empty()){
                
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                num++;

                for(int k=0; k<4;k++){
                    
                    int nx =x +dx[k];
                    int ny =y +dy[k];

                    if(nx < 0 || ny < 0 || nx >= M || ny >= N)  continue;
                    if(map[nx][ny] == 0) {
                        q.push(make_pair(nx,ny));
                        map[nx][ny]=1;
                    }
                }
            }
            
            if(num != 0)    area.push_back(num);
        }
    }
    
    sort(area.begin(),area.end());
    
    cout << cnt << "\n";
    for(int i=0;i<area.size();i++)
        cout << area[i] << " ";
    
    return 0;
}

