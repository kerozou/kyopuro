auto GCD(auto a,auto b){ //ユークリッドの互助法で最大公約数
    if (a%b == 0){
        return b;
    }
    else {
        return GCD(b,a%b);
    }
}

auto LCM(auto a,auto b){ //GCDを使って最小公倍数を求める
    auto g = GCD(a,b);
    return (a/g)*b;  // (a*b)/GCD(a,b) なんだけど、こうしないとa,b=INFとかだとはみ出しちゃう
}