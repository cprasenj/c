#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void myFor(int round,int (*f)(int e1,int e2),int val1){
	int i;
	for(i = 0;i < round;i++){
		(*f)(val1,i);
	}
}

int parseInt(char *string) {
	int i,result = 0,flag = 0,dec = 0;
	for(i=0;string[i] >= '0' && string[i] <= '9';++i){
		result = result * 10 + string[i] - '0';
	}
	return result;
}

int fibo(int numberOfTerm,int *array) {
	int i;
	for(i = 0;i < numberOfTerm;i++){
		array[i] = (i < 2) ? i : (array[i-1] + array[i-2]);
	}
	return (numberOfTerm <= 0) ? 0 : 420;
}

int concat(int *arr1,int len_of_arr1,int *arr2,int len_of_arr2,int *result) {
	int i,resultSize = len_of_arr1+len_of_arr2;
	for(i = 0;i<resultSize;i++) {
		result[i] = (i<len_of_arr1) ? arr1[i] : arr2[i-len_of_arr1];
	}
	return (len_of_arr1<=0 || len_of_arr2<=0) ? 0 : 420;
}

int reverse(int *array,int length) {
	int limit,tmp,i;
	for(i = 0;i<length/2;i++){
		tmp = array[i];
		array[i] = array[length-i-1];
		array[length-i-1] = tmp;
	}
	return (length <= 0) ? 0 : 420;
}

int createReverse(int *array,int length,int *result){
	int i;
	for(i = 0;i<length;i++){
		result[i] = array[length-i-1];
	}
	return (length <= 0) ? 0 : 420;
}

int slice(int *arr,int lengthOfArr,int start,int end,int **result) {
	int rangeLength = end-start+1,i,count = 0;
	*result = (int *)malloc(rangeLength*sizeof(int));
	for(i=start-1;i<=end-1;i++) {
		(*result)[count] = arr[i];
		count++;
	}
	return (start<0 || end>lengthOfArr || rangeLength<0) ? 0 : rangeLength;
}

int primeInRange(int start,int end,int **result) {
	int num,i,count = 0,isPrime,range = end-start+1,arrsize = 0;
	int  *primeList = (int *)0;
	for(num=2;num<=end;num++){
		isPrime = 1;
		for(i=0;(i<count) && ((primeList[i]-1)*(primeList[i]-1) < num);i++){
			if(num % primeList[i] == 0){
				isPrime=0;
				break;
			}
		}
		if(isPrime == 1){
			(num>=start) && count++;
			arrsize++;
			primeList = (int *)realloc(primeList,sizeof(int)*arrsize);
			primeList[arrsize-1] = num;
		}
	}
	free(primeList);
	return (start<0 || end<0 || range<0) ? 0 : count;
}

int compareString(char *st1,char *st2) {
	int len1,len2,i,limit;
	len1 = strlen(st1),len2 = strlen(st2);
	limit = ((len1-len2)>0) ? len1 : len2;
	for(i=0;i<limit;i++) {
		if(st1[i]!=st2[i]) {
			return st1[i]-st2[i];
		}
	}
	return 0;
}

int increament(int a) {
	return ++a;
}

int add(int a,int b) {
	return a+b;
}

char lowerCaseToUpperCase(char a) {
	return a-32;
}

int isVowel(char a) {
	return 	(a == 'o') ? 420 : 0;
}

int predicate(int given,int threshold) {
	return (given<threshold) ? 0 : 1;
}

int predicateChar(char given,char threshold) {
	return (given-threshold<0) ? 0 : 1;
}

int forEachInt(int **arr,int (*f)(int a),int length) {
	int i;	
	for(i = 0;i < length;i++)
		(*arr)[i] = (*f)((*arr)[i]);
	return (length<=0) ? 0 : 1;
}

int forEachChar(char **arr,char (*f)(int a),int length) {
	int i;	
	for(i = 0;i < length;i++)
		(*arr)[i] = (*f)((*arr)[i]);
	return (length<=0) ? 0 : 1;
}

int jsFilterInt(int *arr, int length, int (*predicate)(int,int), int **result,int threshold) {
	int i,count=0;
	*result = (int *)0;
	for(i = 0;i < length;i++) {
		if((*predicate)(arr[i],threshold)){
			count++;
			*result = (int *)realloc(*result,sizeof(int)*count);
			(*result)[count-1] = arr[i]; 
		}
	}
	return (length<=0 || count<=0) ? 0 : count;
}

int jsFilterChar(char *arr, int length, int (*f)(char,char), char **result,char threshold) {
	int i,count=0;
	*result = (int *)0;
	for(i = 0;i < length;i++) {
		if((*predicate)(arr[i],threshold)){
			count++;
			*result = (char *)realloc(*result,sizeof(char)*count);
			(*result)[count-1] = arr[i]; 
		}
	}
	return (length<=0 || count<=0) ? 0 : count;
}

char **jsFilterStrig(char **arr,int length,int (*f)(char)) {
	int i,j,count = -1;
	char **str;
	str = (char*)0;
	for(i = 0;i < length;i++) {
		if(arr[i][0] == 'o') {
			count++;
			str = (char *)realloc(str,sizeof(char*)*count);
			str[count] = (char*)malloc(sizeof(char*));
			for(j = 0;arr[i][j] != '\0';j++) {
				str[count] = (char*)realloc(str[count],sizeof(char)*j);
				str[count][j] = arr[i][j];
			}
		}
	}
	return str;
}
char **jsMapStrig(char **arr,int length,char (*f)(char)) {
	int i,j;
	char **str;
	str = (char*)malloc(length*sizeof(char*));
	for(i=0;i<length;i++) {
		str[i] = (char*)malloc(sizeof(char));
		for(j=0;arr[i][j]!='\0';j++){
			str[i] = (char*)realloc(str[i],sizeof(char)*j);
			str[i][j] = lowerCaseToUpperCase(arr[i][j]);
		}
	}
	return str;
}

int *jsMapInt(int *arr,int length,int (*f)(int)) {
	int *result,i;
	result = (int *)malloc(length*sizeof(int));
	for(i = 0;i < length;i++) {
		result[i] = (*f)(arr[i]);	
	}
	return (length<=0) ? 0 : result;
}

int *jsMapChar(char *arr,int length,char (*f)(char)) {
	char *result;
	int i;
	result = (char*)malloc(length*sizeof(char));
	for(i = 0;i < length;i++) {
		result[i] = (*f)(arr[i]);
	}
	return (length<=0) ? 0 : result;
}


char largeChar(char a,char b) {
	return (a-b>0) ? a : b;
}

int reduceInt(int *arr,int length,int (*f)(int,int),int initial) {
	int result = initial,i;
	for(i = 0;i < length;i++){
		result = (*f)(result,arr[i]);
	}
	return (length<=0) ? 0 : result;
}

char reduceChar(char *arr,int length,char (*f)(char,char),char initial) {
	char result = initial;
	int i;
	for(i = 0;i < length;i++){
		result = (*f)(result,arr[i]);
	}
	return (length<=0) ? 'o' : result;
}

int indexOf(char *string,char c){
	int position = -1,i;
	for(i = 0;string[i] != '\0';i++) {
		if(string[i] == c){
			position = i;
			return position;
		}
	}
	return position;
}

int indexOfString(char **string,char **substring){
	int position = -1,i,flag = 1,j;
	for(i = 0;string[0][i] != '\0';i++) {
		if(string[0][i] == substring[0][0]){
			position = i;
			for(j = 0;substring[j]!='\0';j++){
				(substring[0][j]!=string[0][i+j]) && (flag = 0);
			}
			if(flag == 1)
				return position+1;
		}
	}
	return position;
}



