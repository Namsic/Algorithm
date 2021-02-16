#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer = 0;
	int n; cin >> n;
	vector<string> grid(n);
	bool visited[100][100] = {0,};
	queue<pair<int, int>> bfsq;
	int vm[] = {-1, 1, 0, 0};
	int hm[] = {0, 0, -1, 1};

	for(int i=0; i<n; i++)
		cin >> grid[i];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(!visited[i][j])
			{
				answer++;
				char keyColor = grid[i][j];
				if(grid[i][j] == 'G') grid[i][j] = 'R';
				visited[i][j] = 1;
				bfsq.push(make_pair(i, j));
				while(!bfsq.empty())
				{
					for(int idx=0; idx<4; idx++)
					{
						int r = bfsq.front().first + vm[idx];
						int c = bfsq.front().second + hm[idx];
						if(r < 0 || r > n-1 || c < 0 || c > n-1)
							continue;
						if(visited[r][c] || grid[r][c] != keyColor)
							continue;
						if(grid[r][c] == 'G') grid[r][c] = 'R';
						visited[r][c] = 1;
						bfsq.push(make_pair(r, c));
					}
					bfsq.pop();
				}
			}
		}
	}

	cout << answer << ' ';
	answer = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			visited[i][j] = 0;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(!visited[i][j])
			{
				answer++;
				char keyColor = grid[i][j];
				visited[i][j] = 1;
				bfsq.push(make_pair(i, j));
				while(!bfsq.empty())
				{
					for(int idx=0; idx<4; idx++)
					{
						int r = bfsq.front().first + vm[idx];
						int c = bfsq.front().second + hm[idx];
						if(r < 0 || r > n-1 || c < 0 || c > n-1)
							continue;
						if(visited[r][c] || grid[r][c] != keyColor)
							continue;
						visited[r][c] = 1;
						bfsq.push(make_pair(r, c));
					}
					bfsq.pop();
				}
			}
		}
	}

	cout << answer << '\n';

	return 0;
}
