#ifndef INTERSECT_H
#define INTEESECT_H

#include <stdio.h>
#include <string.h>

#define MAXROW 105 
#define MAXCOL 105

void intersect_Row_int(int a[MAXROW][MAXCOL], int b[MAXROW][MAXCOL], int ii[MAXROW], int jj[MAXROW], int *cnt1, int *cnt2) ;
void intersect_Row_char(char a[MAXROW][MAXCOL], char b[MAXROW][MAXCOL], int ii[MAXROW], int jj[MAXROW], int *cnt1, int *cnt2) ;

#endif // intersect.h