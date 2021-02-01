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
    string s,t;cin >> s >> t;
    vector<vector<int>> dp(3010,vector<int>(3010,0));
    
    //dpテーブル
    rep(i,s.size()) rep(j,t.size()){
        if(s[i] == t[j])chmax(dp[i+1][j+1],dp[i][j] + 1);
        chmax(dp[i+1][j+1],dp[i+1][j]);
        chmax(dp[i+1][j+1],dp[i][j+1]);
    }

    //復元
    int i = s.size(); int j = t.size();
    string ans = "";
    while(i > 0 && j > 0){
        
        if(dp[i][j] == dp[i][j-1]){
            j--;
        }
        else if(dp[i][j] == dp[i-1][j]){
            i--;
        }
        else{   // (i,j) <- (i-1,j-1) の時
            ans = s[i-1] + ans;
            i--;
            j--;
        }
    }

    cout << ans << endl;

}

// ifとelseを逆順に並べたら違う答えになった、
// おそらく、これはテーブルを作るときに更新した順にさかのぼらなければいけないということなんだと思う。