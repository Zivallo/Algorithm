#include <iostream>
using namespace std;
int T, N;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N;
		int inp, x, maxi = 0, mini = 0;
		cin >> x;
		for (int i = 1; i < N; i++) {
			cin >> inp;
			if (inp > x)if (inp - x > maxi) maxi = inp - x;
			if (inp < x)if (x - inp > mini) mini = x - inp;
			x = inp;
		}
		cout << "#" << t << " " << maxi << " " << mini << "\n";
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