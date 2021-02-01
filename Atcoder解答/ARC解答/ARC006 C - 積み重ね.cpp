#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    int N;cin >> N;
    vector<int> ans;

    rep(i,N){
        int w;cin >> w;
        if(ans.empty()){
            ans.push_back(w);
        }
        else{
            int mi = 1e9;
            int ind = -1;
            int lim = ans.size();
            rep(j,lim){
                if(ans[j] >= w){
                    if(mi >= ans[j]){
                        mi = ans[j];
                        ind = j;
                    }
                }
            }
            if(ind == -1){
                ans.push_back(w);
            }
            else{
                ans[ind] = w;
            }
        }
    }   

    cout << ans.size() << endl;
}

// ARC006 C - 積み重ね

/*
    できるだけ小さいダンボールの上に重ねていくとできた。
    なんとなくそんな気がしたけど、証明はうまくできない。
*/