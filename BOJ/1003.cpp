#include <iostream>

using namespace std;

int main()
{
	int callZero[41], callOne[41];
	callZero[0] = 1;
	callOne[0] = 0;
	callZero[1] = 0;
	callOne[1] = 1;
	for(int i=2; i<41; i++)
	{
		callZero[i] = callZero[i-1] + callZero[i-2];
		callOne[i] = callOne[i-1] + callOne[i-2];
	}

	int t;
	cin >> t;

	for(int i=0; i<t; i++)
	{
		int n;
		cin >> n;
		cout << callZero[n] << " " << callOne[n] << endl;
	}

	return 0;
}
