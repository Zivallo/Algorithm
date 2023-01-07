#include <iostream>
#include <string>
using namespace std;
int T;
string s;
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cout << "#" << t << " ";
		for (int i = 0; i < 3; i++) {
			cin >> s; cout << (char)(s[0] - 'a' + 'A');
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