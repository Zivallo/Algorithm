#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dat[37], N;
string temp;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		int pow = 1;
		for (int j = temp.size()-1; j >= 0 ; j--) {
			dat[temp[j] - 'A'] += pow;
			pow *= 10;
		}
	}
	sort(dat, dat+11, greater<int>());
	int idx = 9, sum = 0;
	for (int i = 0; i < 27; i++) {
		if (dat[i] == 0) continue;
		sum += idx * dat[i];
		idx--;
	}
	cout << sum;
	return 0;
}