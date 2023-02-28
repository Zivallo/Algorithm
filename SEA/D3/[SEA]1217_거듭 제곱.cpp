#include <iostream>
using namespace std;
int t, n, m;

int rec(int N, int M) {
	if (M == 0)return 1;
	return N * rec(N, M - 1);
}
void solve() {
	for (int T = 1; T <= 10; T++) {
		cin >> t >> n >> m;
		cout << "#" << t << " " << rec(n, m) << "\n";
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