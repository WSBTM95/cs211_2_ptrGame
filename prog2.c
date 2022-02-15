
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "prog2.h"



/**
* 
*  Function "stubs" for Assignment 2 exercises.
*
*  See prog2.h for specifications of function behavior.
*
*/



/***********************************************
*                                             **
*   MATRIX FUNCTIONS                          **
*                                             **
*   NOTE:  parameter n ALWAYS expresses the   **
*     dimensions of the square matrix in      **
*     question.                               **
*                                             **
***********************************************/
char ** alloc_square_mtx(int n) {
   char **matrix = malloc(n * sizeof(char *));
   for (int i = 0; i < n; i++) {
      matrix[i] = malloc(n * sizeof(char));
   }
   return matrix; // placeholder
}

void free_square_mtx(char **m, int n) {
   for (int i = 0; i < n; i++) {
      free(m[i]);
   }
   free(m);
}

void pop_mtx_alpha(char **m, int n){
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         m[i][j] = (rand() % 26) + 97;
      }
   }
}

void display_mtx(char **m, int n){
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         printf("%c ", m[i][j]);
      }printf("\n");
   }
}

void swap_rows(char **m, int n, int r1, int r2){
   if (r1 > n || r2 > n || r1 == r2)
      return;
   else if (r1 < 1 || r2 < 1)
      return;
   char *temp = m[r1 - 1];
   m[r1 - 1] = m[r2 - 1];
   m[r2 - 1] = temp;
}

void swap_cols(char **m, int n, int c1, int c2){
   if (c1 > n || c2 > n || c1 == c2)
         return;
   else if (c1 < 1 || c2 < 1)
      return;
   for (int i = 0; i < n; i++) {
      char temp = m[i][c1 - 1];
      m[i][c1 - 1] = m[i][c2 - 1];
      m[i][c2 - 1] = temp;
   }
}

void rotate_right(char **m, int n){
   char **Temp = alloc_square_mtx(n);
   for (int i = 0; i < n; i++) {
      int k = 0;
      for (int j = n - 1; j >= 0; j--) {
         Temp[i][k++] = m[j][i];
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         m[i][j] = Temp[i][j];
      }
   }
   free_square_mtx(Temp, 5);
}

void floating_boulders(char **m, int n, int nb){
   int boulders = (nb >= n * n);
   int x, y;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (boulders) {
            m[i][j] = '#';
            continue;
         }m[i][j] = '.';
      }
   }
   if (boulders || nb <= 0)
      return;
   while (nb > 0) {
      x = rand() % (n);
      y = rand() % (n);
      if (m[x][y] != '#') {
         m[x][y] = '#';
         nb--;
      }
   }
}

void mountains(char **m, int n){
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         int x = rand() % 2;
         if (x){
            m[i][j] = '#';
         }else{
            m[i][j] = '.';
         }if (i >= 1 && m[i - 1][j] == '#') {
            m[i][j] = '#';
         }
      }
      printf("\n");
   }
}

void sink(char **m, int n){
   for (int i = n - 1; i > 0; i--) {
      for (int j = 0; j < n; j++) {
         m[i][j] = m[i - 1][j];
      }
   }
   for (int i = 0; i < n; i++) {
      m[0][i] = '.';
   }
}

void gravity(char **m, int n){
   for (int i = 0; i < n; i++) {
      for (int j = n - 1; j > 0; j--) {
         if (m[j][i] == '.' && m[j - 1][i] != '.') {
            m[j][i] = m[j - 1][i];
            m[j - 1][i] = '.';
            j = n;
         }
      }
   }
}

/***********************************************
*                                             **
*   STRING FUNCTIONS                          **
*                                             **
***********************************************/


void str_trim(char *s) {
   char temp[50];
   int i = 0;
   int index = 0;
   while (isspace(*s)) {
      s++;
      index++;
   }while (*s != '\0') {
      temp[i++] = *s;
      s++;
      index++;
   }
   while (!isalnum(temp[i])) {
      temp[i--] = '\0';
      index--;
      s--; 
   }
   while (index > 0) {
      s--;
      index--;
   }
   while (temp[index] != '\0') {
      *s = temp[index++];
      s++;
   }
}

int str_search(char *s, char *pattern) {
   int index = 0;
   int tail = 0;
   int count = 0;
   while (*s != '\0' && *pattern != '\0') {
      if (*s == *pattern) {
         pattern++;
         count++;
         tail++;
      } else if (*s != *pattern && count > 0) {
         while (count != 0) {
            pattern--;
            count--;
         }index = ++tail;
      } else {
         tail = ++index;
      }
      s++;
   }
   if (*pattern == '\0') {
      return index;
   }
return -1;  // just a placeholder to make gcc happy for now
}

#ifndef _LIB  // DO NOT REMOVE THIS LINE!!!
              // IT DOESN"T CHANGE HOW YOUR PROGRAM
              // WORKS, BUT IT GIVES US A WAY TO CALL
              // YOUR FUNCTIONS FROM OUR CODE FOR
              // TESTING

/**
* Write a test driver in main below to exercise and
*   your function implementations.
*
* Think carefully about your test cases!
*/
int main() {
}


#endif        // DO NOT REMOVE THIS LINE!!!
