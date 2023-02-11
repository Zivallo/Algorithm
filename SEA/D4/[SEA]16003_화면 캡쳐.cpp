#include <iostream>
using namespace std;
int T, N, c;

void rec(int max, int n) {
	if (n > max)return;
	if (c > (max > 49 ? 49 : max))return;
	for (int i = 0; i < 10; i++) {
		if (c > (max > 49 ? 49 : max))break;
		if (n + i > N) break;
		cout << n + i << ".png "; c++;
		rec(max, (n + i) * 10);
	}
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; c = 0;
		cout << "#" << t << " ";
		for (int i = 1; i < 10; i++) {
			if (c > (N > 49 ? 49 : N))break;
			if (i > N) break;
			cout << i << ".png "; c++;
			rec(N, i * 10);
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