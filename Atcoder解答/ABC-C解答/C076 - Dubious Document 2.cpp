#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

std::string ReplaceString
(
      std::string String1   // 置き換え対象
    , std::string String2   // 検索対象
    , std::string String3   // 置き換える内容
)
{
    std::string::size_type  Pos( String1.find( String2 ) );
 
    while( Pos != std::string::npos )
    {
        String1.replace( Pos, String2.length(), String3 );
        Pos = String1.find( String2, Pos + String3.length() );
    }
 
    return String1;
}

int main(){
    string Sd;cin >> Sd;
    string T;cin >> T;
    vector<string> L(0);
    int N = Sd.size();
    int Tsize = T.size();
    bool ok = true;
    string tmp = Sd;
    rep(i,N-Tsize+1){
        ok = true;
        rep(j,Tsize) if(ok) if(!(Sd[i+j] == '?' || Sd[i+j] == T[j])) ok = false;
        if(ok){
            tmp = Sd;
            rep(k,Tsize){
                tmp[i+k] = T[k];
            }
            tmp = ReplaceString(tmp,"?","a");
            L.push_back(tmp);
        }
    }
    sort(all(L));
    if(L.size() == 0)cout <<"UNRESTORABLE"<<endl;
    else cout << L[0] << endl;

}

// Tを一つずつずらして、Sd内を掃けば終わり。
// やってることは単純