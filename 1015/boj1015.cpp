#include <iostream>
#include <vector>
#include <algorithm>

#define pType pair<int, int>
using namespace std;

int main(void){

    int n;
    cin >> n;
    vector<pType> a(n);
    vector<int> p(n);
    for(int i = 0;i<n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end());
    for(int i = 0;i<n;i++) p[a[i].second] = i;
    for(auto i : p) cout << i << ' ';
}