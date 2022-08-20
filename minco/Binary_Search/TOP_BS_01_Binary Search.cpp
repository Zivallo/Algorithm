#include <iostream>
#include <algorithm>
using namespace std;

int arr[110000], n, k;
int target;

int bs(int s, int e) {
	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] == target) return 1;
		if (arr[mid] > target) e = mid - 1;
		else s = mid + 1;
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> target;
		int flag = bs(0, n - 1);
		if (flag) cout << "O";
		else cout << "X";
	}
	return 0;
}