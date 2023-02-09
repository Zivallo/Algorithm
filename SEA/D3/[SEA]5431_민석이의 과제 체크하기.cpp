#include <iostream>
using namespace std;
int T, N, K;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> K; int c[110] = { 0 };
		for (int i = 0; i < K; i++) {
			int tmp; cin >> tmp;
			c[tmp] = 1;
		}cout << "#" << t << " ";
		for (int i = 1; i <= N; i++)if (!c[i])cout << i << " ";
		cout << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}