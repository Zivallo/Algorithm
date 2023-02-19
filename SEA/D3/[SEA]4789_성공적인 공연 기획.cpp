#include<iostream>
#include<string>
using namespace std;
int T;
string s;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s; int p = 0, r = 0;
		for (int i = 0; i < s.length(); i++) {
			if (p >= i) { p += (s[i] - '0'); continue; }
			r += (i - p);
			p = i + (s[i] - '0');
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