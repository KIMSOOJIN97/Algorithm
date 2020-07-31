#include <iostream>
#include <vector>

using namespace std;

int N;
int num[11]={0,};
int oper[4]={0,}; // 순서대로 덧셈, 뺄셈, 곱셈, 나눗셈

int MIN = 999999999;
int MAX = -999999999;

vector <int> v;


void calc()
{
    int res=num[0];
    
    for(int i=0;i<N-1;i++){
        
        if( v[i] == 0)  res += num[i+1];
        else if (v[i] == 1) res -= num[i+1];
        else if (v[i] == 2) res *= num[i+1];
        else if( v[i] == 3)  res = res/num[i+1];
    
    }
    if(res > MAX )  MAX = res;
    if(res < MIN )  MIN = res;
}

void DFS(int cnt )
{
    if(cnt == N-1 ){
        calc();
        return;
    }
    
    for(int i=0;i<4;i++){
        if(oper[i] != 0 )
        {
            v.push_back(i);
            oper[i]--;
            DFS(cnt+1);
            oper[i]++;
            v.pop_back();
        }
    }
}

int main(void)
{
    cin >> N;
    
    for (int i=0; i<N ;i++)
        cin >> num[i];
    
    for(int i=0;i<4;i++)
        cin >> oper[i];
    
    DFS(0);
    cout << MAX << "\n";
    cout << MIN;
    
    return 0;
}

