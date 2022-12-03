#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int T, N;
string arr[8];
string ans[8][3];

void rotate() {
	string tmp[8];
	for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) tmp[y] += arr[N - 1 - x][y];
	for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) arr[y][x] = tmp[y][x];
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; 
		for (int i = 0; i < N; i++)arr[i] = "";
		for (int y = 0; y < N; y++)for (int x = 0; x < N; x++) {
			int n;
			cin >> n;
			arr[y] += to_string(n);
		}
		for (int i = 0; i < 3; i++) {
			rotate();
			for (int j = 0; j < N; j++) {
				ans[j][i] = arr[j];
			}
		}
		cout << "#" << t << "\n";
		for (int i = 0; i < N; i++){
			for (int j = 0; j < 3; j++) cout << ans[i][j] << " ";
			cout << "\n";
		}

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}