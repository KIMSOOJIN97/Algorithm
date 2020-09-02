#include <string>
#include <vector>

#define MAX 20

using namespace std;

int ksize;
int lsize;
int bsize;
int board[60][60]={0,};


bool insert(int x ,int y, vector<vector<int>> key) {
    
    int tmp[60][60];
    
    for(int i=0;i<bsize ;i++){
        for(int j=0;j<bsize;j++)    tmp[i][j] = board[i][j];
    }
    
    for(int i=0;i<ksize;i++){
        for(int j=0;j<ksize;j++){
            tmp[i+x][j+y] += key[i][j];
        }
    }
    

    for(int i=0;i<lsize;i++){
        for(int j=0;j<lsize;j++){
            if(tmp[ksize + i-1][ksize+j-i]!= 1)   return false;
        }
    }
    
    return true;
}

void rotate(vector<vector<int>> &key) {
        
    vector<vector<int>> tmp(ksize, vector<int>(ksize));
 
    for (int j = ksize - 1; j >= 0; j--) {
        for (int i = 0; i < ksize; i++) {
            tmp[i][j] = key[ksize - j - 1][i];
        }
    }
 
    key = tmp;
}
 
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    bool answer = true;
    
    ksize = key.size();
    lsize = lock.size();
    bsize = 2*(ksize-1) + bsize;

    memset(board,0,sizeof(board));
    
    for(int i=0 ; i<lsize ; i++ ){
        for(int j=0 ; j <lsize;j++){
            board[ksize+i-1][ksize+j-1] = lock[i][j];
            
        }
    }
    
    for(int k=0;k<4;k++){
        
        for(int i=0 ; i< ksize+bsize-2 ; i++ ){
            for(int j=0 ; j <ksize+bsize-2;j++){
                
                answer = insert(i,j,key);
                if(answer)  return answer;
            }
        }
        rotate(key);
    }
        
    return answer;

}


