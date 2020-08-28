  
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100

using namespace std;

int r,c,k;
int MIN = 0;

int row=3;
int col=3;

int arr[MAX][MAX]={0,};

void row_calc()
{
    vector <pair<int,int>> v[MAX];

    for(int i=0;i<row;i++){
        int num[MAX+1]={0,};

        for(int j=0;j<col;j++)
        {
            num[arr[i][j]]++;
        }
        for(int j=1;j<=MAX;j++) {
            if(num[j] > 0)  v[i].push_back({num[j],j});
        }
        
        sort(v[i].begin(),v[i].end());
        
        for(int j=0;j<col;j++)  arr[i][j]=0;
        
    }

    for(int i=0;i<row;i++){
        int idx =0;
        for(int j=0;j<v[i].size();j++){
            
            arr[i][idx++] = v[i][j].second;
            if(idx == MAX ) break;
            arr[i][idx++] = v[i][j].first;
            if(idx==MAX)    break;
            
        }
        
        col = max(col,idx);
        
    }
}

void col_calc()
{
    vector <pair<int,int>> v[MAX];

    for(int i=0;i<col;i++){
        int num[MAX+1]={0,};

        for(int j=0;j<row;j++)
        {
            num[arr[j][i]]++;
        }
        for(int j=1;j<=MAX;j++){
            if(num[j] >0)   v[i].push_back({num[j],j});
        }
        sort(v[i].begin(),v[i].end());
        
    }
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            arr[i][j]=0;
    }
    
    for(int i=0;i<col;i++){
        int idx =0;
        for(int j=0;j<v[i].size();j++){
            
            arr[idx++][i] = v[i][j].second;
            if(idx == MAX ) break;
            arr[idx++][i] = v[i][j].first;
            if(idx==MAX)    break;
            
        }
        
        row = max(row,idx);
    }
}

int main(void)
{
    cin >> r>> c >> k;
    
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cin >> arr[i][j];
    }
    
    while( arr[r-1][c-1] != k){
        if(MIN >= 101)  break;
        
        if( row >= col) row_calc();
        else    col_calc();
        
        MIN++;
    }
    
    if(MIN == 101)  cout << "-1";
    else    cout << MIN ;
    
    return 0;
    
}
