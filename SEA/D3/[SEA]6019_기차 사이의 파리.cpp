#include <iostream>
using namespace std;
int T;
double D, A, B, F;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> D >> A >> B >> F;
		double s = D / (A + B);
		double ans = s * F;
		cout << "#" << t << " " << ans << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	cout << fixed;
	cout.precision(10);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}