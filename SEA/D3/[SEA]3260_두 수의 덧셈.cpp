#include <iostream>
#include <string>
using namespace std;
int T;
string A, B;

string calc(string A, string B) {
	string ret; int n = 0;
	for (int i = 0; i < A.length(); i++) {
		n += A[A.length() - 1 - i] - '0';
		if (i < B.length())n += B[B.length() - 1 - i] - '0';
		ret = (char)(n % 10 + '0') + ret;
		if (n >= 10)n = 1;
		else n = 0;
	}
	if (n == 1)ret = '1' + ret;
	return ret;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> A >> B;
		cout << "#" << t << " " << calc((A.length() > B.length() ? A : B), (A.length() > B.length() ? B : A)) << "\n";
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