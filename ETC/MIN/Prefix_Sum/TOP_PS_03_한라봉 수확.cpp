#include <iostream>
#include <algorithm>
using namespace std;

int map[110000], acc[110000], idx[110000];
int N, K, maxCnt = -1;

void getRight() {
    int left = 1, right = 2;
    while (right < N) {
        int sum = (acc[N] - acc[left]) + (acc[N] - acc[right]) - map[right];
        if (sum > maxCnt) maxCnt = sum;
        right++;
    }
}
void getLeft() {
    int left = N - 1, right = N;
    while (left > 1) {
        int sum = (acc[left] - map[left]) + (acc[right] - map[right] - map[left]);
        if (sum > maxCnt) maxCnt = sum;
        left--;
    }
}
int getCenter() {
    int left = 1, right = N;
    int sum = (acc[N / 2] - acc[left - 1]) + (acc[right] - acc[N / 2 - 1]);
    if (sum > maxCnt) maxCnt = sum;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> map[i];
        idx[map[i]] = i;
        acc[i] = acc[i - 1] + map[i];
    }
    getLeft();
    getRight();
    getCenter();
    cout << maxCnt;
    return 0;
}