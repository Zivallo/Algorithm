#include <iostream>
#include <string>
using namespace std;

string map[7];

int is1(int y, int x) {
	int drY[8] = { -1,-2,1,2,0,0,0,0 };
	int drX[8] = { 0,0,0,0,-1,-2,1,2 };
	for (int i = 0; i < 8; i++) {
		int ny = y + drY[i];
		int nx = x + drX[i];
		if (ny < 0 || nx < 0 || ny >= 7 || nx >= 7) continue;
		if (map[ny][nx] == '1') return 1;
	}
	return 0;
}
int is2(int y, int x) {
	int drY[12] = { -1,-2,-3,1,2,3,0,0,0,0,0,0 };
	int drX[12] = { 0,0,0,0,0,0,-1,-2,-3,1,2,3 };
	for (int i = 0; i < 12; i++) {
		int ny = y + drY[i];
		int nx = x + drX[i];
		if (ny < 0 || nx < 0 || ny >= 7 || nx >= 7) continue;
		if (map[ny][nx] == '2') return 1;
	}
	return 0;
}

int main()
{
	for (int y = 0; y < 7; y++) {
		cin >> map[y];
	}
	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 7; x++) {
			if (map[y][x] == '1')
				if (is1(y, x)) {
					cout << "fail";
					return 0;
				}
			if (map[y][x] == '2')
				if (is2(y, x)) {
					cout << "fail";
					return 0;
				}
		}
	}
	cout << "pass";
	return 0;
}
