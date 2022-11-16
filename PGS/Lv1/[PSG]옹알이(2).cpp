#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string baby[4]={"aya","ye","woo","ma"};
    int blen[4]={3,2,3,2};
    for(int i=0;i<babbling.size();i++){
        int len=0;
        for(int j=0;j<4;j++){
            int ret = babbling[i].find(baby[j],0);
            int xret = ret;
            while(ret!=-1){
                len += blen[j];
                ret = babbling[i].find(baby[j],ret+1);
                if(xret+blen[j]==ret) break;
                xret = ret;
            }
        }
        if(len == babbling[i].length()) answer++;
    }
    return answer;
}