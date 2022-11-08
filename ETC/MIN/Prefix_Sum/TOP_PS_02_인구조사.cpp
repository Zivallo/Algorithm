#include <iostream>
using namespace std;

int N, M, Q, A, B;
int blg[110000], acc[110000];

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		blg[a] = b;
	}
	for (int i = 1; i <= M; i++) {
		acc[i] = acc[i - 1] + blg[i];
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> A >> B;
		cout << acc[B] - acc[A - 1] << '\n';
	}
	return 0;
}