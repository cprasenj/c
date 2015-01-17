#include "expriment.c"

int parseInt(char *);
void myFor(int,int (*f)(int,int),int);
int fibo(int,int*);
int concat(int*,int,int*,int,int*);
int filter(int*,int,int,int**);
int reverse(int*,int);
int createReverse(int*,int,int*);
int slice(int*,int,int,int,int**);
int primeInRange(int,int,int**);
int compareString(char*,char*);
int forEachInt(int**,int (*f)(int),int);
int increament(int);
char lowerCaseToUpperCase(char);
int forEachChar(char**,char (*f)(int),int);
int jsFilter(int*,int,int (*predicate)(int,int),int**,int);
int predicate(int given,int threshold);
int jsFilterChar(char*,int, int (*f)(char,char), char **,char);
int predicateChar(char,char);
int *jsMapInt(int *,int,int (*f)(int));
int *jsMapChar(char *,int,char (*f)(char));
// char **jsMapStrig(char **arr,int length,char *(*f)(char *stringList));
char **lowerCaseToUpperCaseString(char *a);
int indexOf(char *,char);
int reduceInt(int *,int,int (*f)(int,int),int);
int add(int,int);
char largeChar(char,char);
char reduceChar(char*,int,char (*f)(char,char),char);
