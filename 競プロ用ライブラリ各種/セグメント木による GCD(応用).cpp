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

auto GCD(auto a, auto b) { //ユークリッドの互助法で最大公約数
    if(a % b == 0)return b;
    else return GCD(b, a % b);
}
auto LCM(auto a, auto b) { //GCDを使って最小公倍数を求める
    auto g = GCD(a, b);
    return (a / g) * b;
}


int n;              // 配列サイズ
vector<LL> seg;     // セグ木

void segch(int i,int x){    // 配列i番目要素をxに変更
    i += (n-1);
    seg[i] = x;
    while(i > 0){
        i = (i-1)/2;
        seg[i] = GCD(seg[2*i+1],seg[2*i+2]);    //**0
    }
}

LL getq_sub(int a,int b,int k,int l,int r){ 
    // k:現在見ているノードの位置  [l,r):dat[k]が表している区間
    if(r <= a || b <= l)return -1;             //**1
    else if(a <= l && r <= b)return seg[k];     
    else{                                       
        int ind = (l+r)/2;
        int vl = getq_sub(a,b,2*k+1,l,ind);
        int vr = getq_sub(a,b,2*k+2,ind,r);
        if(vl == -1)vl = vr;                    //check2
        if(vr == -1)vr = vl;                    //check3
        return GCD(vl,vr);                      //**4
    }
}


LL getq(int a,int b){     // [a,b) の区間でminを返す
    return getq_sub(a,b,0,0,n);
}



int main() {
    cin >> n;
    vector<LL> A(n);rep(i,n)cin >> A[i];
    LL bk = A[n-1];                             //check5

    // 配列の要素数を 2^x 個にするためにINFで埋める  
    rep(i,32){
        if(n <= pow(2,i)){
            n = pow(2,i);
            break;
        }
    }
    int st = A.size();
    for(int i = st;i < n;i++)A.push_back(bk);  //**6

    // seg木の配列初期化
    seg.resize(2*n-1);rep(i,2*n-1)seg[i] = 1; //**7
    rep(i,n)segch(i,A[i]);

    LL ans = 1;

    
    rep(i,n){
        if(i == 0){
            ans = max(ans,getq(1,n));
        }
        else if(i == n-1){
            ans = max(ans,getq(0,n-1));
        }
        else{
            LL tmp = GCD(getq(0,i),getq(i+1,n));
            ans = max(ans,tmp);
        }
    }

    cout << ans << endl;

}


// セグ木を使った GCD on Blackboard 
// **は元からあるものを変形
// check は追加要素


/*
    **0:min → GCD
    **1:範囲外の時に INF → -1 とすることでフラグ化
    check2,3:範囲外の時-1を検出するので、その場合はもう一方の値をGCDの値として親に渡す。
    **4:min → GCD
    check5:入力配列の最右の値を確保。余った余計なスペースをその値で埋めとく→GCDの値を一定に保つ。
    **6:INF → 配列の最右の要素
    **7:INF → 1     GCDの最小値が1なので
*/