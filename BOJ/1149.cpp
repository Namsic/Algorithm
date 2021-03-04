// 1149 - RGB거리

#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int cost[1000][3];
	
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
		if (i == 0) continue;
		cost[i][0] += min(cost[i - 1][1], cost[i - 1][2]);
		cost[i][1] += min(cost[i - 1][0], cost[i - 1][2]);
		cost[i][2] += min(cost[i - 1][0], cost[i - 1][1]);
	}

	cout << *min_element(cost[n - 1], cost[n - 1] + 3) << '\n';
}
