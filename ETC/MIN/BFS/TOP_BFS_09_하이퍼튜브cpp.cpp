#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int now;
	int cnt;
};
int N, K, M, used[100001];
vector<vector<int>> whatTube(100001);
vector<vector<int>> whatStation(1001);
queue<Node> q;

int getCnt() {
	while (!q.empty()) {
		int now = q.front().now;
		int nowCnt = q.front().cnt;
		if (now == N) return nowCnt;
		q.pop();
		for (int i = 0; i < whatTube[now].size(); i++) {
			int nextTube = whatTube[now][i];
			for (int j = 0; j < whatStation[nextTube].size(); j++) {
				int nextStation = whatStation[nextTube][j];
				int nCnt = nowCnt + 1;
				if (used[nextStation] == 1) continue;
				used[nextStation] = 1;
				q.push({ nextStation,nCnt });
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> K >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < K; j++) {
			int temp;
			cin >> temp;
			whatStation[i].push_back(temp);
			whatTube[temp].push_back(i);
		}

	}
	used[1] = 1;
	q.push({ 1,1 });
	cout << getCnt();
	return 0;
}