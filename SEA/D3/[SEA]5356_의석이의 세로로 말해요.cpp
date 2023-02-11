#include <iostream>
#include <string>
using namespace std;
int T;
string s[5];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 5; i++)cin >> s[i];
		cout << "#" << t << " ";
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 5; j++) {
				if (i >= s[j].length())continue;
				cout << s[j][i];
			}
		}
		cout << "\n";
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