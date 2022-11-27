#include <iostream>
#include <cmath>
using namespace std;
unsigned long long T, A, B, K;

unsigned long long fpow(unsigned long long n, unsigned long long sum) {
	if (n == 0) return 1;
	unsigned long long result = fpow(n / 2, sum);
	result = (result * result) % sum;
	if (n & 1) result = (result * 2) % sum;
	return result;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> A >> B >> K;
		unsigned long long a = (A > B ? B : A), b = (A > B ? A : B);
		a = (a * fpow(K, A + B)) % (A + B);
		b = (A + B) - a;
		cout << "#" << t << " " << (a > b ? b : a) << "\n";
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