    #include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;
//sort(all(x))とするとソートできるよ

int main(){
    double W,H,x,y;cin >> W >> H >> x >>y ;
    int ans;
    if(W/2 == x && H/2 == y){
        ans = 1;
    }
    else{
        ans = 0;
    }
    cout << H*W/2.0 << ' ' << ans << endl;
}
