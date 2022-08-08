#include <iostream>
using namespace std;

int check[100001] = { 0, }, apt[1000][1000], blst[1000][1000];
int sumBlst = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ay = 0, ax = 0, by = 0, bx = 0, temp = 0;
	cin >> ay >> ax;
	for (int y = 0; y < ay; y++) {
		for (int x = 0; x < ax; x++) {
			cin >> apt[y][x];
			check[apt[y][x]]++;
		}
	}
	cin >> by >> bx;
	for (int y = 0; y < by; y++) {
		for (int x = 0; x < bx; x++) {
			cin >> blst[y][x];
			sumBlst += check[blst[y][x]];
			check[blst[y][x]] = 0;
		}
	}
	int size = ay * ax;
	cout << sumBlst;
	cout << '\n' << size - sumBlst;

	return 0;
}