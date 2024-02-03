#include "intersect.h"

#define mod1 (long long)1000000007
#define mod2 (long long)998244353

void intersect_Row(int a[MAXROW][MAXCOL], int b[MAXROW][MAXCOL], int ii[MAXROW], int jj[MAXROW], int *cnt1, int *cnt2)
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
    int A[MAXROW][MAXCOL] = {{2, 2, 2}, {0, 0, 1}, {1, 2, 3}, {1, 1, 1}} ;
    int B[MAXROW][MAXCOL] = {{1, 2, 3}, {2, 2, 2}, {2, 2, 0}} ;
    int ii[11], jj[11] ;
    int cnt1 = 0, cnt2 = 0;
    intersect_Row(A, B, ii, jj, &cnt1, &cnt2) ;
    for(int i = 0 ; i < cnt1 ; i ++ ) printf("%d\n", ii[i]) ;
    return 0 ;
}