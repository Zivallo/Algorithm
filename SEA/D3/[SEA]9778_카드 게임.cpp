#include <iostream>
using namespace std;
int T, N;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		int card[12] = { 0,0,4,4,4,4,4,4,4,4,16,4, };
		int total = 0, cnt = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int tmp; cin >> tmp;
			card[tmp]--;
			total += tmp;
		}
		if (total >= 21) {
			cout << "#" << t << " STOP\n"; continue;
		}

		for (int i = 2; i <= (21 - total); i++) {
			cnt += card[i];
		}
		if (cnt > (52 - N - cnt))cout << "#" << t << " GAZUA\n";
		else cout << "#" << t << " STOP\n";
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