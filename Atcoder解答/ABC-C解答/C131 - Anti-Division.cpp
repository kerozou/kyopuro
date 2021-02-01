#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;

// CでもDでも割り切れない　=　Cで割れない　かつ　Dでわれない　なので、否定の「少なくともCかDで割れる」を考える。 CまたはDで割れる
// それぞれCで割れないときをU(C)とあらわすと、U(CかつD)　=　全体　-　｛　U（C-）＋　U(D-)　｝　＋　U(CD-）　とあらわせる 最小公倍数

// B/C - A/C でU(C-)が出るので、D-も同様に求める。　かつのときは、B/C+D　－　A/C+D　でおｋ
// 全体は　B-A+1　でおｋ

auto GCD(auto a,auto b){ //ユークリッドの互助法で最大公約数
    if (a%b == 0){
        return b;
    }
    else {
        return GCD(b,a%b);
    }
}

auto LCM(auto a,auto b){ //GCDを使って最小公倍数を求める
    return a*b / GCD(a,b);
}

int main(){
    LL A,B,C,D ;cin >> A >> B >> C >> D;
    LL sum,U,Ucb,Udb,Ucadb,Lcm;
    U = B-A+1;
    Ucb = B/C - (A-1)/C ;
    Udb = B/D - (A-1)/D ;
    Lcm = LCM(C,D);
    Ucadb = B/Lcm - (A-1)/Lcm;
    sum = U - (Ucb + Udb) + Ucadb ;
    cout << sum << endl;
}