#include <iostream>
using namespace std;
int T, N, f;
char map[21][21];

bool cross1(int y, int x) {
	for (int i = 1; i < 5; i++) {
		if (y + i >= N || x + i >= N)return false;
		if (map[y + i][x + i] != 'o')return false;
	}
	return true;
}
bool cross2(int y, int x) {
	for (int i = 1; i < 5; i++) {
		if (y + i >= N || x - i < 0)return false;
		if (map[y + i][x - i] != 'o')return false;
	}
	return true;
}
void check() {
	int cnt = 0;
	for (int x = 0; x < N; x++) {
		cnt = 0;
		for (int y = 0; y < N; y++) {
			if (map[y][x] == 'o') { 
				cnt++; if (cnt == 5) { f = 1; return; } 
				if (cross1(y, x)) { f = 1; return; }
				if (cross2(y, x)) { f = 1; return; }
			}
			else cnt = 0;
		}
	}
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; int cnt = 0; f = 0;
		for (int y = 0; y < N; y++){
			cnt = 0;
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
				if (map[y][x] == 'o') { cnt++; if (cnt == 5) { f = 1; } }
				else cnt = 0;
			}
		}
		if (!f) check();
		if (f) cout << "#" << t << " YES\n";
		else cout << "#" << t << " NO\n";
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