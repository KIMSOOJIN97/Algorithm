#include <string>
#include <vector>

#define MAX 30

using namespace std;

int map[MAX][MAX]={0,};
int N=0;
int cnt =0;

vector <int> v;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    int answer = 0;
    
    N = board.size();
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)    map[i][j]=board[i][j];
    }
    
    for(int i=0;i<moves.size();i++)
    {
        int idx= moves[i]-1;
        
        for(int j=0;j<N;j++){
            if(map[j][idx] !=0 )    
            {
                int num = map[j][idx];
                map[j][idx]=0;
                
                int vsize= v.size();
                
                if(vsize > 0 && v[vsize-1] == num){
                    v.pop_back();
                    cnt+=2;
                }
                else    v.push_back(num);
                break;
            }
                
        }
    }
    
    answer = cnt;
    return answer;
    
}
