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
    int N;cin >> N;
    deque<LL> a;
    LL tmp;
    int i = 0;
    if(N%2 == 0){
        while(i != N){
            if(i%2 == 0){
                cin >> tmp;
                a.push_back(tmp);
                i++;
            }
            else{
                cin >> tmp;
                a.push_front(tmp);
                i++;
            }
        }
    }
    else{
        while(i != N){
            if(i%2 == 0){
                cin >> tmp;
                a.push_front(tmp);
                i++;
            }
            else{
                cin >> tmp;
                a.push_back(tmp);
                i++;
            }
        }
    }
    rep(i,N)cout << a[i] << " ";
    cout << endl;
}

// ソートはO(NlogN)なので、純粋にN回ソートすると、O(N^2logN)になって間に合わないので、ソートがどういう風に動いているか考える。
// すると、Nの偶奇によって、最終形が異なることに気づく。
// vector だとpush_frontがO(N)かかり、結局O(N^2)になりそうなので、dequeを使って作る。
// dequeはpush_frontがO(1)でできるので、安心。