#include <iostream>
#include <string>
#define M 1000000007
using namespace std;
int T;
string s;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s;
		long long r = 1;
		for (int i = 0; i < s.length(); i++) {
			int c = 1;
			if (i - 1 >= 0) if (s[i - 1] != s[i])c++;
			if (i + 1 < s.length()) if (s[i + 1] != s[i])c++;
			if (i - 1 >= 0 && i + 1 < s.length())if (c == 3 && s[i - 1] == s[i + 1])c--;
			r = (r * c) % M;
		}
		cout << "#" << t << " " << r << "\n";
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