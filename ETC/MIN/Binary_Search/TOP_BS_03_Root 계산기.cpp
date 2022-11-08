#include <iostream>
using namespace std;

long long num;

int getRoot(int s, int e) {
	long long ans = 0;
	while (s <= e) {
		long long mid = (s + e) / 2;

		if (mid * mid <= num) {
			ans = mid;
			s = mid + 1;
		}
		else e = mid - 1;
	}
	return ans;
}

int main() {
	cin >> num;
	int ans = getRoot(1, num);
	cout << ans;
	return 0;
}