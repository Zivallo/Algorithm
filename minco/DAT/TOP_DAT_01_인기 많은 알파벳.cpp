#include <iostream>
using namespace std;

int main() {
	char arr[9] = { 0 };
	int cnt[100] = { 0 }, max = -999, maxi = 0;
	cin >> arr;
	for (int x = 0; x < 8; x++) {
		cnt[arr[x]]++;
	}
	for (int x = 0; x < 100; x++) {
		if (max < cnt[x]) {
			max = cnt[x];
			maxi = x;
		}
	}
	cout << (char)maxi;

	return 0;
}