#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> tri(n, vector<int>(n));
    
    int row = -1, col = 0;
    int num = 1;
    for(int i=n; i>0; i--)
        for(int j=0; j<i; j++)
        {
            switch((n-i)%3)
            {
                case 0:
                    row++;
                    break;
                case 1:
                    col++;
                    break;
                case 2:
                    row--;
                    col--;
                    break;
            }
            tri[row][col] = num++;
        }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<=i; j++)
            answer.push_back(tri[i][j]);
    return answer;
}
