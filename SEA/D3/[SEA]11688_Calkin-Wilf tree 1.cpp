#include <iostream>
#include <string>
using namespace std;
int T;
string s;
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s;
		int a = 1, b = 1;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'R') a += b;
			if (s[i] == 'L') b += a;
		}
		cout << "#" << t << " " << a << " " << b << "\n";
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