#include <iostream>
#include <vector>
using namespace std;

int N, M, target;
int upSize, downSize;
int used[100001], r_slist[100001];
vector<vector<int>> alist(100001);
vector<vector<int>> r_alist(100001);

void getDownSize(int now)
{
    downSize++;
    for (int i = 0; i < alist[now].size(); i++)
    {
        int next = alist[now][i];
        if (used[next] == 1) continue;
        used[next] = 1;
        getDownSize(next);
    }
}
void getUpSize(int now)
{
    upSize++;
    for (int i = 0; i < r_alist[now].size(); i++)
    {
        int next = r_alist[now][i];
        getUpSize(next);
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
        r_alist[to].push_back(from);
    }
    getUpSize(target);
    getDownSize(target);
    cout << upSize << '\n';
    cout << N - downSize + 1 << '\n';

    return 0;
}