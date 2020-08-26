#include <iostream>
using namespace std;

int flag[4] ={0,};
int pos[4]={0,}; // position of horse
int mv[10]={0,};

int map[40]={0,};
int MAX =0;

bool move(int idx, int len)
{
    int start = pos[idx];
    int next = start;
    
    if(start > 40 ) return true;
    
    if(start ==10 || start ==20 || start ==30 || flag[idx])
    {
        if(start == 30 && flag[idx]==0){
            next = 28;
            len--;
        }
        
        flag[idx] = 1;

        for(int i=0;i<len;i++){
            if(next >= 40){
                next = 41;
                break;
            }
            next = map[next];
        }
    }
    else    next += 2 * len;
    
    
    for(int i=0;i<4;i++){
        if(pos[i] == next && next <= 40){
            if(flag[i] == flag[idx]){
                pos[idx] = next;
                return false;


            }
        }
    }
    
    pos[idx] = next;
    return true;
    
}


void DFS(int cnt , int sum)
{
    if(cnt == 10){
        if(MAX < sum)   MAX = sum;
        return ;
    }
    
    for(int i=0;i<4;i++){
        
        int tmp1 = pos[i];
        int tmp2 = flag[i];
        
        int res1 = move(i,mv[cnt]);
            
        int res = pos[i];
        
        if(res1 == false)    res = sum;
        else if(res > 40)   res = sum;
        else    res +=sum;
        
        DFS(cnt+1,res);
        
        pos[i] = tmp1;
        flag[i] = tmp2;
        
    }
}

int main(void)
{
    for(int i=0;i<10;i++)   cin >> mv[i];
    for(int i=0;i<3;i++)    map[10+3*i] = 10 + 3*(i+1);
    for(int i=0;i<2;i++)    map[20+2*i] = 20 + 2*(i+1);
    for(int i=0;i<3;i++)    map[28-i] = 28  - (i+1);
    for(int i=0;i<3;i++)    map[25+5*i] = 25 + 5*(i+1);

    map[24] =25;
    map[19] =25;
    
    DFS(0,0);

    cout << MAX;
    return 0;
}

