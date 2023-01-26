#include <iostream>
#include <string>
using namespace std;
int T, N;
string s;

bool check(string s, int last) {
	if (s[0] < 'A' || s[0]>'Z')return false;
	for (int i = 1; i < last; i++) {
		if (s[i] < 'a' || s[i]>'z')return false;
	}
	return true;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N;
		int r = 0;
		cout << "#" << t << " ";
		while (N) {
			cin >> s;
			if (s[s.length() - 1] == '.' || s[s.length() - 1] == '!' || s[s.length()-1] == '?') {
				if (check(s, s.length() - 1))r++;
				cout << r << " ";
				r = 0;
				N--;
			}
			else 
				if (check(s, s.length()))r++;
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