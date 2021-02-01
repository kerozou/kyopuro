//map 使い方

//ABC111　C より

    ifと配列ソートで偶奇分けして第２頻値を探そうとしたけど、バグ塗れで積んだのでmapで実装　→　めちゃくちゃ楽だった
    なので、備忘録としてmapの基本的な使い方も記しておく。

//mapの使い方とは

//   1,mapの概要
        基本的に　map<int,int> とかって作る。
        first はkey　で、second　はvalue。これはmapがpairを使ってることによるらしい。
        mapはvectorやstringのように、indexのメモリの増え方が一定でないらしく、順番に添え字の値を増やすみたいなことができない。
        なので、イテレータを使って、
        　for(auto itr = map.begin() ; itr != map.end() ;itr++)
        みたいなitrループを作って、全探索する。

//    2,アロー演算子
        -> の矢印のような表記をアロー演算子といい、左側に構造体のポインタ、右側に構造体のメンバ名を用意する。
        map　の場合は　構造体のポインタがitr、構造体のメンバが（first、second）のいずれかであると考えられる。
        なので、 cnt = itr -> second とすると、cntにはmapのitr番目のvalueが追加される。

//    mp.find(キー) で、キーが mp に設定されているかどうかを調べることが出来る。 
//      キーが設定されている場合は、キーと値のペアへのイテレータを返す。 
//      キーが設定されていない場合は、end() へのイテレータを返す。

//    lower_bound(キー) : iterator
//      lower_bound(キー) は、引数で指定されたキー以上のキーを持つ最初のノードへのイテレータを返す。

//    erase(キー) : size_t
//      mp から、キー："abc" の要素を削除したい場合は mp.erase("abc") とすればよい。直感的で簡単だ。 
//      存在しないキーを指定した場合は、無視され何も起こらない。

//    clear() : void
//    empty() : bool
//    size() : size_t  も使える

///////
//一応下にC111を張っておく

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


// 拡張for文
    std::map<std::string, int> mp;       // mp を生成
    mp にキー、値のペアを複数設定;
    for(auto x : mp) {
        std::cout << x.first << " " << x.second << "\n";
    }