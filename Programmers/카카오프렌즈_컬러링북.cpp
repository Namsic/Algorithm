#include <vector>
#include <queue>
#include <utility>

using namespace std;

void addQueue(queue<pair<int, int>>& queue, 
               vector<vector<int>>& picture, 
               int r, int c, int flag)
{
    if( r < 0 || r >= picture.size() ||
        c < 0 || c >= picture[0].size())
        return;
    if(picture[r][c] != flag)
        return;
    
    picture[r][c] = -1;
    queue.push(make_pair(r, c));
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    queue<pair<int, int>> queue;
    
    for(int r=0; r<picture.size(); r++)
        for(int c=0; c<picture[0].size(); c++)
        {
            if(picture[r][c] < 1)
                continue;
            number_of_area++;
            int size_of_area = 0;
            int area_num = picture[r][c];
            
            queue.push(make_pair(r, c));
            picture[r][c] = -1;
            while(!queue.empty())
            {
                int tmp_r = queue.front().first;
                int tmp_c = queue.front().second;
                size_of_area++;
                queue.pop();
                addQueue(queue, picture, tmp_r, tmp_c-1, area_num);
                addQueue(queue, picture, tmp_r, tmp_c+1, area_num);
                addQueue(queue, picture, tmp_r-1, tmp_c, area_num);
                addQueue(queue, picture, tmp_r+1, tmp_c, area_num);
            }
            if(size_of_area > max_size_of_one_area)
                max_size_of_one_area = size_of_area;
        }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
