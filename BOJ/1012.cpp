#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for(int i=0; i<t; i++)
	{
		int m, n, k;
		cin >> m >> n >> k;
		bool field[50][50] = {0,};
		for(int j=0; j<k; j++)
		{
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}

		queue<pair<int, int>> queue;
		int answer = 0;
		for(int r=0; r<n; r++)
			for(int c=0; c<m; c++)
				if(field[r][c])
				{
					answer++;
					queue.push(make_pair(r, c));
					while(!queue.empty())
					{
						int tmp_r = queue.front().first;
						int tmp_c = queue.front().second;
						queue.pop();
						if(tmp_r>0 && field[tmp_r-1][tmp_c])
						{
							field[tmp_r-1][tmp_c] = 0;
							queue.push(make_pair(tmp_r-1, tmp_c));
						}
						if(tmp_r<n-1 && field[tmp_r+1][tmp_c])
						{
							field[tmp_r+1][tmp_c] = 0;
							queue.push(make_pair(tmp_r+1, tmp_c));
						}
						if(tmp_c>0 && field[tmp_r][tmp_c-1])
						{
							field[tmp_r][tmp_c-1] = 0;
							queue.push(make_pair(tmp_r, tmp_c-1));
						}
						if(tmp_c<m-1 && field[tmp_r][tmp_c+1])
						{
							field[tmp_r][tmp_c+1] = 0;
							queue.push(make_pair(tmp_r, tmp_c+1));
						}
					}
				}
		cout << answer << endl;
	}
	return 0;
}
