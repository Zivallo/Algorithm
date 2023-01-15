#include <iostream>
using namespace std;
int T, N, B, E;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> B >> E; int r = 0, tmp = 0;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			if (E >= (B % tmp) || E >= (tmp - (B % tmp)))r++;
		}
		cout << "#" << t << " " << r << "\n";
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