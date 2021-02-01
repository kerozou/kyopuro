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
    LL H,W;cin >> H >> W;
    if(H % 3 == 0 || W % 3 == 0)cout << 0 << endl;
    else{
        LL Sa,Sb,Sc;
        LL ans = INF;
        LL tmp1,tmp2;
        for(int i = 1;i<=H;i++){
            if((H-i)%2==0){
                Sa = i*W;
                Sb = (H-i)/2 * W;
                Sc = (H-i)/2 * W;
            }
            else{
                Sa = i*W;
                Sb = (H-i-1)/2 * W;
                Sc = (H-i+1)/2 * W;                
            }
            tmp1 = min(Sa,min(Sb,Sc));
            tmp2 = max(Sa,max(Sb,Sc));
            ans = min(ans,tmp2-tmp1);
        }
        for(int i = 1;i<=H;i++){
            if(W%2==0){
                Sa = i*W;
                Sb = (H-i)*W/2;
                Sc = (H-i)*W/2;
            }
            else{
                Sa = i*W;
                Sb = (H-i)*(W-1)/2;
                Sc = (H-i)*(W+1)/2;                
            }

            tmp1 = min(Sa,min(Sb,Sc));
            tmp2 = max(Sa,max(Sb,Sc));
            ans = min(ans,tmp2-tmp1);
        }
        swap(H,W);
        for(int i = 1;i<=H;i++){
            if((H-i)%2==0){
                Sa = i*W;
                Sb = (H-i)/2 * W;
                Sc = (H-i)/2 * W;
            }
            else{
                Sa = i*W;
                Sb = (H-i-1)/2 * W;
                Sc = (H-i+1)/2 * W;                
            }
            tmp1 = min(Sa,min(Sb,Sc));
            tmp2 = max(Sa,max(Sb,Sc));
            ans = min(ans,tmp2-tmp1);
        }
        for(int i = 1;i<=H;i++){
            if(W%2==0){
                Sa = i*W;
                Sb = (H-i)*W/2;
                Sc = (H-i)*W/2;
            }
            else{
                Sa = i*W;
                Sb = (H-i)*(W-1)/2;
                Sc = (H-i)*(W+1)/2;                
            }

            tmp1 = min(Sa,min(Sb,Sc));
            tmp2 = max(Sa,max(Sb,Sc));
            ans = min(ans,tmp2-tmp1);
        }     

        cout << ans << endl;
    }
}

// ABC062 C - Chocolate Bar
// ・チョコを3分割するが、各ピースは長方形になる。

// チョコを分割する際に解説のように4パターンになる。

// 奇数をキャストするときに　そのまま　奇数/2　とやるとバグることあるっぽい。（1敗）
// あと、桁あふれで死ぬのでLLにしておく（1敗）