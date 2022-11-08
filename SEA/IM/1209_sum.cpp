#include <iostream>
using namespace std;
int arr[110][110];
int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;

int main() {
	for (int t = 1; t <= 10; t++) {
		int n;
		cin >> n;
		int maxSum = -21e8;
		for (int y = 0; y < 100; y++) {
			for (int x = 0; x < 100; x++) {
				cin >> arr[y][x];
			}
		}
		for (int y = 0; y < 100; y++) {
			sum1 = 0, sum2 = 0;
			for (int x = 0; x < 100; x++) {
				sum1 += arr[y][x];
				sum2 += arr[x][y];
			}
			if (sum1 > maxSum) maxSum = sum1;
			if (sum2 > maxSum) maxSum = sum2;
		}
		sum3 = 0, sum4 = 0;
		for (int y = 0; y < 100; y++) {
			sum3 += arr[y][y];
			sum4 += arr[y][99 - y];
		}
		if (sum3 > maxSum) maxSum = sum3;
		if (sum4 > maxSum) maxSum = sum4;
		cout << "#" << n << " " << maxSum << '\n';
	}

	return 0;
}