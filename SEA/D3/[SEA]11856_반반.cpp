#include <iostream>
#include <string>
using namespace std;
int T;
string s;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s; int u[130] = { 0 }, cnt = 0, flag = 0;
		for (int i = 0; i < s.length(); i++)u[s[i]]++;
		for (int i = 'A'; i <= 'Z'; i++) {
			if (u[i] == 0)continue;
			if (u[i] != 2) { flag = 1; break; }
			cnt++;
		}
		if (flag == 0 && cnt == 2)cout << "#" << t << " Yes\n";
		else cout << "#" << t << " No\n";
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