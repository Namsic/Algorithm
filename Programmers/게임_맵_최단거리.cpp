#include<vector>
#include<queue>
#include<utility>

using namespace std;

int solution(vector<vector<int> > maps)
{
    maps[0][0] = 2;
    queue<pair<int, int>> path;
    path.push(make_pair(0, 0));
    while(!path.empty())
    {
        if(maps[maps.size()-1][maps[0].size()-1] != 1)
            return maps[maps.size()-1][maps[0].size()-1]-1;
        
        int curRow = path.front().first,
            curCol = path.front().second;
        if(curRow > 0 && maps[curRow-1][curCol] == 1)
        {
            maps[curRow-1][curCol] = maps[curRow][curCol]+1;
            path.push(make_pair(curRow-1, curCol));
        }
        if(curRow < maps.size()-1 && maps[curRow+1][curCol] == 1)
        {
            maps[curRow+1][curCol] = maps[curRow][curCol]+1;
            path.push(make_pair(curRow+1, curCol));
        }
        if(curCol > 0 && maps[curRow][curCol-1] == 1)
        {
            maps[curRow][curCol-1] = maps[curRow][curCol]+1;
            path.push(make_pair(curRow, curCol-1));
        }
        if(curCol < maps[0].size()-1 && maps[curRow][curCol+1] == 1)
        {
            maps[curRow][curCol+1] = maps[curRow][curCol]+1;
            path.push(make_pair(curRow, curCol+1));
        }
        path.pop();
    }
    return -1;
}
