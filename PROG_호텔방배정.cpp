#include <string>
#include <vector>
#include <map>

using namespace std;

map <long long,long long > m;

long long Find(long long num)
{
    if(m[num]==0)
    {
        m[num]=num+1;
        return num;
    }
    else    return m[num]= Find(m[num]);
    
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(int i=0;i<room_number.size();i++){
        long long room= room_number[i];
        if(m[room] == 0)
        {
            answer.push_back(room);
            m[room]=room+1;
        }
        else
        {
            long long res = Find(room);
            answer.push_back(res);
        }
    }
    return answer;
}
