#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
unordered_map<string, int> um;
int T;
string s;
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s;
		if (s == "SUN")cout << "#" << t << " 7\n";
		if (s == "MON")cout << "#" << t << " 6\n";
		if (s == "TUE")cout << "#" << t << " 5\n";
		if (s == "WED")cout << "#" << t << " 4\n";
		if (s == "THU")cout << "#" << t << " 3\n";
		if (s == "FRI")cout << "#" << t << " 2\n";
		if (s == "SAT")cout << "#" << t << " 1\n";
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