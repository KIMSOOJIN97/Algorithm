#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 10001
using namespace std;



int main(void)
{
    int N;
    int sum=0;
    int cnt =0;
    
    priority_queue <int,vector<int>,greater<int>> positive;
    priority_queue <int> negative;


    cin >> N;
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        
        if(num == 1)    sum+=1;
        else if(num == 0)   cnt++;
        else if (num > 0 )  positive.push(num);
        else negative.push(num);
    }
    
    if(positive.size()%2 != 0)  positive.push(1);
    if(negative.size()%2 != 0)  {
        if(cnt != 0)    negative.push(0);
        else    negative.push(1);
    }
    
    while(!positive.empty()){
        int num1 = positive.top();
        positive.pop();
        int num2 = positive.top();
        positive.pop();
        
        sum += num1*num2;
    }
    while(!negative.empty()){
        int num1 = negative.top();
        negative.pop();
        int num2 = negative.top();
        negative.pop();
        
        sum += num1*num2;
    }
    
    cout << sum;
    return 0;
}

