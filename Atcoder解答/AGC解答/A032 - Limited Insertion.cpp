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



int cal(vector<int>& v){
    if(v.empty())return -2;
    int ind = -1;
    int lim = v.size();
    rep(i,lim){
        if(i+1 == v[i]){
            ind = i;
        }
    }
    if(ind == -1)return -1;

    v.erase(v.begin()+ind);
    return ind;
}

int main() {
    int N;cin >> N;
    vector<int> b(N);
    rep(i,N)cin >> b[i];


    bool ok = true;
    vector<int> ans;
    rep(i,N){
        int tmp = cal(b);
        if(tmp == -1)ok = false;
        else if(tmp == -2)break;
        else ans.push_back(tmp+1);
    }

    if(ok){
        if(!b.empty())cout << -1 << endl;
        else{
            for(int j = ans.size()-1;j >= 0;j--)cout << ans[j] << endl;
        }
    }
    else cout << -1 << endl;
}


// AGC032 A - Limited Insertion

/*
    解説の通り。
    indexと同じ数字を同じ場所に足していって配列を作る操作は、逆から考えると
    「同じindexの数字を取り除いていく作業」である。
    これが完遂できるときが題意の場合であるので、これを調べる。

    この時、現在選べる数字の最も右にあるものから選ぶ必要がある。
    なぜなら、一つ数字を選ぶとそれより後ろにあるものは全部一つ左にindexがずれる。
    すると、それ以降の数字の中には二度と取り出し不能になるものが現れる可能性がある。
    なので、できるだけそうなるものが少なくなるように動くのが最適であり、右側からとっていく必要がある。

    すると、vectorのeraceがO(N)なので、N回数字を取り除くことを考えるとO(N^2)で完遂できる。
*/