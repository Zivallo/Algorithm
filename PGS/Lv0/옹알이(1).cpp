#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string baby[4]={"aya","ye","woo","ma"};
    for(int i=0;i<babbling.size();i++){
        int len = 0;
        for(int j=0;j<4;j++){
            int ret = -1;
            while(1){
                ret = babbling[i].find(baby[j],ret+1);
                if(ret==-1)break;
                len+=baby[j].length();
            }
        }
        if(len==babbling[i].length()) answer++;
    } 
    return answer;
}