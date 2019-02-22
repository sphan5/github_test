#include <stdio.h>
//Name: Steven Phan, NetID: sphan5

int main() {

  unsigned int w, x, y, z; //Variables for which the function operates on
  unsigned int a, b; //Dummy variables used to calculate x and z in gray code order
  unsigned int f, g; //Variable to store the desired boolean operation output

  /* Print header for K-map*/
  printf("f(w,x,y,z)        yz         \n");
  printf("            00  01  11  10   \n");
  printf("         _____________________\n");

  /*prints out each full row for wx = *anything**/
  for (w = 0; w < 2; w++) {
      for (a = 0; a < 2; a++) {
        /*Calculated x (gray code order) in terms of w and a*/
        x = (w^a);
        /*Prints out wx = in gray code order*/
        printf("wx = %u%u |", w, x);
        /*loops through y in binary order*/
        for (y = 0; y < 2; y++) {
          for (b = 0; b < 2; b++) {
          /*Calculated z (gray code order) in terms of y and b*/
          z = (y^b);
          /*Calculated f(w,x,y,z) and prints the output for every yz input in the current interation of wx*/
          f = (((x)&(~y)) | ((~w)&(z)))&1;
          printf("  %u  ", f);
        }
      }
      /*New line for the next iteration of wx = */
      printf("\n");
    }
  }

  /*Add line and line break to divide up output in terminal screen*/
  printf("_________________________________\n");
  printf("\n");

  /*Repeat process for function g*/
  /* Print header for K-map*/
  printf("g(w,x,y,z)        yz         \n");
  printf("            00  01  11  10   \n");
  printf("         _____________________\n");

  /*prints out each full row for wx = *anything**/
  for (w = 0; w < 2; w++) {
      for (a = 0; a < 2; a++) {
        /*Calculated x (gray code order) in terms of w and a*/
        x = (w^a);
        /*Prints out wx = in gray code order*/
        printf("wx = %u%u |", w, x);
        /*loops through y in binary order*/
        for (y = 0; y < 2; y++) {
          for (b = 0; b < 2; b++) {
          /*Calculated z (gray code order) in terms of y and b*/
          z = (y^b);
          /*Calculated g(w,x,y,z) and prints the output for every yz input in the current interation of wx*/
          g = (((~w)&(x)&(y)&(~z))|(w)|(~x))&1;
          printf("  %u  ", g);
        }
      }
      /*New line for the next iteration of wx = */
      printf("\n");
    }
  }
  return 0;
}
