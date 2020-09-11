#include <iostream>
#include <map>

using namespace std;

int parent[200000]={0,};
int number[200000]={0,};

char fr1[21],fr2[21];

int find(int idx)
{
    if(idx== parent[idx])   return idx;
    else    return  parent[idx]=find(parent[idx]);
}


int unit(int idx1, int idx2)
{
    idx1 = find(idx1);
    idx2 = find(idx2);
    
    if(idx1 != idx2 )
    {
        parent[idx1] = idx2;
        
        number[idx2] += number[idx1];
        number[idx1] = 1;
    }
    
    return number[idx2];
    
}

int main(void)
{
    int T;
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        int F;
        int count =0;
        map <string , int> fr;

        scanf("%d",&F);
        
        for(int j=0;j<2*F;j++){
            parent[j]=j;
            number[j]=1;
        }
        
        for(int j=0;j<F;j++){
            scanf("%s %s",fr1,fr2);
            
            if(fr.count(fr1)==0)   fr[fr1]=count++;
            int idx1= fr[fr1];
            if(fr.count(fr2)==0)   fr[fr2]=count++;
            int idx2= fr[fr2];
            
            printf("%d\n", unit(idx1,idx2));
                        
        }
    }
    return 0;
    
}

