#include <iostream>

using namespace std;

int pos[4] = {0,};// 현재 말들의 위치
int blue[4] = {0,};//blue 영역에 들어갔는지 체크
int map[41]={0,};

int mv[10];
int MAX=0;


bool move(int len ,int idx)
{

    int start = pos[idx];
    int next = start;
    
    if(start ==10 || start ==20 || start == 30 || blue[idx]){
        
        if(start ==30 && blue[idx] ==0){
            next = 28;
            len--;
        }
        
        blue[idx]=1;
        for(int i=0;i<len;i++){
            if(next > 40 )  break;
            next = map[next];
        }
    }
    else    next = start + 2*len;
    
    
    for(int i=0;i<4;i++){
        if(pos[i] == next && next <= 40) {
            if( idx == i )  continue;
            if(blue[idx] == blue[i] || next == 40 ) return false;
        }
    }
    
    pos[idx] = next;
    return true;
}

void DFS(int cnt , int sum)
{
    if(cnt == 10){
        if(sum > MAX) {
            MAX = sum;
        }
        return;
    }
    
    for(int i=0;i<4;i++){
        
        if(pos[i] > 40  )   DFS(cnt+1 , sum);
        else{
            
            int idx = pos[i];
            int tmp = blue[i];

            bool res = move(mv[cnt],i);
            
            // 이미 해당 칸에 다른 말이 존재하는 경우 , 해당 조합은 무효화, 움직이지 않음
            if(res==0) {
                pos[i] = idx;
                blue[i] = tmp;
                continue;
            }
                        
            if(res && pos[i] > 40)  DFS(cnt+1 , sum);
            else if(res && pos[i]<= 40) DFS(cnt+1, sum+pos[i]);

            pos[i] = idx;
            blue[i] = tmp;

        }
    }
}

int main(void)
{
    for(int i=0;i<10;i++)   cin >> mv[i];

    for(int i=0;i<3;i++)    map[10+3*i] = 10+3*(i+1);
    for(int i=0;i<2;i++)    map[20+2*i] = 20+2*(i+1);
    for(int i=0;i<3;i++)    map[28-i] = 28-(i+1);
    for(int i=0;i<4;i++)    map[25+5*i] = 25+5*(i+1);

    map[24]=25;
    map[19]=25;
    
    DFS(0,0);
    
    cout << MAX;
    
    return 0;
}

