#include <iostream>
#include <string>
using namespace std;
int T, N;
string s[1010];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; for (int i = 0; i < N; i++)cin >> s[i];
		cout << "#" << t << " ";
		for (int i = 0; i < (N&1?N+1:N) / 2; i++) {
			cout << s[i] << " ";
			if ((N & 1 ? N + 1 : N) / 2 + i < N)cout << s[(N & 1 ? N + 1 : N) / 2 + i] << " ";
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