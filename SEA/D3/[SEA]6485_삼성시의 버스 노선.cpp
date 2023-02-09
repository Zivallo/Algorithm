#include <iostream>
using namespace std;
int T, N, P;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; int c[550][2] = { 0 };
		for (int i = 0; i < N; i++) {
			cin >> c[i][0] >> c[i][1];
		}
		cin >> P; cout << "#" << t << " ";
		for (int i = 0; i < P; i++) {
			int r = 0, C;
			cin >> C;
			for (int j = 0; j < N; j++) {
				if (c[j][0]<=C && c[j][1]>=C)r++;
			}
			cout << r << " ";
		}
		cout << "\n";
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