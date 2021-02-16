#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector<vector<int>> connect(n);
	vector<bool> visited(n);
	int answer = 0;
	queue<int> bfsq;

	while(m--)
	{
		int u, v; cin >> u >> v;
		connect[u-1].push_back(v-1);
		connect[v-1].push_back(u-1);
	}

	for(int i=0; i<n; i++)
		if(!visited[i])
		{
			answer++;
			visited[i] = 1;
			bfsq.push(i);
			while(!bfsq.empty())
			{
				vector<int> next = connect[bfsq.front()];
				for(int j=0; j<next.size(); j++)
					if(!visited[next[j]])
					{
						visited[next[j]] = 1;
						bfsq.push(next[j]);
					}
				bfsq.pop();
			}
		}

	cout << answer << '\n';

	return 0;
}
