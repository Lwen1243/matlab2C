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

int main()
{
    int A[MAXROW][MAXCOL] ;
    int B[MAXROW][MAXCOL] ;
    for(int i = 0; i < MAXROW; i++){
        for(int j = 0; j < MAXCOL; j++){
            A[i][j] = -1;
            B[i][j] = -1;
        }
    }
    A[0][0] = 2 , A[0][1] = 2 , A[0][2] = 2 ;
    A[1][0] = 0, A[1][1] = 0, A[1][2] = 1 ;
    A[2][0] = 1, A[2][1] = 2, A[2][2] = 3;
    A[3][0] = 1, A[3][1] = 1, A[3][2] = 1 ;
    B[0][0] = 1, B[0][1] = 2, B[0][2] = 3;
    B[1][0] = 2, B[1][1] = 2, B[1][2] = 2 ;
    B[2][0] = 2, B[2][1] = 2, B[2][2] = 0;
    
    int ii[11], jj[11] ;
    int cnt1 = 0, cnt2 = 0;
    intersect_Row(A, B, ii, jj, &cnt1, &cnt2) ;
    for(int i = 1 ; i <= cnt1; i ++ ) printf("%d\n", ii[i]) ;
    return 0 ;
}