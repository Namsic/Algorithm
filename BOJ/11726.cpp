#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	if(n == 1 || n == 2)
	{
		cout << n <<endl;
		return 0;
	}
	int b2 = 1;
	int b1 = 2;

	for(int i=3; i<=n; i++)
	{
		int tmp = (b2 + b1) % 10007;
		b2 = b1;
		b1 = tmp;
	}
	cout << b1 % 10007 << endl;

	return 0;
}
