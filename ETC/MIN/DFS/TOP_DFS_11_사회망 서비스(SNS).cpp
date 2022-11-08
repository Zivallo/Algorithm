#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> alist(31);
int oddCnt, evenCnt, N, used[31], cntused[31], oddCnt1, evenCnt1;
int flag;

void DFS(int now, int lev) {
	if (lev % 2 == 1) oddCnt1++;
	else evenCnt1++;
	if (now != 1 && alist[now].size() == 1) {
		if (lev % 2 == 0) flag = 2;
		if (lev % 2 == 1) flag = 1;
		return;
	}
	for (int i = 0; i < alist[now].size(); i++) {
		int next = alist[now][i];
		if (used[next] == 1) continue;
		used[next] = 1;
		DFS(next, lev + 1);
		if (cntused[now] == 1) continue;
		if (flag == 2)
			if (lev % 2 == 1) {
				cntused[now] = 1;
				oddCnt++;
			}
		if (flag == 1)
			if (lev % 2 == 0) {
				cntused[now] = 1;
				evenCnt++;
			}
	}
	if (lev == 0) flag = 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int from = 0, to = 0;
		cin >> from >> to;
		alist[from].push_back(to);
		alist[to].push_back(from);
	}
	used[1] = 1;
	DFS(1, 0);
	if (oddCnt1 < (oddCnt + evenCnt) && oddCnt1 < evenCnt1) cout << oddCnt1;
	else if ((oddCnt + evenCnt) < evenCnt1) cout << oddCnt + evenCnt;
	else cout << evenCnt1;

	return 0;
}