#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, map[110][110], used[110][110], parents[7];
int maxIdx, result;
int drY[4] = { -1,0,1,0 };
int drX[4] = { 0,1,0,-1 };
vector < pair<int, pair<int, int>>> bridge;
bool cmp(pair<int, pair<int, int>>t, pair<int, pair<int, int>>v) {
	return t.first < v.first;
}
int findP(int tar) {
	if (parents[tar] == tar) return tar;
	return parents[tar] = findP(parents[tar]);
}
void uni(int a, int b) {
	int PA = findP(a);
	int PB = findP(b);
	if (PA == PB) return;
	parents[PB] = PA;
}

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++)for (int x = 0; x < M; x++) {
		cin >> map[y][x];
		used[y][x] = 0;
	}
	maxIdx = 1;
	bridge.clear();
}
void setMap() {
	maxIdx = 1;
	for (int y = 0; y < N; y++)for (int x = 0; x < M; x++) {
		if (map[y][x] == 0 || used[y][x] == 1)continue;
		queue<pair<int, int>> q;
		used[y][x] = 1;
		map[y][x] = maxIdx;
		q.push({ y,x });
		while (!q.empty()) {
			pair<int, int> now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = now.first + drY[i];
				int nx = now.second + drX[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
				if (map[ny][nx] != 1)continue;
				if (used[ny][nx] == 1)continue;
				used[ny][nx] = 1;
				map[ny][nx] = maxIdx;
				q.push({ ny,nx });
			}
		}
		maxIdx++;
	}
	for (int i = 1; i < maxIdx; i++)parents[i] = i;
}
void findMinBridge() {
	for (int y = 0; y < N; y++) {
		int xval = map[y][0], flag = 0, from = 0, to = 0, len = 0;
		for (int x = 1; x < M; x++) {
			if (xval != 0 && map[y][x] == 0) { flag = 1; from = xval; }
			if (flag) len++;
			if (xval == 0 && map[y][x] != 0) {
				flag = 0;
				if (len - 1 < 2) { xval = map[y][x]; len = 0; continue; }
				to = map[y][x];
				bridge.push_back({ len - 1,{from,to} });
				len = 0;
			}
			xval = map[y][x];
		}
	}
	for (int x = 0; x < M; x++) {
		int xval = map[0][x], flag = 0, from = 0, to = 0, len = 0;
		for (int y = 1; y < N; y++) {
			if (xval != 0 && map[y][x] == 0) { flag = 1; from = xval; }
			if (flag) len++;
			if (xval == 0 && map[y][x] != 0) {
				flag = 0;
				if (len - 1 < 2) { xval = map[y][x]; len = 0; continue; }
				to = map[y][x];
				bridge.push_back({ len - 1,{from,to} });
				len = 0;
			}
			xval = map[y][x];
		}
	}
}
int findResult() {
	int minLen = 0, cnt = 0;
	for (int i = 0; i < bridge.size(); i++) {
		if (findP(bridge[i].second.first) == findP(bridge[i].second.second)) continue;
		minLen += bridge[i].first;
		uni(bridge[i].second.first, bridge[i].second.second);
		for (int i = 1; i < maxIdx; i++) findP(i);
		cnt++;
		if (cnt == maxIdx - 2)break;
	}
	return  minLen;
}
bool isAllConnected() {
	int parent = parents[1];
	for (int i = 2; i < maxIdx; i++)if (parents[i] != parent)return false;
	return true;
}
void solve() {
	input();
	setMap();
	findMinBridge();
	if (bridge.empty()) { cout << "-1\n"; return; }
	sort(bridge.begin(), bridge.end(), cmp);
	result = findResult();
	bool flag = isAllConnected();
	if (flag) cout << result << "\n";
	else cout << "-1\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}