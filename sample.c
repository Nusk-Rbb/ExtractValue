#include<stdio.h>
#include "ExtractValue.c"

int main(void) {
    // 例：GPAメッセージを使って緯度と経度を抽出します
    char str[] = "$GPGGA,213959.00,3522.5012666,N,13942.1022598,E,1,20,0.9,4174.8064,M,39.6262,M,,*5A";
    char *adr1;
    int len;
    char *adr2;
    double value;

    // 指定した文字を検索し先頭アドレスを返す
    adr1 = find(str, ',', 2);
    printf("found           : %s\n", adr1);

    // 指定した文字まで検索しその文字列までを返す
    len = lencount(adr1 + 1, ',');
    printf("target num      : %d\n", len);

    value = getvalue(adr1, len);
    printf("target value    : %lf\n", value);
    
    // 指定した文字を検索し先頭アドレスを返す
    adr2 = find(str, ',', 4);
    printf("found           : %s\n", adr2);

    // 指定した文字まで検索しその文字列までを返す
    len = lencount(adr2, ',');
    printf("target num      : %d\n", len);

    value = getvalue(adr2, len);
    printf("target value    : %lf\n", value);
    return 0;
}