#include <iostream>
using namespace std;
long long T, A, B;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> A >> B;
		cout << "#" << t << " " << (A / B) * (A / B) << "\n";
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