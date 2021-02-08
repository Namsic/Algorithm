#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;

	vector<string> int_str;
	map<string, int> str_int;

	for(int i=0; i<n; i++)
	{
		string tmp; cin >> tmp;
		int_str.push_back(tmp);
		str_int.insert(make_pair(tmp, i));
	}
	for(int i=0; i<m; i++)
	{
		string tmp; cin >> tmp;
		try
		{
			int idx = stoi(tmp);
			cout << int_str[idx-1] << '\n';
		} catch(exception e)
		{
			cout << str_int.find(tmp)->second+1 << '\n';
		}
	}
	
	return 0;
}
