#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[] = {1, 2, 4, 7, 13, 24, 44, 81, 149, 274};
	
	int t; cin >> t;
	for(int i=0; i<t; i++)
	{
		int n; cin >> n;
		cout << arr[n-1] << '\n';
	}

	return 0;
}
