#include <iostream>
#include <vector>


using namespace std;

/*
차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다.
 */

int oper[4]={0,};
int num[11]={0,};

int N;

int MIN = 999999999;
int MAX = -999999999;

vector <int> v;

void calc()
{
    int sum = num[0];
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==0)    sum+=num[i+1];
        else if (v[i]==1)  sum-=num[i+1];
        else if(v[i]==2)   sum*=num[i+1];
        else    sum/=num[i+1];
    }
    
    if(sum > MAX)   MAX = sum;
    if(sum < MIN)   MIN = sum;

}

void DFS(int cnt)
{
    if(cnt == N-1){
        calc();
        return;
    }
    
    for(int i=0;i<4;i++){
        
        if(oper[i]!=0){
            
            oper[i]--;
            v.push_back(i);
            DFS(cnt+1);
            v.pop_back();
            oper[i]++;
            
        }
    }
}

int main(void)
{
    cin >> N;
    for(int i=0;i<N;i++)    cin >> num[i];
    for(int i=0;i<4;i++)    cin >> oper[i];
    
    DFS(0);
    
    cout << MAX << "\n" << MIN ;
    
    return 0;
}

