#include <iostream>

using namespace std;

int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	
	int length = 1;
	for(int i=0; i<n; i++)
		length *= 2;

	int left = 0;
	int right = length * length - 1;

	while(left != right)
	{
		if(r < length / 2 && c < length / 2)
			right -= length * length / 4 * 3;
		else if(r < length / 2)
		{
			left += length * length / 4;
			right -= length * length / 2;
		}
		else if(c < length / 2)
		{
			left += length * length / 2;
			right -= length * length / 4;
		}
		else
			left += length * length / 4 * 3;
		length /= 2;
		r %= length;
		c %= length;
	}
	cout << left << endl;
	return 0;
}
