#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int T, M, N, K, m[55][55];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
vector<pair<int, int>> v;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		v.clear();
		cin >> M >> N >> K; int r = 0;
		for (int i = 0; i < K; i++) {
			int y, x; cin >> y >> x;
			v.push_back({ y,x });
			m[y][x] = 1;
		}
		queue<pair<int, int>> q;
		for (int i = 0; i < K; i++) {
			if (m[v[i].first][v[i].second] == 0)continue;
			q.push({ v[i].first,v[i].second });
			m[v[i].first][v[i].second] = 0;
			while (!q.empty()) {
				pair<int, int> now = q.front();
				q.pop();

				for (int j = 0; j < 4; j++) {
					int ny = now.first + dy[j];
					int nx = now.second + dx[j];
					if (ny < 0 || nx < 0 || ny >= M || nx >= N)continue;
					if (m[ny][nx] == 0)continue;
					m[ny][nx] = 0;
					q.push({ ny,nx });
				}
			}
			r++;
		}
		cout << r << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}