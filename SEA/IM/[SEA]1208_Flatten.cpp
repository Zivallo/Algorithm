#include <iostream>
#include <algorithm>
using namespace std;

int dump, box[110];
int ans;

int main() {
	for (int t = 1; t <= 10; t++) {
		cin >> dump;
		for (int i = 0; i < 100; i++) cin >> box[i];
		sort(box, box + 100);
		for (int i = 0; i < dump; i++) {
			ans = box[99] - box[0];
			if (ans == 0) break;
			box[0]++;
			box[99]--;
			sort(box, box + 100);
		}
		ans = box[99] - box[0];
		cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}