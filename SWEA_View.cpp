#include <iostream>

using namespace std;

int N;
int map[10000]={0,};



void solve()
{
    int cnt =0;
    int h1,h2;
    
    for(int i=2;i<N-2;i++){
        h1 = map[i-1] > map[i-2] ? map[i-1] : map[i-2];
        h2 = map[i+1] > map[i+2] ? map[i+1] : map[i+2];
        
        int MAX = h1 > h2 ? h1 : h2;
        if(MAX < map[i])    cnt += map[i]- MAX;
    
    }
    
    cout << cnt << "\n";
    return ;
}

int main(void)
{
    for(int i=0;i<10;i++){
        
        cin >> N;
        
        for(int j=0;j<N;j++){
            
            cin >> map[j];
            cout << map[j];
        }
        cout << "#" << i+1 << " ";
        solve();
        
    }
    
    return 0;
    
}

