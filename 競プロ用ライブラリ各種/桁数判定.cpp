unsigned GetDigit(unsigned num){
    if(num == 0)return 1;
    return log10(num)+1;
}