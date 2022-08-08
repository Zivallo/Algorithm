#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, S;
int preorder[101], postorder[101], used[101];
vector<vector<int>> alist(101);
int preidx = 1, postidx = 0;

void DFS(int now) {
	sort(alist[now].rbegin(), alist[now].rend());
	for (int i = 0; i < alist[now].size(); i++) {
		int next = alist[now][i];
		if (used[next] == 1)continue;
		used[next] = 1;
		preorder[preidx] = next;
		preidx++;
		DFS(next);
		postorder[postidx] = next;
		postidx++;
	}
}

int main() {
	cin >> N >> K >> S;
	for (int i = 0; i < K; i++) {
		int from, to;
		cin >> from >> to;
		alist[from].push_back(to);
	}
	used[S] = 1;
	preorder[0] = S;
	DFS(S);
	postorder[N - 1] = S;
	for (int i = 0; i < N; i++) cout << preorder[i] << " ";
	cout << '\n';
	for (int i = 0; i < N; i++) cout << postorder[i] << " ";
	return 0;
}