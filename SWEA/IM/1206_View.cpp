#include <iostream>
using namespace std;

int len, sum;
int map[1100];

int main() {
	for (int t = 1; t <= 10; t++) {
		sum = 0;
		cin >> len;
		for (int i = 0; i < len; i++) cin >> map[i];
		for (int i = 2; i < len - 2; i++) {
			int tempMin = 21e8;
			for (int j = -2; j < 3; j++) {
				if (j == 0) continue;
				int temp = map[i] - map[i + j];
				if (temp < 0) temp = 0;
				if (tempMin > temp) tempMin = temp;
			}
			if (tempMin == 21e8) tempMin = 0;
			sum += tempMin;
		}
		cout << "#" << t << " " << sum << '\n';
	}
	return 0;
}