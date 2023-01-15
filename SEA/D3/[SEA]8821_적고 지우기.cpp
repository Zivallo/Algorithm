#include <iostream>
#include <string>
using namespace std;
int T;
string s;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s; int r = 0, c[10] = { 0 };
		for (int i = 0; i < s.length(); i++) {
			if (c[s[i] - '0'] == 0) {
				c[s[i] - '0'] = 1;
				r++;
			}
			else {
				c[s[i] - '0'] = 0;
				r--;
			}
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