# Remembering Structures

## Basic Example
```c
#include <stdio.h>
#include <stdlib.h>

/*
    The ideia is to create an absctract data,
    using simples types.
*/

struct Dot {
    double x;
    double y;
};

int main () {
    struct Dot p;

    printf("Type 2 coordinates (x and y): ");
    scanf("%lf %lf", &p.x, &p.y);
    printf("Dot (%.2lf, %.2lf)\n", p.x, p.y);
 
    return 0;
}
```

## Passing Structures by Parameter
```c
#include <stdio.h>
#include <stdlib.h>

struct Dot {
    double x;
    double y;
};

void print (struct Dot p) {
    printf("Dot (%.2lf, %.2lf)\n", p.x, p.y);
}

int main () {
    struct Dot p;
    struct Dot *pp;
    pp = &p;
    // (*pp).x is the same to use pp->x
    
    (*pp).x = 10.0;
    (*pp).y = -6.0;
    print(p);
    
    pp->x = -1.0;
    pp->y = 13;
    print(p);

    return 0;
}
```

## Passing Structure Pointer
```c
#include <stdio.h>
#include <stdlib.h>

struct Dot {
    double x;
    double y;
};

void print (struct Dot *pp) {
    printf("Dot (%.2lf, %.2lf)\n", pp->x, pp->y);
}

void capture (struct Dot *pp) {
    printf("Type the coordinates (x and y): ");
    scanf("%lf %lf", &pp->x, &pp->y);
}

int main () {
    struct Dot p;    
    capture(&p);
    print(&p);
    return 0;
}
```

## Typedef
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Dot;

void print (Dot *pp) {
    printf("Dot (%.2lf, %.2lf)\n", pp->x, pp->y);
}

void capture (Dot *pp) {
    printf("Type the coordinates (x and y): ");
    scanf("%lf %lf", &pp->x, &pp->y);
}

double distance (Dot *p1, Dot *p2) {
    return sqrt(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));
}

int main () {
    Dot p1, p2;    
    capture(&p1);
    capture(&p2);

    double d = distance(&p1, &p2);
    printf("The distance between the dots is: %.5lf units of distance\n", d);

    return 0;
}
```

## Nested types
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Dot;

typedef struct {
    Dot p;
    double r;
} Circle;

void print (Dot *pp) {
    printf("Dot (%.2lf, %.2lf)\n", pp->x, pp->y);
}

void captureDot (Dot *pp) {
    printf("Type the coordinates (x and y): ");
    scanf("%lf %lf", &pp->x, &pp->y);
}

void captureCircle (Circle *cc) {
    Dot *pp = &cc->p;
    printf("Type the coordinates and radius of the circle (x, y and radius): ");
    scanf("%lf %lf %lf", &pp->x, &pp->y, &cc->r);
}

double distance (Dot *p1, Dot *p2) {
    return sqrt(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));
}

int isInner (Circle *c, Dot *p) {
    double d = distance((&c->p), p);
    return (d < (c->r));
}

int main () {
    Dot p;
    Circle c;    
    captureCircle(&c);
    captureDot(&p);

    int value = isInner(&c, &p);
    printf("The dot %s the circle.\n", ((value) ? "is in" : "is out of"));

    return 0;
}
```

## Structured Array - Ex.: 1
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 2
#define NO_STUDENT -1

typedef struct {
    char name[81];
    double ira;
} Student;


void init (int n, Student students[]) {
    int i;
    for (i = 0; i < n; i++) {
        strcpy(students[i].name, "");
        students[i].ira = NO_STUDENT;
    }
}

void print (Student student) {
    printf("Name: %s - IRA: %.2lf\n", student.name, student.ira);
}

void printAll (int n, Student students[]) {
    int i = 0;
    for (i = 0; i < n; i++) {
        Student student = students[i];
        print(student);
    }
}

void update (int n, Student students[], int i) {
    double ira;
    if (i < 0 || i >= n) {
        printf("Index out of bounds!\n");
        exit(1);
    }

    printf("Type the student name: ");
    scanf(" %[^\n]", students[i].name);
    
    while (1) {
        printf("Input the IRA of the student: ");
        scanf(" %lf", &ira);
        
        if (ira < 0 || ira > 100) printf("IRA should be on the following interval [0.0, 100.0]\n");
        else break;
    }

    students[i].ira = ira;
}

int main () {
    Student students[MAXN];
    int i;
    
    init(MAXN, students);
    for (i = 0; i < MAXN; i++) {
        update(MAXN, students, i);
    }

    printAll(MAXN, students);
    return 0;
}
```

## Structured Array - Ex.: 2
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[81];
    double ira;
} Student;

#define MAXN 100
#define NO_STUDENT -1

void init (int n, Student *students[]) {
    int i;    
    for (i = 0; i < n; i++) {
        students[i] = (Student *) malloc(n * sizeof(Student));
        if (students[i] == NULL) {
            printf("Unable to alloc memory!");
            exit(1);
        }
        strcpy(students[i]->name, "");
        students[i]->ira = NO_STUDENT;
    }
}

void print (Student student) {
    printf("Name: %s - IRA: %.2lf\n", student.name, student.ira);
}

void printAll (int n, Student **students) {
    int i = 0;
    for (i = 0; i < n; i++) {
        print(*students[i]);
    }
}

void update (int n, Student *students[], int i) {
    double ira;
    if (i < 0 || i >= n) {
        printf("Index out of bounds!\n");
        exit(1);
    }

    printf("Type the student name: ");
    scanf(" %[^\n]", students[i]->name);
    
    while (1) {
        printf("Input the IRA of the student: ");
        scanf(" %lf", &ira);
        
        if (ira < 0 || ira > 100) printf("IRA should be on the following interval [0.0, 100.0]\n");
        else break;
    }

    students[i]->ira = ira;
}


int main () {
    Student *students[MAXN];
    int i, n;

    printf("Input the quantity of students to be typed: ");
    scanf("%d", &n);

    init(n, students);

    for (i = 0; i < n; i++) {
        update(n, students, i);
    }

    printAll(n, students);

    for (i = 0; i < n; i++) {
        free(students[i]);
    }

    return 0;
}
```

## Structured Array - Ex.: 3
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[81];
    double ira;
} Student;

#define MAXN 100
#define NO_STUDENT -1

void init (int n, Student *students[]) {
    int i;    
    students = (Student **) malloc(n * sizeof(Student *));
    for (i = 0; i < n; i++) {
        students[i] = (Student *) malloc(n * sizeof(Student));
        if (students[i] == NULL) {
            printf("Unable to alloc memory!");
            exit(1);
        }
        strcpy(students[i]->name, "");
        students[i]->ira = NO_STUDENT;
    }
}

void print (Student student) {
    printf("Name: %s - IRA: %.2lf\n", student.name, student.ira);
}

void printAll (int n, Student **students) {
    int i = 0;
    for (i = 0; i < n; i++) {
        print(*students[i]);
    }
}

void update (int n, Student *students[], int i) {
    double ira;
    if (i < 0 || i >= n) {
        printf("Index out of bounds!\n");
        exit(1);
    }

    printf("Type the student name: ");
    scanf(" %[^\n]", students[i]->name);
    
    while (1) {
        printf("Input the IRA of the student: ");
        scanf(" %lf", &ira);
        
        if (ira < 0 || ira > 100) printf("IRA should be on the following interval [0.0, 100.0]\n");
        else break;
    }

    students[i]->ira = ira;
}


int main () {
    Student **students;
    int i, n;

    printf("Input the quantity of students to be typed: ");
    scanf("%d", &n);

    init(n, students);

    for (i = 0; i < n; i++) {
        update(n, students, i);
    }

    printAll(n, students);

    for (i = 0; i < n; i++) {
        free(students[i]);
    }
    free(students);

    return 0;
}
```