#include <iostream>
using namespace std;
int T, K;
int ps[100100];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		int cur = 1, tmp = 0;
		cin >> K >> ps[0];
		for (int i = 1; i < K; i++) {
			cin >> tmp;
			if (tmp != 0) {
				ps[cur] = ps[cur - 1] + tmp;
				cur++;
			}
			else {
				if (cur == 0) { ps[cur] = 0; cur++; }
				else cur--;
			}
		}
		cout << "#" << t << " " << ps[cur - 1] << "\n";
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