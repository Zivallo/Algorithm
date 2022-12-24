#include <iostream>
using namespace std;
int T, A, B;
int arr[1001];
void mk() {
	arr[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		arr[i] += arr[i - 1];
		if (9 < i && i < 100) 
		{ 
			if (i / 10 != i % 10)continue; 
		}
		if (100<i && i < 1000) 
		{ 
			if (i / 100 != i % 10)continue; 
		}
		int ii = i * i;
		if (ii < 10)
		{
			arr[ii]++;
		}
		if (10<=ii && ii < 100)
		{
			if ((ii) / 10 == (ii) % 10)arr[ii]++;
		}
		if (100<= ii && ii < 1000)
		{
			if ((ii) / 100 == (ii) % 10)arr[ii]++;
		}
	}
	arr[1000] = arr[999];
}
void solve() {
	mk();
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> A >> B;
		cout << "#" << t << " " << arr[B] - arr[A - 1] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}