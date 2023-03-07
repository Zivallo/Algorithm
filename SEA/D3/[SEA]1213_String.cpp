#include <iostream>
#include <string>
using namespace std;
int t;
string tar, str;

void solve() {
	for (int v = 0; v < 10; v++) {
		cin >> t >> tar >> str; int r = 0, idx = -1;
		do {
			if (idx > 0)r++;
			idx = str.find(tar, idx + 1);
		} while (idx != -1);
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