#include <iostream>
using namespace std;
int T;
char date[4];

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 4; i++)cin >> date[i];
		bool first = false, second = false;
		int xx = (date[0] - '0') * 10 + (date[1] - '0');
		int yy = (date[2] - '0') * 10 + (date[3] - '0');

		if (0 < xx && xx < 13)first = true;
		else first = false;

		if (0 < yy && yy < 13)second = true;
		else second = false;

		cout << "#" << t;
		if (first && second) cout << " AMBIGUOUS\n";
		else if (first && !second) cout << " MMYY\n";
		else if (!first && second) cout << " YYMM\n";
		else cout << " NA\n";
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