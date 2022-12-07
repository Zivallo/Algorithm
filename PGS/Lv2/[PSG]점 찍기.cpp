#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long dd = d;
    long long answer = 0;
    for (long long y = 0; y <= d; y += k)
    {
        long long x = sqrt(dd * dd - y * y);
        answer += (floor(x / k) + 1);
    }

    return answer;
}