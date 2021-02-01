#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define INF 1000000000
typedef long long int LL;


int main(){
    int N,K; cin >> N >> K;
    vector<LL> h(N);

    rep(i,N){
       cin >> h[i];
    }

    sort(all(h));

  
    LL temp = INF;
    rep(j,N-K+1){
        temp = min(temp,h[j+K-1] - h[j]);
    }

    cout << temp << endl;
    
}