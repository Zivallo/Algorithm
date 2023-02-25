#include <iostream>
#include <string>
using namespace std;
int T;
string s;

bool check() {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i]) {
			if (s[i] == '?' || s[s.length() - 1 - i] == '?')continue;
			return false;
		}
	}
	return true;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s; cout << "#" << t << " ";
		if (check())cout << "Exist\n";
		else cout << "Not exist\n";
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