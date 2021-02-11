#include<string>
#include<stack>

using namespace std;

int solution(string s)
{
    stack<char> st;
    for(char c : s)
        st.empty() || st.top() != c ? st.push(c) : st.pop();
    return st.empty();
}
