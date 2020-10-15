#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000

using namespace std;

int N,H;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int res = 1e9;
    cin >> N >> H;
    
    vector <int> up(N/2);
    vector <int> down(N/2);
    
    for(int i=0;i<N/2;i++)  cin >> down[i]>> up[i];

    int total=1;
       
    sort(down.begin(),down.end());
    sort(up.begin(),up.end());
    
    for(int i=1;i<=H;i++)
    {
        int cnt = down.size() - (lower_bound(down.begin(), down.end(),i)-down.begin());
        cnt += up.size() - (upper_bound(up.begin(), up.end(),H-i)-up.begin());
        
        
        if(res == cnt ) total++;
        else if(res > cnt ){
            res = cnt;
            total=1;
        }

    }

    cout << res << " " << total;
    return 0;
    
}

