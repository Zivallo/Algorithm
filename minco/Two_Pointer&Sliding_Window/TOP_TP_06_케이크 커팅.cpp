#include <iostream>
#include <string>
using namespace std;

string cake;
int N, sCnt, kCnt;

int main() {
	cin >> N;
	cin >> cake;
	for (int i = 0; i < N / 2; i++) {
		if (cake[i] == 'k') kCnt++;
		if (cake[i] == 's') sCnt++;
	}
	if (kCnt == sCnt) {
		cout << 1 << "\n" << N / 2;
		return 0;
	}
	for (int i = 0; i < N / 2; i++) {
		if (cake[N / 2 + i] == 'k') kCnt++;
		else sCnt++;
		if (cake[i] == 'k') kCnt--;
		else sCnt--;
		if (kCnt == sCnt) {
			cout << 2 << "\n" << i + 1 << " " << 1 + i + N / 2;
			break;
		}
	}
	return 0;
}