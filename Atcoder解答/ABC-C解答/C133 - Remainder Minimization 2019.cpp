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

//連続する2019個の整数の中には、必ず2019の倍数があるという事実を利用する。
//つまり、R-Lが2019以上の時、mod2019は必ず0 となるということ。
//なので、R-L<2019 の時に、全探索すればよい。

//また、modの性質として、「和・差・積で閉じている」というものがあり、これのうちの積が今回の問題。
int main(){
    LL L,R;cin >> L >> R;
    if(R-L >= 2019){
        cout << 0 << endl;
    }
    else{
        LL mi = 2018;
        LL r;
        LL l;
        rep(i,R-L){
            l = (L + i) % 2019;
            for(int j = i+1;j <= R-L;j++){
                r = (L + j) % 2019;
                mi = min(mi,(l * r) % 2019);
            }
        }
        cout << mi << endl;
    }
}