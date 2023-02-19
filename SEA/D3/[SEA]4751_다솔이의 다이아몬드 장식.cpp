#include <iostream>
#include <string>
using namespace std;
int T;
string s;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s;
		cout << "."; for (int i = 0; i < s.length(); i++)cout << ".#..";
		cout << "\n."; for (int i = 0; i < s.length() * 2; i++)cout << "#.";
		cout << "\n#"; for (int i = 0; i < s.length(); i++)cout << "." << s[i] << ".#";
		cout << "\n."; for (int i = 0; i < s.length() * 2; i++)cout << "#.";
		cout << "\n."; for (int i = 0; i < s.length(); i++)cout << ".#..";
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