#include <iostream>
using namespace std;
int T, N, Q, L, R;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> Q; int box[1100] = { 0 };
		for (int i = 1; i <= Q; i++) {
			cin >> L >> R;
			for (int j = L; j <= R; j++)box[j] = i;
		}
		cout << "#" << t << " ";
		for (int i = 1; i <= N; i++)cout << box[i] << " ";
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