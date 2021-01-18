#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<stack<int>> cols(board[0].size());
    stack<int> basket;
    
    for(int j=board.size()-1; j>=0; j--)
        for(int i=0; i<board[0].size(); i++)
            if(board[j][i])
                cols[i].push(board[j][i]);
    
    for(int i=0; i<moves.size(); i++)
    {
        if(cols[moves[i]-1].empty())
            continue;
        
        int pick = cols[moves[i]-1].top();
        if(basket.empty())
            basket.push(pick);
        
        else if(basket.top() == pick)
        {
            answer += 2;
            basket.pop();
        }
        
        else
            basket.push(pick);
            
        cols[moves[i]-1].pop();
    }
    
    return answer;
}
