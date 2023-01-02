#include <iostream>
using namespace std;
int T, N;
char ori[100100], cpy[100100];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; int r = 0;
		for (int i = 0; i < N; i++)cin >> ori[i];
		for (int i = 0; i < N; i++) {
			cin >> cpy[i];
			if (ori[i] == cpy[i])r++;
		}
		cout << "#" << t << " " << r << '\n';
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