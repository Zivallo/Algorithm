#include <iostream>
#include <string>
using namespace std;
int T;
string s;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s;
		cout << "#" << t << " ";
		if ((s[s.length() - 1] - '0') % 2 == 0)cout << "Even\n";
		else cout << "Odd\n";
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