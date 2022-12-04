#include <iostream>
#include <string>
using namespace std;
int T;
string str;
int enc[130];

void solve() {
	for (int c = 'A'; c <= 'Z'; c++)enc[c] = (c - 'A');
	for (int c = 'a'; c <= 'z'; c++)enc[c] = (c - 'a' + 26);
	for (int c = '0'; c <= '9'; c++)enc[c] = (c - '0' + 52);
	enc['+'] = 62, enc['/'] = 63;
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> str; cout << "#" << t << " ";
		string ans = "";
		for (int i = 0; i < str.length(); i += 4)
		{
			long long tmp = 0; string tmp1 = "";
			for (int j = 0; j < 4; j++)
			{
				tmp = (tmp << 6 | enc[str[i + j]]);
			}
			for (int j = 0; j < 3; j++)
			{
				tmp1 = char(tmp & 0b11111111) + tmp1;
				tmp >>= 8;
			}
			ans += tmp1;
		}
		cout << ans << "\n";
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