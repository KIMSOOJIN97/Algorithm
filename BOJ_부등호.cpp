#include <iostream>
#include <vector>
#include <string>

using namespace std;

int K;
int visited[10]={0,};
char oper[10];

string _min="";
string _max="";

int MIN=1e9;
int MAX=-1e9;

vector <int> v;


void solve()
{
    string str1="";
    
    for(int i=0;i<K;i++){
            
        char ch1 = oper[i];
        
        int num1 = v[i];
        int num2 = v[i+1];
        
        if(ch1 == '<'){
            if(num1 > num2) return;
        }
        else{
            if(num1 < num2 )    return;
        }
        
        if(i==0) str1 += to_string(num1);
        str1 += to_string(num2);
        
    }
     
    int res = stoi(str1);
    
    if(MIN > res){
        MIN = res;
        _min = str1;
    }
    if(MAX < res ){
        MAX = res;
        _max= str1;
    }
}

void DFS(int cnt)
{
    if(cnt == K+1)  {
        solve();
        return ;
    }
    
    for(int i=0;i<10;i++){
        if(visited[i]==0){
            visited[i] = 1;
            v.push_back(i);
            DFS(cnt+1);
            v.pop_back();
            visited[i]=0;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    
    cin >> K;
    for(int i=0;i<K;i++)    cin >> oper[i];
    
    DFS(0);
    
    cout << _max <<"\n";
    cout << _min;
    
    return 0;
    
}

