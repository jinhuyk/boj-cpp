#include <iostream>
#include <vector>

using namespace std;

int main(void){

    int M, N;
    cin >> M >> N;

    vector<vector<int>> path(N+2, vector<int>(M+2,-1));
    for(int i = 1;i<N+1;i++){
        for(int j = 1;j< M+1;j++){
            cin >> path[i][j];
        }
    }
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    int countDay = 0;

    while(true){
        bool isFinish = true;
        bool isAllZero = true;
        for(int i = 1;i<N+1;i++){
            for(int j = 1;j< M+1;j++){
                if(path[i][j] == 2){
                    path[i][j] = 1;
                }
                if(path[i][j] == 1){
                    isAllZero = false;
                }
                if(path[i][j] == 0){
                    isFinish = false;
                }
                int pointOut = 0;
                if(path[i][j] == 0){
                    for(int k = 0;k<4;k++){
                        if(path[i+dx[k]][j+dy[k]] == -1){
                            pointOut+=1;
                        }
                    }
                }
                if(pointOut == 4){
                    cout << "-1" << endl;
                    return 0;
                }
            }
        }
        if(isAllZero){
            cout << "-1"<< endl;
            return 0;
        }
        if(isFinish){
            cout << countDay << endl;
            return 0;
        }
        countDay++;

        // search
        for(int i = 1;i<N+1;i++){
            for(int j = 1;j< M+1;j++){
                if(path[i][j] == 1){
                    for(int k = 0;k<4;k++){
                        if(path[i+dx[k]][j+dy[k]] == 0){
                            path[i+dx[k]][j+dy[k]] = 2;
                        } 
                    }
                }
            }
        }
    }
}