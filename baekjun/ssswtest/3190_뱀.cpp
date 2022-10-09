#include <iostream>
#include <vector>
using namespace std;
int N, K, L, dir, sec, result;
int map[110][110] = { 0 };
int drY[4] = { -1,0,1,0 };
int drX[4] = { 0,1,0,-1 };
vector<pair<int, int>> tail;
vector<pair<int, char>> turning;

void input() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int ay, ax;
		cin >> ay >> ax;
		map[ay-1][ax-1] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int X;
		char C;
		cin >> X >> C;
		turning.push_back({ X ,C });
	}
	map[0][0] = 1;
	tail.push_back({ 0, 0 });
	dir = 1;
}
void chdir() {
	if (turning[0].second == 'L') dir = (dir + 3) % 4;
	if (turning[0].second == 'D') dir = (dir + 1) % 4;
	turning.erase(turning.begin());
}
void mvTail() {
	map[tail[0].first][tail[0].second] = 0;
	tail.erase(tail.begin());
}
void simulation() {
	sec = 1;
	int ny = 0, nx = 0;
	while (1) {
		ny += drY[dir];
		nx += drX[dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) break;
		if (map[ny][nx] == 1) break;
		if (map[ny][nx] != 2) mvTail();
		map[ny][nx] = 1;
		tail.push_back({ ny,nx });
		if (!turning.empty()) if (turning[0].first == sec) chdir();
		sec++;
	}
	result = sec;
}
void solve() {
	input();
	simulation();
	cout << result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}