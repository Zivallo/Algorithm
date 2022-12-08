#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int idx[130] = { 0 };
    for (int i = 'a'; i <= 'z'; i++)idx[i] = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (idx[s[i]] == -1)
        {
            answer.push_back(idx[s[i]]);
            idx[s[i]] = i;
            continue;
        }
        answer.push_back(i - idx[s[i]]);
        idx[s[i]] = i;
    }
    return answer;
}