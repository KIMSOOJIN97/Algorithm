#include <string>
#include <vector>
#include <iostream>

#define MAX 31
using namespace std;

int bsize;
int map[MAX][MAX]={0,};
int cnt=0;

vector <int> doll;
void move(int idx)
{
    int num =0;
    
    for(int i=1;i<=bsize;i++){
        if(map[i][idx]!=0){
            num = map[i][idx];
            map[i][idx]=0;
            break;
        }
    }
    
    if(num==0)  return;
    
    int size = doll.size();
    if(size!=0 && doll[size-1] == num ){
        doll.pop_back();
        cnt+=2;
        return;
    }
    doll.push_back(num);
    
}

int solution(vector<vector<int>> board, vector<int> moves) {
    
    int answer = 0;
    int size = moves.size();
    bsize = board.size();
    
    for(int i=1;i<=bsize;i++){
        for(int j=1;j<=bsize;j++)    map[i][j] = board[i-1][j-1];
    }
            
    
    for(int i=0;i<size;i++){
        int idx= moves[i];
        move(idx);
    }
    
    answer = cnt;
    return answer;
}

