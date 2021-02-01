#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;
const int MOD = 1000000007;
//sort(all(x))とするとソートできるよ

//  操作の特性上数値集合の中にある因数2をワンループで一つ使うことになる。
//  つまり、全体に存在する因数2の数がそのまま答えなので、各数字の持つ因数2の数をカウントして和をとればおｋ。


int main(){
    int N;cin >> N;
    vector<LL> a(N);
    rep(i,N)cin >> a[i];
    LL ans;
    LL tmp;
    rep(i,N){
        while(!(a[i] % 2)){
            ans++;
            a[i] /= 2;
        }
    }
    cout << ans << endl;
}