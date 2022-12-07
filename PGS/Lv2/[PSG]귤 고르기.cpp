#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cnt[10000001] = { 0 };
bool cmp(int t, int v)
{
    return cnt[t] < cnt[v];
}
int solution(int k, vector<int> tangerine) {
    int answer = 21e8;
    vector<int> tmp;
    for (int i = 0; i < tangerine.size(); i++) {
        if (cnt[tangerine[i]] == 0) tmp.push_back(tangerine[i]);
        cnt[tangerine[i]]++;
    }
    sort(tmp.begin(), tmp.end(), cmp);
    int l = -1, r = 0, sum = cnt[tmp[0]], c = 1;
    while (r <= tmp.size())
    {
        if (sum >= k)
        {
            if (answer > c)answer = c;
            l++;
            sum -= cnt[tmp[l]];
            c--;
        }
        else
        {
            r++;
            if (r >= tmp.size()) break;
            sum += cnt[tmp[r]];
            c++;
        }
        if (answer == 1)break;
    }
    return answer;
}