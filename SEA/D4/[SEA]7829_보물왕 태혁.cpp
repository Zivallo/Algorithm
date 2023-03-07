#include <iostream>
#include <algorithm>
using namespace std;
int T, P;
long long n[1000010];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> P;
		for (int i = 0; i < P; i++)cin >> n[i];
		sort(n, n + P);
		cout << "#" << t << " " << n[0] * n[P - 1] << "\n";
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