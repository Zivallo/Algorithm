#include <iostream>
using namespace std;
int T;

int sum(int n) {
	int ret = 0;
	while (n) {
		ret += (n % 10);
		n /= 10;
	}
	return ret;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		int maxi = 0, mini = 21e8;
		for (int i = 0; i < 10; i++) {
			int n; cin >> n;
			int tmp = sum(n);
			if (tmp > maxi)maxi = tmp;
			if (tmp < mini)mini = tmp;
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