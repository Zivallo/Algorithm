#include <iostream>
#include <string>
using namespace std;
string arr[1100];

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << "#" << t << " ";
		if (n % 2 == 1) {
			for (int i = 0; i < (n / 2) + 1; i++) {
				cout << arr[i] << " ";
				if ((n / 2) + i + 1 == n) break;
				cout << arr[(n / 2) + i + 1] << " ";
			}
		}
		else {
			for (int i = 0; i < (n / 2); i++) {
				cout << arr[i] << " " << arr[(n / 2) + i] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}