#include <iostream>
using namespace std;
long long T, L;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> L;
		cout << "#" << t << " " << ((L - 1) / 2) * ((L - 1) / 2) << "\n";
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