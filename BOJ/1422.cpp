#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comapreU(string s1, string s2);

int main()
{
	// declare
	int k, n;
	vector<string> data;
	string mem = "";
	
	// input
	cin >> k >> n;
	for(int i=0; i<k; i++)
	{
		string tmp;
		cin >> tmp;
		data.push_back(tmp);

		if( tmp.length() > mem.length() ||
			(tmp.length() == mem.length() && comapreU(mem, tmp)))
			mem = tmp;
	}

	// preprocess
	// solve
	sort(data.begin(), data.end(), comapreU);

	for(int j=0; j<k; j++)
		if(data[j] == mem)
		{
			for(int i=0; i<n-k; i++)
				data.insert(data.begin() + j, mem);
			break;
		}

	// output
	for(int i=n-1; i>=0; i--)
		cout << data[i];

	return 0;
}

bool comapreU(string s1, string s2)
{
	return s1+s2 < s2+s1;
}