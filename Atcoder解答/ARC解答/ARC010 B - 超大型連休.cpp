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
    vector<int> cal(13,0);
    for(int i = 1;i <= 12;i++){
        if(i == 2)cal[i] = 29;
        else if(i == 4 || i == 6 || i == 9 || i == 11)cal[i] = 30;
        else cal[i] = 31;
    }

    vector<bool> ok(368,false);
    for(int i = 1;i <= 366;i++){
        if(i % 7 == 1 || i % 7 == 0)ok[i] = true;
    }


    int N;cin >> N;
    

    rep(i,N){
        int M, D;
        scanf("%d/%d", &M, &D);

        int in = D;
        for(int j = 1;j < M;j++){
            in += cal[j];
        }
        
        while(ok[in]){
            if(in == 366)break;
            in++;
        }
        ok[in] = true;
    }




    int ans = 2;
    int ct = 0;
    rep(i,367){
        if(i == 0)continue;

        if(ok[i]){
            ct++;
        }
        else{ 
            ct = 0;
        }
        ans = max(ans,ct);
    }

    cout << ans << endl;
}


// ARC010 B - 超大型連休

/*
    無限にバグり散らかしてRE出まくってしにかけた。
    入力文字列の中に取り除くべきものが入ってて、なおかつ stoi() で恐らく未定義エラーか何か出まくってRE出てたと思う。
    scanf で直接int を二つ獲得するようにして、累積和計算やめたらWAもREも消えて通った。
    
    なんか良く分からないしスッキリしないけど、こういうヤバい時はscanf使ってみる。
*/