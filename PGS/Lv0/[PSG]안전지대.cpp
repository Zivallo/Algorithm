#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int cnt=0;
    int drY[8]={-1,1,0,0,-1,-1,1,1};
    int drX[8]={0,0,-1,1,-1,1,-1,1};
    
    for(int y=0;y<board.size();y++){
        for(int x=0;x<board[0].size();x++){
            if(board[y][x]==1){
                for(int i=0;i<8;i++){
                    int ny = y+drY[i];
                    int nx = x+drX[i];
                    if(ny<0||nx<0||ny>=board.size()||nx>=board[0].size())  continue;
                    if(board[ny][nx]!=0)continue;
                    board[ny][nx]=2;
                    cnt++;
                }
                cnt++;
            }
        }
    }
    answer = board.size()*board[0].size()-cnt;
    return answer;
}