// ACL の FenwickTree で区間更新等するためのメモ

fenwickTree は二つの関数をもっていて、
    ・add := 1点更新    O(logN)
    ・sum := 区間和     O(logN)


1.配列を v として、とりあえず受け取る。
    vector<LL> v(N);

2.v の差分をfenwickTreeで用意する。コンストラクタが O(N)
    fenwick_tree<LL> fw(N);
    fw[i] = v[i] - v[i-1]   で定義して初期化。（fw[0] = v[0];　としておく。）O(NlogN)

3.v[i] は fw.sum(0,i+1) で表現できる。
    差分を次々足していくと分かる。
    fw[5] = v[5] - v[4];
    fw[4] = v[4] - v[3];
    fw[3] = v[3] - v[2];
    fw[2] = v[2] - v[1];
    fw[1] = v[1] - v[0];
    fw[0] = v[0];
    より v[5] = fw[0] ~ fw[5] なのは明らか。

4.以上より、v の [2,4] に +3 したい場合を例にとって考えてみる。
    fw.add(2,3);
    fw.add(4+1,-3);
    
    この状態だと、fw は [0,0,2,0,0,-2,0] となる。
    この時、v[i] を考えると、
    v[2] = 2;
    v[3] = fw[0] + fw[1] + fw[2] + fw[3] = 2;
    v[4] = fw[0~4] = 2;
    v[5] = fw[0~5] = 2 -2 = 0;
    となり、きちんと区間更新を O(logN) で行えていることが分かる。

5.以上まとめ

    // コンストラクタ
    vector<LL> v(N);
    fenwick_tree<LL> fw(N);

    // 初期化
    rep(i,N){
        if(i == 0)fw.add(0,v[0]);
        else fw.add(i,v[i]-v[i-1]);
    }

    // 区間更新 [i,j] に +w するとき
    fw.add(i,w);
    fw.add(j+1,-w);

    // 更新後の配列から1点の数値を得たい時  O(logN)
    LL ans = v[i] + fw.sum(0,i+1);

    // 更新後の配列の区間和が欲しい時
    更新後の fenwick の実数値（つまりは、v改 的な配列）を常にもっていないと、各更新後に区間和をO(logN)で取れない。
    なので、fenwick の更新ごとに常に fenwick_vkai を持っていないといけないことになる。
    これは二本BITを持って、あれこれするとできるらしい。
    これについては今まとめてる時間がないので今度にする。

