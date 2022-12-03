#include <iostream>
using namespace std;
int T, N;
int cost[8] = { 50000,10000,5000,1000,500,100,50,10 };
void solve() {
	cin >> T; for (int t = 1; t <= T; t ++ ) {
		cin >> N; cout << "#" << t << "\n";
		for (int i = 0; i < 8; i++) {
			cout << N / cost[i] << " ";
			N -= cost[i] * (N / cost[i]);
		}
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