#include <string>
#include <vector>

using namespace std;

int getNum(int num) {
    if (num == 1)return 1;
    int cnt = 0;
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0)cnt++;
        if (num % i == 0 && i * i < num)cnt++;
    }
    return cnt;
}
int solution(int number, int limit, int power) {
    int answer = 0;
    for (int i = 1; i <= number; i++) {
        int tmp = getNum(i);
        if (tmp > limit) answer += power;
        else {
            answer += tmp;
        }
    }
    return answer;
}