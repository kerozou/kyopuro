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
    string S;cin >> S;
    vector<LL> ct;
    char tmp = S[0];
    LL p = 1;
    LL N = S.size();
    rep(i,N){
        if(i == 0)continue;
        if(tmp == S[i]){
            p++;
            if(i == N-1)ct.push_back(p);
        }
        else{
            ct.push_back(p);
            p = 1;
            tmp = S[i];
            if(i == N-1)ct.push_back(p);
        }
    }

 //   rep(i,ct.size())cout << ct[i] << " ";
 //   cout << endl; 

    LL ans = 0;
    LL lim = ct.size();
    if(N == 1){
        ans = 1;
    }
    else{
        rep(i,lim){

        if(S[0] == '<'){
            if(i == lim-1)
                LL a = ct[i];
                ans += a*(a+1)/2;
            }
            else{
                LL a = ct[i];
                LL b = ct[i+1];
                if(a < b)ans += a*(a-1)/2 + b*(b+1)/2;
                else ans += a*(a+1)/2 + b*(b-1)/2;
            }
            i++;
        }
        else{
            if(i == 0){
                LL a = ct[i];                
                ans += a*(a+1)/2;
            }
            else{
                if(i == lim-1){
                    LL a = ct[i];                
                    ans += a*(a+1)/2;
                }
                else{
                    LL a = ct[i];
                    LL b = ct[i+1];
                    if(a < b)ans += a*(a-1)/2 + b*(b+1)/2;
                    else ans += a*(a+1)/2 + b*(b-1)/2;
                }
                i++;
            }
    //        cout << ans << " ";
        }

    }
    //cout << endl;
    }

    cout << ans << endl;
}

