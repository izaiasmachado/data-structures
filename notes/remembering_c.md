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
    double s = 0.0F;
    for (i = 0; i < m; i++) {
        s += v[i];
    }

    return s;
} 

int main () {
    double v[] = { 2.0, 3.0, 4.0 };
    int m = (sizeof(v)) / (sizeof(double));
    double s = sum(m, v);

    printf("sum = %.lf, mean = %.lf", s, (s / m)); // sum = 9, mean = 3
    
    return 0;
}
```