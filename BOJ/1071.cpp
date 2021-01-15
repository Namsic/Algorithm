#include <iostream>
#include <vector>

using namespace std;

vector<int> strangeSort(vector<int>& data);

int main()
{
	// declare
	int n;
	int res = 0;
	
	// input
	cin >> n;
	vector<int> data(1001);
	for(int i=0; i<n; i++)
	{
		int tmp;
		cin >> tmp;
		data[tmp]++;
	}

	// preprocess

	// solve
	vector<int> result = strangeSort(data);

	// output
	cout << result[0];
	for(int i=1; i<n; i++)
		cout << " " << result[i];

	int t;
	cin >> t;
	return 0;
}

vector<int> strangeSort(vector<int>& data)
{
	vector<int> res;

	for(int i=0; i<1001; i++)
	{
		if(data[i] == 0) continue;

		if(res.size() == 0)
		{
			for(int j=0; j<data[i]; j++)
				res.push_back(i);
			continue;
		}
		
		if(res.back() == i-1)
			for(int j=i+1; j<1001; j++)
				if(data[j] > 0)
				{
					res.push_back(j);
					data[j]--;
					break;
				}
		for(int j=0; j<data[i]; j++)
			res.push_back(i);
	}

	for(int i=res.size()-1; i>0; i--)
		if(res[i]-1 == res[i-1])
		{
			int tmp = res[i];
			res[i] = res[i-1];
			res[i-1] = tmp;
			i = res.size();
		}
	return res;
}