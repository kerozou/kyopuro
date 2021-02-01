#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    int N;cin >> N;
    vector<int> A(N);
    vector<vector<pair<int,int>>> xy(N);
    rep(i,N){
        cin >> A[i];
        rep(j,A[i]){
            int x,y;cin >> x >> y;
            x--;
            xy[i].push_back({x,y});
        }
    }

    //bit_flag集をvectorに格納
    vector<int> bit_flag(15);
    rep(i,15){
        bit_flag[i] = (1 << i);
    }

    int ans = 0;
    for(int bit = 0;bit < (1 << N);++bit){
        bool ok = true;

        rep(i,N)rep(j,A[i]){
            if(bit & bit_flag[i]){      // 正直者
                rep(j,A[i]){
                    int x = xy[i][j].F;
                    int y = xy[i][j].S;
                    if((bit >> x) % 2 != y)ok = false;         
                }
            }
        }
        if(ok)ans = max(ans,__builtin_popcount(bit));
    }
    cout << ans << endl;
}

