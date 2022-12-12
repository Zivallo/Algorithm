#include <iostream>
#include <string>
using namespace std;
int T, maxi, mini;
string s;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s; maxi = stoi(s); mini = stoi(s);
		for (int i = 0; i < s.length() - 1; i++) {
			for (int j = i + 1; j < s.length(); j++) {
				string tmp = s;
				tmp[i] = s[j]; tmp[j] = s[i];
				if (tmp[0] == '0')continue;
				maxi = (maxi < stoi(tmp) ? stoi(tmp) : maxi);
				mini = (mini > stoi(tmp) ? stoi(tmp) : mini);
			}
		}
		cout << "#" << t << " " << mini << " " << maxi << "\n";
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