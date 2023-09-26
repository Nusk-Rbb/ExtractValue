#include <stdio.h>
#include<stdlib.h>
#include <string.h>
 
char* find(char *text, char target, int target_num){
    size_t len = strlen(text);
    int count = 0;

    for(int i = 0; i < len; i++){
        if(text[i] == target){
            count++;
            if(count == target_num){
                return text + i;
            }
        }
    }

    return NULL;
}

int lencount(char* text, char target){
    size_t len = strlen(text);
    text += 1;

    for(int i = 1; i < len; i++){
        if(*(text + i) == target){
            return i;          
        }
    }

    return 0;
}

double getvalue(char* text, int len){
    double value;
    char char_value[len];

    text += 1;
    for(int i = 0; i < len; i++){
        char_value[i] = *(text + i);
    }

    value = atof(char_value);  
    return value;
}

int main(void) {
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