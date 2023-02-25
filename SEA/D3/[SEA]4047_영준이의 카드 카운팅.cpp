#include <iostream>
#include <string>
using namespace std;
int T; string s;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s; int cnt[130][15] = {0}, flag = 0;
		for (int i = 0; i < s.length(); i += 3) {
			int n = (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
			cnt[s[i]][n]++;
			cnt[s[i]][0]++;
			if (cnt[s[i]][n] > 1)flag = 1;
		}
		cout << "#" << t << " ";
		if (flag)cout << "ERROR\n";
		else cout << 13 - cnt['S'][0] << " " << 13 - cnt['D'][0] << " " << 13 - cnt['H'][0] << " " << 13 - cnt['C'][0] << "\n";
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