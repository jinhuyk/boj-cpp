#include <iostream>
#include <queue>
using namespace std;

struct tomato{
    int x;
    int y;
    int d;
};

int main(void){
    int path[1001][1001];
    int cnt=0;
    int zero = 0;
    int maxDepth = 0;
    int m, n;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    queue <tomato> v;

    cin >> m >> n;

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> path[j][i];
            if(path[j][i] == 1){
                v.push({j,i,0});
            }
            if(path[j][i] == 0){
                zero++;
            }
        }
    }
    if(zero==0){
        cout << 0<<endl;
        return 0;
    }

    while(!v.empty()){
        int x = v.front().x;
        int y = v.front().y;
        int d = v.front().d;

        v.pop();
        maxDepth = max(maxDepth, d);
        for(int i =0 ; i<4;i++){
            int nx = x+ dx[i];
            int ny = y + dy[i];
            if(nx >= m || nx <0 || ny >=n|| ny <0 )continue;
            if(path[nx][ny] == 1 || path[nx][ny] == -1 ) continue;
            
            path[nx][ny] = 1;
            cnt++;
            v.push({nx,ny,d+1});
            

        }
    }
    if(cnt == zero) cout << maxDepth << endl;
    else cout << -1 << endl;
}