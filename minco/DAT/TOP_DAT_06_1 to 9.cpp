#include <iostream>
using namespace std;

int type, N, cnt[1000];
int input[1000];

void type1(int input1[])
{
	int cnt[1000] = { 0, };
	for (int i = 0; i < N; i++) {
		cnt[input1[i]]++;
	}
	for (int i = 1; i <= 9; i++) {
		cout << i << ":" << cnt[i] << "개\n";
	}
}
int type2(int input1[])
{
	int cnt[1000] = { 0, };
	for (int i = 0; i < N; i++) {
		cnt[input1[i]]++;
	}
	for (int i = 1; i <= 9; i++) {
		if (cnt[i] > 1) return 0;
	}
	return 1;
}


int main() {
	cin >> type >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	if (type == 1) type1(input);
	if (type == 2) {
		if (type2(input)) cout << "중복없음";
		else cout << "중복발견";
	}

	return 0;
}