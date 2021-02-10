#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n; cin >> m >> n;

	vector<vector<int>> tomato(n, vector<int>(m));
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> tomato[i][j];

	queue<pair<int, int>> q;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(tomato[i][j] == 1)
				q.push(make_pair(i, j));

	int answer = 0;
	while(!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if(answer < tomato[r][c])
			answer = tomato[r][c];
		
		if(r > 0 && !tomato[r-1][c]) {
			tomato[r-1][c] = tomato[r][c] + 1;
			q.push(make_pair(r-1, c));
		}
		if(r < n-1 && !tomato[r+1][c]) {
			tomato[r+1][c] = tomato[r][c] + 1;
			q.push(make_pair(r+1, c));
		}
		if(c > 0 && !tomato[r][c-1]) {
			tomato[r][c-1] = tomato[r][c] + 1;
			q.push(make_pair(r, c-1));
		}
		if(c < m-1 && !tomato[r][c+1]) {
			tomato[r][c+1] = tomato[r][c] + 1;
			q.push(make_pair(r, c+1));
		}
	}

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(!tomato[i][j])
				answer = 0;
	cout << answer-1 << '\n';

	return 0;
}
