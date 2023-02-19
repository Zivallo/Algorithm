#include <iostream>
#include <string>
using namespace std;
int T, H;
string s;

void solve() {
	cin >> T;for(int t=1;t<=T;t++){
		cin >> s >> H; int c[1010] = { 0 };
		for (int i = 0; i < H; i++) {
			int tp; cin >> tp;
			c[tp]++;
		}cout << "#" << t << " ";
		for (int i = 0; i <= s.length(); i++) {
			for (int j = 0; j < c[i]; j++)cout << "-";
			if (i < s.length()) cout << s[i];
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