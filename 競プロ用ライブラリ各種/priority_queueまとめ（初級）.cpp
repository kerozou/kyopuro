//  プライオリティー・キューまとめ　（priority_queue)

//  次のような操作が行えるデータ構造をプライオリティーキューという。

・数を追加する
・最小（最大）の数値を取り出す（値を取得し、削除する）

// これらを二分木を用いて表現するのがヒープというデータ構造。
// ヒープに関しては蟻本参照（実際に実装するのはめんどいので）

// 実際に使うときには、std::priority_queue を使おう！
// 以下、簡単な priority_queue の使用例

#include <bits/stdc++.h>
using namespace std;

int main(){
    //　宣言
    priority_queue<int> pque;

    //  要素の追加
    pque.push(3);
    pque.push(5);
    pque.push(1);

    //　空になるまでループ
    while (! pque.empty() ){
        //　最大値の取得および削除
        cout << pque.top() << endl;
        pque.pop();
    }
}

///////

// stdのpriority_queueは降順に取り出してしまうので、昇順に取り出したいときは

    priority_queue<int,vector<int>,greater<int>> que;

// と定義することで同じように.topで最小値を取り出せる。

