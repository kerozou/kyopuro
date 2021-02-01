#include <bits/stdc++.h>
using namespace std;

// 難しすぎてやばい。
// DFS（深さ優先探索）で再帰関数を使って処理する。
// そもそも、再帰関数のきちんとした使い方をマスターできてないから、その辺をその都度復習する。

// イメージ的には終わりからの逆算だけど、
// 1.終了条件のセット
// 2.再帰処理をreturnや代入で行う
// 3.各再帰処理の回の返り値用のreturnを用意しておく。
// ことを意識。

// DFSを書くときは再帰処理をX^nのX個分だけ縦に並べて書いてあげる。
// すると、
// 1 再帰を通るもの
// 2 再帰を通らないもの
// が現れて、必然的に2択が生まれて、2^nの探索が可能に。

// 4つの場合は4^n探索に。


int N,A,B,C;
vector<int> L;

void chmin(int &x,int y){
    if(x > y){
        x = y;
    }
}

int DFS(int i,int a,int b,int c){

    if(i == N){ //終了条件
        if(!a || !b || !c){
            return 100000;
        }
        else {
            return abs(a - A) + abs(b - B) + abs(c - C);
        }
    }
    int res = DFS(i+1,a,b,c);
    chmin(res,DFS(i+1,a + L[i],b,c) + (a ? 10 : 0));
    chmin(res,DFS(i+1,a,b + L[i],c) + (b ? 10 : 0));
    chmin(res,DFS(i+1,a,b,c + L[i]) + (c ? 10 : 0));

    return res;

}


int main(){
    cin >> N >> A >> B >> C;
    L.resize(N);
    for(int j = 0; j < N ;j++){
        cin >> L[j];
    }

    cout << DFS(0,0,0,0) << endl;
}

// 20190516 AC済みっちゃ済みだけど、9割方丸写しなので、何回も復習しよう。