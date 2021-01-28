#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> x(n);

	for(int i=0; i<n; i++)
		cin >> x[i];
	vector<int> xx(x);

	sort(xx.begin(), xx.end());
	xx.erase(unique(xx.begin(), xx.end()), xx.end());

	for(int i=0; i<n; i++)
	{
		int res = lower_bound(xx.begin(), xx.end(), x[i]) - xx.begin();
		cout << res << " ";
	}

	return 0;
}
