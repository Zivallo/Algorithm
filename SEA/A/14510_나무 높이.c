#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N, maxiLen;
int tree[110];
void input() {
	maxiLen = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tree[i]);
		if (tree[i] > maxiLen) maxiLen = tree[i];
	}
}
void solve() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		input();
		int oddCnt = 0, evenCnt = 0;
		for (int i = 0; i < N; i++) {
			int temp = maxiLen - tree[i];
			evenCnt += temp / 2;
			oddCnt += temp % 2;
		}
		int evenLen = 2 * evenCnt;
		int oddLen = 2 * oddCnt - 1;
		int result = 0, temp = 0;
		if (evenLen > oddLen) result = evenLen;
		else result = oddLen;
		while (1) {
			evenCnt--;
			oddCnt += 2;
			temp = 0;
			evenLen = 2 * evenCnt;
			oddLen = 2 * oddCnt - 1;
			if (evenLen > oddLen) temp = evenLen;
			else temp = oddLen;
			if (result < temp) break;
			result = temp;
		}
		printf("#%d %d\n", t, result);
	}
}
int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}