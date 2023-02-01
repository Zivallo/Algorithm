#include <iostream>
#include <string>
using namespace std;
int T, dat[130];
string r, l;
void init() {
	dat['A'] = 1, dat['B'] = 2, dat['D'] = 1;
	dat['O'] = 1, dat['P'] = 1, dat['Q'] = 1;
	dat['R'] = 1;
}
void solve() {
	init();
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> r >> l; cout << "#" << t << " ";
		if (r.length() != l.length())cout << "DIFF\n";
		else {
			bool flag = true;
			for (int i = 0; i < r.length(); i++) {
				if (dat[r[i]] != dat[l[i]]) { flag = false; break; }
			}
			if (flag)cout << "SAME\n";
			else cout << "DIFF\n";
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}