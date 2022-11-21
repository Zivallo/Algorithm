#include <iostream>
#include <string>
using namespace std;
int T, gcd, gop, l1, l2;
string s1, s2, t1, t2;

int getGcd(int a, int b) {
	int c = a % b;
	while (c) {
		a = b; b = c;
		c = a % b;
	}
	return b;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> s1 >> s2;
		gcd = 0, l1 = s1.length(), l2 = s2.length();
		if (l1 > l2)gcd = getGcd(l1, l2);
		else gcd = getGcd(l2, l1);
		gop = l1 * l2 / gcd, t1 = "", t2 = "";
		for (int i = 0; i < gop / l1; i++)t1 += s1;
		for (int i = 0; i < gop / l2; i++)t2 += s2;
		if (t1 == t2)cout << "#" << t << " yes\n";
		else cout << "#" << t << " no\n";
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