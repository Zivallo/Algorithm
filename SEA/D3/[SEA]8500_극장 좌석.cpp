#include <iostream>
using namespace std;
int T, N, A[10010];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; int maxi = 0, tmp = 0, r = 0;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			r += tmp;
			if (tmp > maxi)maxi = tmp;
		}
		cout << "#" << t << " " << r + maxi + N << "\n";
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