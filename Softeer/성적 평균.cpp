#include<iostream>
using namespace std;
int N, K;
float list[1100000];

int main(int argc, char** argv)
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		list[i] += list[i - 1];
	}
	for (int i = 0; i < K; i++) {
		int s, e;
		cin >> s >> e;
		float temp = list[e] - list[s - 1];
		float ans = temp / (e - s + 1);
		cout << fixed;
		cout.precision(2);
		cout << ans << '\n';
	}
	return 0;
}