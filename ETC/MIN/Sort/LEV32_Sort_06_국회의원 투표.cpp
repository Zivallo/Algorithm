#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct INFO {
	int to;
	string name;
};

INFO info[100];
int cnt[100], cntMax = -1, maxidx;

int main() {
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < c; i++) {
		cin >> info[i].to >> info[i].name;
	}
	for (int i = 0; i < c; i++) {
		cnt[info[i].to]++;
	}
	for (int i = 0; i < n; i++) {
		if (cnt[i] > cntMax) {
			cntMax = cnt[i];
			maxidx = i;
		}
	}
	for (int i = 0; i < c; i++) {
		if (info[i].to == maxidx) cout << info[i].name << " ";
	}

	return 0;
}