#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
char map[4][8]={0,};
vector <int> num;

/*
 5
 12 10
 1B3B3B81F75E
 16 2
 F53586D76286B2D8
// 테스트 케이스의 개수 T = 5
 // 1번째 테스트 케이스, N=12, K=10
 // N개의 숫자
 // 2번째 테스트 케이스, N=16, K=2
 // N개의 숫자
 
 */

bool comp(int a, int b)
{
    return a>b;
}
void calc()
{
    int idx = N/4-1; // 2~8

    for(int i=0;i<4;i++){
     
        int sum=0;
        int tmp = 1;
        
        
        for(int j=idx;j>=0;j--){
            
            if(48<=map[i][j] && map[i][j] <=57){
                sum += tmp * (map[i][j]-48);
            }
            else    sum += tmp * (map[i][j] - 55);
            
            tmp *=16;
            
        }
        
        if(find(num.begin(),num.end(), sum) == num.end())   num.push_back(sum);
    }
}
void rotate()
{
    int idx = N/4-1; // 2~8
    char tmp[4]={0,};
    
    for(int i=0;i<4;i++)    tmp[i] = map[i][idx];
    
    while(idx>0){
        
        for(int i=0;i<4;i++){
            map[i][idx] = map[i][idx-1];
        }
        idx--;
    }
    
    for(int i=0;i<3;i++)    map[i+1][0] = tmp[i];
    map[0][0] = tmp[3];
    
}

void init()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++)    map[i][j] = {0,};
    }
    num.clear();
    
}

int main(void)
{
    
    int T;
    cin >> T;
    
    for(int k=0;k<T;k++){
        init();
        
        cin >> N >> K;
        for(int i=0;i<4;i++){
            for(int j=0;j<N/4;j++){
                cin >> map[i][j];
            }
        }
        
        for(int i=0;i<N/4;i++){
            rotate();
            calc();
        }
        
        sort(num.begin(), num.end(),comp);
        cout << "#" << k+1 << " " << num[K-1]<<"\n";
    }
    return 0;
}

