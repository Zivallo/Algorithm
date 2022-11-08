#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[5000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int cur = 1, ans = 0;
	while (cur < N) {
		sort(arr, arr + N);
		ans += arr[cur - 1] + arr[cur];
		arr[cur] = arr[cur - 1] + arr[cur];
		cur++;
	}
	cout << ans;
	return 0;
}