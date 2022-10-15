#include <iostream>
#include <cstring>
using namespace std;
char num[1100000];
int num100, num10, num1, squ;
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> num;
		num100 = num[0] - '0';
		num10 = num[1] - '0';
		num1 = num[2] - '0';
		if (num1 > 4) num10++;
		if (num10 == 10) {
			num100++;
			num10 = 0;
		}
		squ = strlen(num) - 1;
		if (num100 == 10) {
			num10 = num100 % 10;
			num100 = num100 / 10;
			squ++;
		}
		cout << "#" << t << " " << num100 << "." << num10 << "*10^" << squ << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}