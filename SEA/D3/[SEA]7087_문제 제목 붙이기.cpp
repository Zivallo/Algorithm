#include <iostream>
using namespace std;
int T, N;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; int dat[130] = { 0 };
		char ch[35];
		for (int i = 0; i < N; i++) {
			cin >> ch;
			dat[ch[0]] = 1;
		}int r = 0;
		for (char i = 'A'; i <= 'Z'; i++) {
			if (dat[i] == 1)r++;
			else break;
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