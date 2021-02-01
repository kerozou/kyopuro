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
    int N,R;cin >> N >> R;
    string S;cin >> S;

    vector<bool> ok(N,false);
    rep(i,N)if(S[i] == 'o')ok[i] = true;

    int ans = 0;
    int lim = -1;
    for(int i = N-1;i >= 0;i--){
        if(!ok[i]){
            lim = i;
            break;
        }
    }   

    if(lim == -1){
        cout << 0 << endl;
    }
    else if(R-1 > lim){
        cout << 1 << endl;
    }
    else{
        for(int i = 0;i+R-1 <= lim;i++){
            if(i+R-1 == lim){
                ans++;
                break;
            }
            if(!ok[i]){
                rep(j,R){
                    if(i+j < N)ok[i+j] = true;
                }
                ans++;
            }
            ans++;
        }

        cout << ans << endl;
    }
    


}

// ARC040 B - 直線塗り

/*
    else if のケースで死ぬほど落ちた
*/