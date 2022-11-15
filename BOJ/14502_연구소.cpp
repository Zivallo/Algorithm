#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, result;
int map[10][10], copymap[10][10], visited[10][10];
int drY[4] = { -1,1,0,0 };
int drX[4] = { 0,0,-1,1 };
vector<pair<int, int>> initVirus;
queue<pair<int, int>> virus;
void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++)for (int x = 0; x < M; x++) {
		cin >> map[y][x];
		if (map[y][x] == 2) initVirus.push_back({ y,x });
	}
}
void copyMap() {
	for (int y = 0; y < N; y++)for (int x = 0; x < M; x++) copymap[y][x] = map[y][x];
}
void copyVirus() {
	for (int i = 0; i < initVirus.size(); i++) virus.push({ initVirus[i].first,initVirus[i].second });
}
void setCopyMap() {
	copyVirus();
	while (!virus.empty()) {
		int y = virus.front().first;
		int x = virus.front().second;
		virus.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + drY[i];
			int nx = x + drX[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
			if (copymap[ny][nx] != 0) continue;
			copymap[ny][nx] = 2;
			virus.push({ ny,nx });
		}
	}
}
void findSafeArea() {
	int cnt = 0;
	for (int y = 0; y < N; y++)for (int x = 0; x < M; x++) {
		if (copymap[y][x] == 0) cnt++;
	}
	if (cnt > result)result = cnt;
}
void dfs(int lev) {
	if (lev == 3) {
		copyMap();
		setCopyMap();
		findSafeArea();
		return;
	}
	for (int y = 0; y < N; y++)for (int x = 0; x < M; x++) {
		if (map[y][x] != 0) continue;
		if (visited[y][x] == 1) continue;
		visited[y][x] = 1;
		map[y][x] = 1;
		dfs(lev + 1);
		map[y][x] = 0;
		visited[y][x] = 0;
	}
}
void solve() {
	input();
	dfs(0);
	cout << result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}