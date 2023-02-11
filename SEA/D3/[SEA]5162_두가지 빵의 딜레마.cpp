#include<iostream>
using namespace std;
int T, A, B, C;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> A >> B >> C;
		int r = 0;
		r += C / (A < B ? A : B);
		C %= (A < B ? A : B);
		r += C / (A > B ? A : B);
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