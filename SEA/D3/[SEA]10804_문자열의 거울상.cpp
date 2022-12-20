#include <iostream>
#include <string>
using namespace std;
int T;
string s;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s;
		cout << "#" << t << " ";
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == 'b')cout << "d";
			if (s[i] == 'd')cout << "b";
			if (s[i] == 'q')cout << "p";
			if (s[i] == 'p')cout << "q";
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