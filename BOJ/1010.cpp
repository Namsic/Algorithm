#include <iostream>

using namespace std;

int main()
{
	int t, n ,m;
	cin >> t;

	for(int i=0; i<t; i++)
	{
		int res = 1;
		cin >> n >> m;
		for(int j=0; j<n; j++)
		{
			res *= m-j;
			res /= j+1;
		}
		cout << res << endl;
	}
	int tmp;
	cin >> tmp;
	return 0;
}
