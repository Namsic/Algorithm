#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int m; cin >> m;

	vector<int> connect[101];
	for(int i=0; i<m; i++)
	{
		int pc1, pc2; cin >> pc1 >> pc2;
		connect[pc1].push_back(pc2);
		connect[pc2].push_back(pc1);
	}

	bool virus[101] = {0,};
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		if(!virus[q.front()])
		{
			virus[q.front()] = 1;
			for(int i=0; i<connect[q.front()].size(); i++)
				q.push(connect[q.front()][i]);
		}
		q.pop();
	}

	int answer = 0;
	for(int i=2; i<=n; i++)
		answer += virus[i];
	cout << answer << '\n';

	return 0;
}
