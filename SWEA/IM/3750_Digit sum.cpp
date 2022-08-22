#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int T = 0;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        string num;
        cin >> num;
        int sum = 10;
        while (sum >= 10) {
            sum = 0;
            for (int j = 0; j < num.size(); j++) {
                sum += (int)(num[j] - '0');
            }
            num = to_string(sum);
        }
        cout << "#" << i << " " << sum << '\n';
    }
    return 0;
}