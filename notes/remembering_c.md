# Remembering C

## Returning Values By Memory Reference
```c
#include <stdio.h>

void sum (int x, int y, int *s, int *p) {
	*s = x + y;
	*p = x * y;
}

int main () {
	int s, p;
    
	sum(3, 5, &s, &p);
	printf("sum = %d and prod = %d", s, p); // sum = 8 and 15

	return 0;
}
```
## Swapping Values By Memory Address
```c
#include <stdio.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main () {
    int x = 5, y = 7;

    swap(&x, &y);
    printf("x = %d and y = %d", x, y); // x = 7 and y = 5

    return 0;
}
```
## Array as a Pointer
```c
#include <stdio.h>

int main () {
    int v[3] = { 6, 8, 9 };

    printf("%d\n", v[0]); // 6
    printf("%d\n", *v);   // 6

    printf("%p\n", &v); // 0x7ffe2555877c
    printf("%p\n", v);  // 0x7ffe2555877c

    printf("%p\n", &v[1]); // 0x7ffe25558780
    printf("%p\n", v + 1);  // 0x7ffe25558780

    printf("%d\n", sizeof(int)); // 4
    printf("%d\n", sizeof(v)); // 12
    
    return 0;
}
```
## Passing Array By Parameter
```c
#include <stdio.h>

double sum (int m, double v[]) {
    int i;
    double s = 0.0;
    for (i = 0; i < m; i++) {
        s += v[i];
    }

    return s;
} 

int main () {
    double v[] = { 2.0, 3.0, 4.0 };
    int m = 3;
    double s = sum(m, v);

    printf("sum = %.lf, mean = %.lf", s, (s / m)); // sum = 9, mean = 3
    
    return 0;
}
```
## Dynamic Allocation
```c
#include <stdio.h>
#include <stdlib.h>

double sum (int m, double *v) {
    int i;
    double s = 0.0;
    for (i = 0; i < m; i++) {
        s += v[i];
    }

    return s;
} 

int main () {
    int n, i;
    double *v, s;
    v = (double *) malloc(n * sizeof(double));

    if (v == NULL) {
        printf("Unable to alloc memory :/\n");
        return -1;
    }

    printf("Type the size of dynamic array: ");
    scanf("%d", &n); // 3

    printf("Enter the elements in the array: ");
    for (i = 0; i < n; i++) {
        scanf("%lf", v + i); // 1 2 3
    }

    s = sum(n, v);
    printf("sum = %.lf and mean %.lf\n", s, (s / n)); // sum = 6 and mean = 2

    free(v);
    
    return 0;
}
```
## Passing Static Matrix By Parameter
```c
#include <stdio.h>
#include <stdlib.h>

double sum (int m, double v[][3]) {
    int i, j;
    double md = 0.0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < 3; j++) {
            md += v[i][j];
        }
    }

    return md;
}

int main () {
    double mtx[4][3] = {
        { 5.0, 10.0, 15.0 },
        { 20.0, 25.0, 30.0 },
        { 35.0, 40.0, 45.0 },
        { 50.0, 55.0, 60.0 }
    };

    printf("%.lf", sum(4, mtx)); // 390

    return 0;
}
```
## Parse Dynamic Matrixes
```c
#include <stdio.h>
#include <stdlib.h>

double sum (int m, int n, double *v) {
    int i, j;
    double md = 0.0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < 3; j++) {
            md += v[i * n + j];
        }
    }

    return md;
}

int main () {
    int m = 4, n = 3;
    double *mtx = (double *) malloc (m * n * sizeof(double));

    mtx[0 * n + 0] = 5.0; // mtx[0][0]
    mtx[0 * n + 1] = 10.0; // mtx[0][1]
    mtx[0 * n + 2] = 15.0; // mtx[0][2]

    mtx[1 * n + 0] = 20.0; // mtx[1][0]
    mtx[1 * n + 1] = 25.0; // mtx[1][1]
    mtx[1 * n + 2] = 30.0; // mtx[1][2]
     
    mtx[2 * n + 0] = 35.0; // mtx[2][0]
    mtx[2 * n + 1] = 40.0; // mtx[2][1]
    mtx[2 * n + 2] = 45.0; // mtx[2][2]

    mtx[3 * n + 0] = 50.0; // mtx[3][0]
    mtx[3 * n + 1] = 55.0; // mtx[3][1]
    mtx[3 * n + 2] = 60.0; // mtx[3][2]

    printf("%.lf", sum(m, n, mtx)); // 390

    return 0;
}
```
## Other Aproach to Dynamic Matrixes
```c
#include <stdio.h>
#include <stdlib.h> 

double sum (int m, double **v) {
    int i, j;
    double md = 0.0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < 3; j++) {
            md += v[i][j];
        }
    }

    return md;
}

int main () {
    int m = 4, n = 3, i;
    double **mtx = (double **) malloc(m * sizeof(double *));

    for (i = 0; i < m; i++) {
        mtx[i] = (double *) malloc(n * sizeof(double));
    }

    mtx[0][0] = 5.0;
    mtx[0][1] = 10.0;
    mtx[0][2] = 15.0;

    mtx[1][0] = 20.0;
    mtx[1][1] = 25.0;
    mtx[1][2] = 30.0;
     
    mtx[2][0] = 35.0;
    mtx[2][1] = 40.0;
    mtx[2][2] = 45.0;

    mtx[3][0] = 50.0;
    mtx[3][1] = 55.0;
    mtx[3][2] = 60.0;

    printf("%.lf", sum(m, mtx)); // 390

    for (i = 0; i < m; i++) {
        free(mtx[i]);
    }

    free(mtx);

    return 0;
}
```
## What if you change your mind? Rellocation
```c
#include <stdio.h>
#include <stdlib.h>
  
int main () {
   int *ptr;
   int n, i;
  
   n = 5;
   printf("Enter number of elements: %d\n", n);
  
   ptr = (int*)calloc(n, sizeof(int));
  
   if (ptr == NULL) {
      printf("Memory not allocated.\n");
      exit(0);
   } else {
      printf("Memory successfully allocated using calloc.\n");
  
      for (i = 0; i < n; ++i) {
         ptr[i] = i + 1;
      }
  
      printf("The elements of the array are: ");
      for (i = 0; i < n; ++i) {
         printf("%d%s", ptr[i], (i == (n - 1) ? "\n" : ", ")); // 1, 2, 3, 4, 5
      }
  
      n = 10;
      printf("Enter the new size of the array: %d\n", n);
  
      ptr = (int *) realloc(ptr, n * sizeof(int));
      if (ptr == NULL) {
         printf("Memory not allocated.\n");
         exit(0);
      } else {
         printf("Memory successfully re-allocated using realloc.\n");
  
         for (i = 5; i < n; ++i) {
            ptr[i] = i + 1;
         }
  
         printf("The elements of the array are: ");
         for (i = 0; i < n; ++i) {
            printf("%d%s", ptr[i], (i == (n - 1) ? "\n" : ", ")); // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
         }

      } 
  
      free(ptr);
   }
  
   return 0;
}
```
