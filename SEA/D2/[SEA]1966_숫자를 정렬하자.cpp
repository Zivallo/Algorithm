#include <iostream>
#include <algorithm>
using namespace std;
int T, N;
int a[55];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; for (int i = 0; i < N; i++)cin >> a[i];
		sort(a, a + N);
		cout << "#" << t << " ";
		for (int i = 0; i < N; i++)cout << a[i] << " ";
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