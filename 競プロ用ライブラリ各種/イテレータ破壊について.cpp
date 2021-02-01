//イテレータ破壊について

//ABC138 D - Ki　において、
// エラー　bad_alloc　が出て死亡した際に、原因がわからず四苦八苦したのでメモ

// 下のようなコードを見る。

    rep(i,N){   // 高さのループなので途中でぶったぎるため、最悪高さがNだった時のためにNにしてる.所詮N個のノードを探索して終わりだからO(N)でできる。
        if(high[i].size() == 0)break;
        for(auto d : high[i]){
            rep(j,G[d].size()){
                if(ok[G[d][j]])continue;
                high[i+1].push_back(G[d][j]);                               // ←　これがイテレータ破壊の原因であり、今回の問題児
                ok[G[d][j]] = true;
                tree[d].push_back(G[d][j]);     //  重複なしの無向グラフmapを木構造を作るときのためにつくっておく
            }
        }
    }

// 拡張for文のループ内で high.push_back があるが、vectorのitr自身をループで参照中にvectorにpush_backすると高確率でイテレータ破壊が起きて死ぬらしい。

あと、vectorのメモリ確保についてもメモ

// vector のコピーインストラクタの処理によってメモリが2^100000くらいになってそう　→　案の定reserveであらかじめ確保しといたら改善された。
// しかし、map内部のvectorの方でおそらくメモリがおかしなことになってbad_alloc吐いてる。　→　vectorが誕生したとき、すなわちvector.sizeが1になった時にreserveしてみよう →　駄目だった。

vectorの要素数がとんでもなく多い時には、reserveで確保しとくとよいかも？