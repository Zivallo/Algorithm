#include <iostream>
using namespace std;
int T;
double A, B, C, D;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> A >> B >> C >> D;
		cout << "#" << t << " " << (A / B == C / D ? "DRAW" : (A / B > C / D ? "ALICE" : "BOB")) << "\n";
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