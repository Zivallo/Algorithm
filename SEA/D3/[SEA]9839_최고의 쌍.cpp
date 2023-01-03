#include <iostream>
using namespace std;
int T, N;
int n[1010];

bool check(int num) {
	int tmp = num % 10;
	num /= 10;
	while (num) {
		if (tmp - 1 != num % 10)return false;
		tmp = num % 10;
		num /= 10;
	}
	return true;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; for (int i = 0; i < N; i++)cin >> n[i];
		int r = 0;
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (check(n[i] * n[j])) if (r < n[i] * n[j])r = n[i] * n[j];
			}
		}
		if (r)cout << "#" << t << " " << r << "\n";
		else cout << "#" << t << " -1\n";
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