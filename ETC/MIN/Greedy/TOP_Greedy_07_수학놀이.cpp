#include <iostream>
using namespace std;

int start, target, cnt;

int main() {
	cin >> start >> target;

	while (1)
	{
		if (target % 10 == 1) target /= 10;
		else target /= 2;
		cnt++;
		if (start == target) break;
		if (start > target) {
			cnt = -1;
			break;
		}
	}
	cout << cnt;
	return 0;
}