#include <iostream>
#include <string>
using namespace std;
int T;
string S;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> S; int win = 15;
		for (int i = 0; i < S.length(); i++) if (S[i] == 'x')win--;
		cout << "#" << t;
		if (win >= 8)cout << " YES\n";
		else cout << " NO\n";
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