#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> rank;
    for (int i = 0; i < score.size(); i++)
    {
        rank.push_back(score[i]);
        sort(rank.begin(), rank.end(), greater<int>());
        if (rank.size() > k)rank.pop_back();
        answer.push_back(rank.back());
    }
    return answer;
}