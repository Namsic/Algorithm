#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector<int> res(4);
	res[1] = 0;
	res[2] = 1;
	res[3] = 1;
	for(int i=4; i<=n; i++)
	{
		res.push_back(res[i-1]+1);
		if(i%3 == 0 && res[i/3]+1 < res[i])
			res[i] = res[i/3]+1;
		if(i%2 == 0 && res[i/2]+1 < res[i])
			res[i] = res[i/2]+1;
	}
	cout << res[n] << '\n';

	return 0;
}
