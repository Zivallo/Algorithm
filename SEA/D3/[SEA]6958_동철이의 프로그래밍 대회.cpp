#include <iostream>
using namespace std;
int T, N, M;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		int c[22] = { 0 }, maxi = 0;
		for (int y = 0; y < N; y++) {
			int c1 = 0;
			for (int x = 0; x < M; x++) {
				int tmp; cin >> tmp;
				if (tmp)c1++;
			}
			if (c1 > maxi)maxi = c1;
			c[c1]++;
		}
		cout << "#" << t << " " << c[maxi] << " " << maxi << "\n";
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