#include <iostream>
#include <string>
using namespace std;
int T;
string s;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s; int c[10] = { 0 }, r = 0;
		for (int i = 0; i < s.length(); i++) {
			if (c[s[i] - '0'])continue;
			c[s[i] - '0'] = 1;
			r++;
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