#include <iostream>
#include <vector>
using namespace std;

int N, M, target;
int nodeSize, idx;
int maxidx, minidx;
vector<vector<int>> alist(100001);
vector<vector<int>> r_alist(100001);

int getMinIdx(int now, int lev)
{
    if (alist[now].size() == 0)
    {
        return lev;
    }
    for (int i = 0; i < alist[now].size(); i++)
    {
        int next = alist[now][i];
        getMinIdx(next, lev + 1);
    }
}
int getMaxIdx(int now, int lev)
{
    if (r_alist[now].size() == 0)
    {
        return lev;
    }
    for (int i = 0; i < r_alist[now].size(); i++)
    {
        int next = r_alist[now][i];
        getMinIdx(next, lev + 1);
    }
}

int main()
{
    cin >> N >> M >> target;
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        alist[from].push_back(to);
        r_alist[to].push_back(to);
    }
    cout << 1 + getMaxIdx(target, 0) << '\n';
    cout << N - getMinIdx(target, 0) << '\n';

    return 0;
}