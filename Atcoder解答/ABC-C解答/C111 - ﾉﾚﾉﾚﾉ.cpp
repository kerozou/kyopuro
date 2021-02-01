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

//ifと配列ソートで偶奇分けして第２頻値を探そうとしたけど、バグ塗れで積んだのでmapで実装　→　めちゃくちゃ楽だった
//なので、備忘録としてmapの基本的な使い方も記しておく。

//mapの使い方とは

//1,mapの概要
//  基本的に　map<int,int> とかって作る。
//  first はkey　で、second　はvalue。これはmapがpairを使ってることによるらしい。
//  mapはvectorやstringのように、indexのメモリの増え方が一定でないらしく、順番に添え字の値を増やすみたいなことができない。
//  なので、イテレータを使って、
//   for(auto itr = map.begin() ; itr != map.end() ;itr++)
//  みたいなitrループを作って、全探索する。

//2,アロー演算子
//  -> の矢印のような表記をアロー演算子といい、左側に構造体のポインタ、右側に構造体のメンバ名を用意する。
//  map　の場合は　構造体のポインタがitr、構造体のメンバが（first、second）のいずれかであると考えられる。
// なので、 cnt = itr -> second とすると、cntにはmapのitr番目のvalueが追加される。

int main(){
    int n;cin >> n;
    vector<int> v(n);
    rep(i,n){
        cin >> v[i];
    }
    map<int,int> even,odd;
    rep(i,n){
        if(i % 2 == 0)odd[v[i]]++;
        else even[v[i]]++;
    }
    int even_1 = 0,even_2 =0,odd_1 = 0,odd_2 = 0;
    int e1 = 0,e2 = 0,o1 = 0,o2 = 0;

    //even mode1 roop
    int cnt = 0;
    for(auto itr = even.begin();itr != even.end();itr++){       //itr は　!= end としなければならないことに注意。
        if(itr -> second > cnt){
            cnt = itr -> second;
            even_1 = itr -> first;
        }
    }
    e1 = cnt;
    
    cnt = 0;
    for(auto itr = even.begin();itr != even.end();itr++){
        if(itr -> second > cnt && itr -> first != even_1){
            cnt = itr -> second;
            even_2 = itr -> first;
        }
    }
    e2 = cnt;

    cnt = 0;
    for(auto itr = odd.begin();itr != odd.end();itr++){
        if(itr -> second > cnt){
            cnt = itr -> second;
            odd_1 = itr -> first;
        }
    }
    o1 = cnt;

    cnt = 0;
    for(auto itr = odd.begin();itr != odd.end();itr++){
        if(itr -> second > cnt && itr -> first != odd_1){
            cnt = itr -> second;
            odd_2 = itr -> first;
        }
    }
    o2 = cnt;

    if(even_1 == odd_1){
        cout << min(n-e1-o2,n-e2-o1) << endl;
    }
    else{
        cout << n-e1-o1 << endl;
    }
}