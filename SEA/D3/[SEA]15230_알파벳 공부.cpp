#include <iostream>
#include <string>
using namespace std;
int T;
string str;
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> str; int ans = 0;
		for (int i = 0; i < str.length(); i++) {
			if (i != str[i] - 'a')break;
			ans++;
			if (ans == 26)break;
		}
		cout << "#" << t << " " << ans << "\n";
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
