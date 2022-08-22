#include <iostream>
using namespace std;

int T, N, D, ans;

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> D;
		int div1 = 2 * D + 1;
		int temp = N / div1;
		if (N % div1 == 0) {
			ans = temp;
			cout << '#' << t << ' ' << ans << '\n';
			continue;
		}
		ans = temp + 1;
		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}