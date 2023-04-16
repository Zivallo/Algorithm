#include <iostream>
#include <string>
using namespace std;

void solve() {
	for (int t = 1; t <= 10; t++) {
		int l; string s;
		cin >> l >> s;
		int sum = s[0] - '0';
		for (int i = 1; i < l; i++) {
			if (s[i] == '+')continue;
			sum += s[i] - '0';
		}
		cout << "#" << t << " " << sum << "\n";
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