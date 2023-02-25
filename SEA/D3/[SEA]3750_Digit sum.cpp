#include <iostream>
using namespace std;
long long T, N;

long long calc(long long n) {
	long long ret = 0;
	while (n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N;
		while (N >= 10) N = calc(N);
		cout << "#" << t << " " << N << "\n";
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