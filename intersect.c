#include "intersect.h"

#define mod1 (long long)1000000007
#define mod2 (long long)998244353

void intersect_Row_int(int a[MAXROW][MAXCOL], int b[MAXROW][MAXCOL], int ii[MAXROW], int jj[MAXROW], int *cnt1, int *cnt2)
{
    long long mp1[MAXROW] ;
    long long mp2[MAXROW] ;
    int mp[MAXROW] ;
    for(int i = 0 ; i < MAXROW ; i ++ )
    {
        mp1[i] = 0;
        mp2[i] = 0 ;
        mp[i] = 0 ;
    }
    for(int i = 0; i < MAXROW; i++){
        if(a[i][0] == -1) break;
        long long res1 = 0;
        long long res2 = 0;
        for(int j = 0; j < MAXCOL; j++){
            res1 = (res1 * (long long)131 % mod1 + a[i][j]) % mod1; 
            res2 = (res2 * (long long)251 % mod2 + a[i][j]) % mod2;
        }
        mp1[i] = res1;
        mp2[i] = res2;
    }

    // int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < MAXROW; i++){
        if(b[i][0] == -1) break;
        long long res1 = 0;
        long long res2 = 0;
        for(int j = 0; j < MAXCOL; j++){
            res1 = (res1 * (long long)131 % mod1 + b[i][j]) % mod1; 
            res2 = (res2 * (long long)251 % mod2 + b[i][j]) % mod2;
        }
        for(int j = 0; j < MAXROW; j++){
            if(mp[j]){
                if(mp1[j] == res1 && mp2[j] == res2){
                    break;
                }
            }
            if(!mp[j] && mp1[j] == res1 && mp2[j] == res2){
                ii[++(*cnt1)] = j;
                jj[++(*cnt2)] = i;
                mp[j] = 1;
                break;
            }
        }
    }
    
}

/*
intersect_Row_char我的想法是将整个char** 转为int**，之后使用intersect_Row_int进行处理
*/
void intersect_Row_char(char a[MAXROW][MAXCOL], char b[MAXROW][MAXCOL], int ii[MAXROW], int jj[MAXROW], int *cnt1, int *cnt2)
{
    int A[MAXROW][MAXCOL], B[MAXROW][MAXCOL] ;
    for(int i = 0 ; i < MAXROW; i ++ )
    {
        for(int j = 0 ; j < MAXCOL ; j ++ )
        {
            if(a[i][j] != 0 )
            {
                A[i][j] = a[i][j] ;
            }
            else A[i][j] = -1 ;
            if(b[i][j] != 0)
            {
                B[i][j] = b[i][j] ;
            }
            else B[i][j] = -1 ;
        }
    }
    long long mp1[MAXROW] ;
    long long mp2[MAXROW] ;
    int mp[MAXROW] ;
    for(int i = 0 ; i < MAXROW ; i ++ )
    {
        mp1[i] = 0;
        mp2[i] = 0 ;
        mp[i] = 0 ;
    }
    for(int i = 0; i < MAXROW; i++){
        if(a[i][0] < '0' || a[i][0] > '9') break ;
        long long res1 = 0;
        long long res2 = 0;
        for(int j = 0; j < MAXCOL; j++){
            res1 = (res1 * (long long)131 % mod1 + a[i][j]) % mod1; 
            res2 = (res2 * (long long)251 % mod2 + a[i][j]) % mod2;
        }
        mp1[i] = res1;
        mp2[i] = res2;
    }

    // int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < MAXROW; i++){
        if(b[i][0] < '0' || b[i][0] > '9') break ;
        long long res1 = 0;
        long long res2 = 0;
        for(int j = 0; j < MAXCOL; j++){
            res1 = (res1 * (long long)131 % mod1 + b[i][j]) % mod1; 
            res2 = (res2 * (long long)251 % mod2 + b[i][j]) % mod2;
        }
        for(int j = 0; j < MAXROW; j++){
            if(mp[j]){
                if(mp1[j] == res1 && mp2[j] == res2){
                    break;
                }
            }
            if(!mp[j] && mp1[j] == res1 && mp2[j] == res2){
                ii[++(*cnt1)] = j;
                jj[++(*cnt2)] = i;
                mp[j] = 1;
                break;
            }
        }
    }
}



int main()
{
    char a[MAXROW][MAXCOL], b[MAXROW][MAXCOL] ;
    strcpy(a[0], "1314520") ;
    strcpy(a[1], "1314210") ;
    strcpy(b[0], "1314210") ;
    int ii[MAXROW] ;
    int jj[MAXROW] ;
    int cnt1, cnt2 ;
    intersect_Row_char(a, b, ii, jj, &cnt1, &cnt2) ;
    for(int i = 1; i <= cnt1 ; i ++ )
    {
        printf("%d\n", ii[i]) ;
    }
    return 0 ;
}