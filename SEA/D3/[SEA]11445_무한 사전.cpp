#include <iostream>
#include <string>
using namespace std;
int T;
string P, Q;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> P >> Q;
		if (P + 'a' == Q)cout << "#" << t << " N\n";
		else cout << "#" << t << " Y\n";
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