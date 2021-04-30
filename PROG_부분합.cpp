#include <iostream>
#include <vector>
#define MAX 100000

using namespace std;

int N,S;
int res = 1e9;
int sequence[MAX] = { 0, };

int main(void)
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)		cin >> sequence[i];

	int start = 0;
	int end = 0;
	int total = sequence[0];

	while (end < N) {
		if (total < S)
		{
			end++;
			total += sequence[end];
		}
		else {
			if (start == end)
			{
				cout << "1";
				return 0;
			}
			int len = end - start + 1;
			if (len < res)		res = len;
			total -= sequence[start];
			start++;
		}
	}
	if (res == 1e9)	cout << "0";
	else    cout << res;
	return 0;
}

