#include <iostream>

#include <queue>

using namespace std;
struct pos{
    int x;
    int y;
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int m,n;
void dfs(int x, int y, int path[][51]){

    path[x][y]= 2;
    for(int i =0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >=m || nx <0 || ny >=n || ny <0) continue;
        if(path[nx][ny]==1){
            dfs(nx,ny,path);
        }
    }
}
int main(void){
    int tc;

    cin >> tc;
    for(int c = 0;c<tc;c++){

        int path[51][51] = {0};
        int k;
        int bug = 0;
        queue<pos> p;
        cin >> m >> n>>k;
        for(int i = 0;i<k;i++){
            int x, y;
            cin >> x >> y;
            path[x][y] = 1;
            p.push({x,y});
        }
        while(!p.empty()){
            int x = p.front().x;
            int y = p.front().y;

            p.pop();
            if(path[x][y] == 1){
                bug++;
                dfs(x,y,path);
            }
            
        }
        cout << bug << endl;


    }
}