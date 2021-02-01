// set の使い方

set は　順序付き集合を表すコンテナで、データを順不同に追加すると、その値をキーにして自動的にソートをかましてくれる。
つまり、要素が常にソートされた配列のようなもの。

ただ、内部的には二分探索木で管理しているので、ランダムアクセスはできない。
あと、multisetとは異なり、重複する要素は持てない。

setはデータの追加、削除、検索の処理速度がO(log N)であり高速。
また、vectorは検索するとO(N）だが、あらかじめO(NlogN)でソートしてlower_boundとかで二分探索するとO(logN)となる。
なので、データが動的に追加されないような場合は vector を使ったほうがメモリ効率よく、特に速度差もない。

しかし、ランダムアクセスが必要なく、データ追加が動的に何度も行われ、並行して探索するようなときはsetのほうがいいぞ。

以下に簡単にいろいろ記す

// 宣言
set<int> s;

// 要素の追加
s.insert(1);
s.insert(2);

// 要素の検索
set<int>::iterator itr;;

itr = s.find(1);
if(itr == s.end()) cout << "not found" << endl;
else cout << "found" << endl;

// 要素の削除
s.erase(3);

// 要素の検索の別の方法
if(s.count(3) != 0) cout << "found" << endl;
else cout << "not found" << endl;

// 要素をすべてループする
for(auto itr = s.begin(); itr != s.end();itr++){
    cout << *itr << endl;
}

// そのほか
s.empty() // 空集合かどうかのbool
x.swap(y) // 集合ｘとｙを中身を入れ替える。
s.clear() // 空集合化する。
s.size() // 要素数を取得。
s.count(i) // 要素iの数を返すが、setの時は０か１となる。
