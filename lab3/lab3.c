/* Name: Elizabeth Chan
   Email: lmchan@brynmawr.edu
   Class: cs287: High Performance Scientific Computing
   Description: Program multiplies matrices. Size of matrices defined by user. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>


void matrix_mult(int n1, int m1, double mat1[n1][m1],
                 int m2, double mat2[m1][m2],
                 double result[n1][m2])
{
  if(n1 <= 0 || m1 <= 0){
    printf("Not a valid matrix. Matrix not stored. \n");
  } else if(m2 <= 0){
    printf("Not a valid matrix. Matrix not stored. \n");
  } else{
    //nested for loop that multiples correct rows and columns and adds products accordingly
    //values are then stored in total and placed in correct index in result array
    //total is then set back to zero
    int h, i, j;
    int total = 0;
    for(h = 0; h<n1; h++){
      for (i = 0; i<m2; i++) {
          for (j = 0; j<m1; j++) {
            total = total + (mat1[h][j] * mat2[j][i]);
            }
            result[h][i] = total;
            total = 0;

      }
    }
  }
}

void print_matrix(int n, int m, double mat[n][m])
{
  if(n <= 0 || m <= 0){
    printf("Not a valid matrix.\n");
  }else{
    int i, j;
    for (i = 0; i<n; i++) {
      for (j = 0; j<m; j++) {
	       printf("\t %lf ", mat[i][j]);
      }
      printf("\n"); //moves numbers to next line
    }
  }
}



int main() {


  //FILE *fp = fopen("/homes/lmchan/287/theFiles/MatrixTest2.txt", "r");
  //FILE *fp = fopen("/homes/lmchan/287/theFiles/MatrixTest.txt", "r");
  //FILE *fp = fopen("/homes/lmchan/287/theFiles/MatrixTest3.txt", "r");


  //FILE *fp = fopen("/Users/elizabethmchan2/desktop/lab3files/MatrixTest2.txt", "r");
  //FILE *fp = fopen("/Users/elizabethmchan2/desktop/lab3files/MatrixTest.txt", "r");
  //FILE *fp = fopen("/Users/elizabethmchan2/desktop/lab3files/MatrixTest3.txt", "r");
  int num;
  printf("Give the dimension of the matrix? \n");
  scanf("%d", &num);

  double a1[num][num];
  double a2[num][num];
  double result[num][num];


  /*int i;
  srand(time(NULL));
  for(i=0; i<num; i++) {
    double ans = rand()/(double)RAND_MAX*100;
  }  */

  int m, n;
  double ans;
  for (m=0; m<num; m++) {
   for(n=0; n<num; n++) {
     //fscanf(fp, "%lf \t", &a[m][n]);
     ans = rand()/(double)RAND_MAX*100;
     a1[m][n] = ans;
     a2[m][n] = ans;
   }
  }

  //printf("%f %f", a1[0][0], a2[0][0]);
  clock_t tic = clock();
  //print_matrix(num, num, a);
  //matrix_mult(num, num, a, num, a, result);
  //print_matrix(num, num, result);

  int h, i, j;
  double total = 0;
  for(h = 0; h<num; h++){
    for (i = 0; i<num; i++) {
        for (j = 0; j<num; j++) {
          total = total + (a1[h][j] * a2[j][i]);
          }
          result[h][i] = total;
          total = 0;
      }
    }

  /*print_matrix(num, num, a1);
  print_matrix(num, num, a2);
  print_matrix(num, num, result); */
  clock_t toc = clock();


  printf("Elapsed: %Lf seconds\n", (long double)(toc-tic)/CLOCKS_PER_SEC); //prints out execution time


  return 0;
}
