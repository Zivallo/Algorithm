#include <iostream>
using namespace std;
unsigned long long T, N, M;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		if ((M & ((1 << N) - 1)) == ((1 << N) - 1))cout << "#" << t << " ON\n";
		else cout << "#" << t << " OFF\n";
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