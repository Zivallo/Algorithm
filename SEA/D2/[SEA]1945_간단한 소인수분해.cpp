#include <iostream>
using namespace std;
int T, N;
int m[5] = { 2,3,5,7,11 };
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N;
		cout << "#" << t << " ";
		for (int i = 0; i < 5; i++) {
			int cnt = 0;
			while (N % m[i] == 0) {
				N /= m[i];
				cnt++;
			}
			cout << cnt << " ";
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