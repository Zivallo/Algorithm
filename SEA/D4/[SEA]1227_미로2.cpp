#include <iostream>
#include <queue>
using namespace std;
char m[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void solve() {
	for (int t = 1; t <= 10; t++) {
		int T; cin >> T;
		queue<pair<int, int>> q; bool f = false;
		for (int y = 0; y < 100; y++)for (int x = 0; x < 100; x++) {
			cin >> m[y][x];
			if (m[y][x] == '2')q.push({ y,x });
		}
		while (!q.empty()) {
			pair<int, int> now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = now.first + dy[i];
				int nx = now.second + dx[i];
				if (ny < 0 || nx < 0 || ny >= 100 || nx >= 100)continue;
				if (m[ny][nx] == '3') {
					f = true; break;
				}
				if (m[ny][nx] != '0')continue;
				m[ny][nx] = '2';
				q.push({ ny,nx });
			}
		}
		if (f)cout << "#" << t << " 1\n";
		else cout << "#" << t << " 0\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}