#include<cs50.h>
#include<stdio.h>

int main(void) {
    int n;
    do {
        n = get_int("Height: ");        //Getting height of the Pyramid
    }
    while ((n<1) || (n>8));

    for (int i=1; i<=n; i++) {          // main loop to build complete pyramid

        for (int k=(n-i);k>0;k--) {     // loop for giving spaces
            printf(" ");
        }

        for (int j=0; j<i; j++) {       // loop for #
            printf("#");
        }

        printf("\n");                   // giving a new line after every level
    }
}