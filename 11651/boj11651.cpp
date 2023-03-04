// y pos 증가순


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp (pair<int,int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;

}
int main(void){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> pos(n);
    for(int i = 0;i<n;i++){
        int x,y;
        cin >> x >> y;
        pos[i].first = y;
        pos[i].second = x;
    }
    sort(pos.begin(), pos.end());

    for(auto i : pos){
        cout << i.second << " " << i.first << "\n";
    }

}
