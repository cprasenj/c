#include "expr_assert.h"
#include "experiment.h"
#include <string.h>
void test_parseInt1(){
	int x = parseInt("123hjhjjhj");
	assert(x == 123);
}

void test_parseInt2(){
	int x = parseInt("123                 ");
	assert(x == 123);
}

void test_parseInt3(){
	int x = parseInt("123\n\n\n\n\\\\\\\\\\\n\n\n\n\n");
	assert(x == 123);
}

void test_parseInt4(){
	int x = parseInt("123\n\n\n\n\\\\\\53465463\\ttttt\\\n\n\n\n\n7347346364");
	assert(x == 123);
}

void test_parseInt5(){
	int x = parseInt("     ");
	assert(x == 0);
}

void test_parseInt6(){
	int x = parseInt("ghjgsdhfsjej");
	assert(x == 0);
}

void test_fibo_4_terms(){
	int *array,x;
	array = (int*)malloc(4*sizeof(int));
	x = fibo(4,array);
	assert(x == 420);
	assert(0==array[0]);
	assert(1==array[1]);
	assert(1==array[2]);
	assert(2==array[3]);
	free(array);
}

void test_fibo_5_terms(){
	int *array,x;
	array = (int*)malloc(5*sizeof(int));
	x = fibo(5,array);
	assert(x == 420);
	assert(0==array[0]);
	assert(1==array[1]);
	assert(1==array[2]);
	assert(2==array[3]);
	assert(3==array[4]);
	free(array);
}

void test_fibo_with_negative_number(){
	int *array,x;
	x = fibo(-4,array);
	assert(0 == x);
}

void test_fibo_with_1_term(){
	int *array,x;
	array = (int*)malloc(1*sizeof(int));
	x = fibo(1,array);
	assert(420 == x);
	assert(array[0] == 0);
}

void test_fibo_with_2_term(){
	int *array,x;
	array = (int*)malloc(2*sizeof(int));
	x = fibo(2,array);
	assert(420 == x);
	assert(array[0] == 0);
	assert(array[1] == 1);
	free(array);
}

void test_concat_with_same_size_array(){
	int *arr1,*arr2,len1=2,len2=2,*result,x,resultSize=len1+len2;
	arr1 = (int*)malloc(len1*sizeof(int));
	arr2 = (int*)malloc(len2*sizeof(int));
	result = (int*)malloc(resultSize*sizeof(int));
	arr1[0] = 1;
	arr1[1] = 2;
	arr2[0] = 3;
	arr2[1] = 4;
	x = concat(arr1,len1,arr2,len2,result);
	assert(x == 420);
	assert(result[0] == 1);
	assert(result[1] == 2);
	assert(result[2] == 3);
	assert(result[3] == 4);
	free(arr1);
	free(arr2);
	free(result);
}

void test_concat_with_different_size_array(){
	int *arr1,*arr2,len1=2,len2=3,*result,x,resultSize=len1+len2;
	arr1 = (int*)malloc(len1*sizeof(int));
	arr2 = (int*)malloc(len2*sizeof(int));
	result = (int*)malloc(resultSize*sizeof(int));
	arr1[0] = 1;
	arr1[1] = 2;
	arr2[0] = 3;
	arr2[1] = 4;
	arr2[2] = 5;
	x = concat(arr1,len1,arr2,len2,result);
	assert(x == 420);
	assert(result[0] == 1);
	assert(result[1] == 2);
	assert(result[2] == 3);
	assert(result[3] == 4);
	assert(result[4] == 5);
	free(arr1);
	free(arr2);
	free(result);
}

void test_concat_with_zero_size_array(){
	int *arr1,*arr2,len1=2,len2=0,*result,x,resultSize=len1+len2;
	arr1 = (int*)malloc(len1*sizeof(int));
	arr2 = (int*)malloc(len2*sizeof(int));
	result = (int*)malloc(resultSize*sizeof(int));
	arr1[0] = 1;
	arr1[1] = 2;
	x = concat(arr1,len1,arr2,len2,result);
	assert(x == 0);
	free(arr1);
	free(arr2);
}

void test_reverse_arr_of_size_4() {
	int *arr,x;
	arr = (int*)malloc(4*sizeof(int));
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	x = reverse(arr,4);
	assert(x == 420);
	assert(arr[0] == 4);
	assert(arr[1] == 3);
	assert(arr[2] == 2);
	assert(arr[3] == 1);
	free(arr);
}

void test_reverse_arr_of_size_5() {
	int *arr,x;
	arr = (int*)malloc(4*sizeof(int));
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	x = reverse(arr,5);
	assert(x == 420);
	assert(arr[0] == 5);
	assert(arr[1] == 4);
	assert(arr[2] == 3);
	assert(arr[3] == 2);
	assert(arr[4] == 1);
	free(arr);
}

void test_reverse_arr_of_size_1() {
	int *arr,x;
	arr = (int*)malloc(1*sizeof(int));
	arr[0] = 1;
	x = reverse(arr,1);
	assert(x == 420);
	assert(arr[0] == 1);
	free(arr);
}

void test_reverse_arr_of_size_0() {
	int *arr,x;
	x = reverse(arr,0);
	assert(x == 0);
}

void test_createReverse_arr_of_size_4() {
	int *arr,x,*result;
	arr = (int*)malloc(4*sizeof(int));
	result = (int*)malloc(4*sizeof(int));
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	x = createReverse(arr,4,result);
	assert(x == 420);
	assert(result[0] == 4);
	assert(result[1] == 3);
	assert(result[2] == 2);
	assert(result[3] == 1);
	free(arr);
}

void test_createReverse_arr_of_size_5() {
	int *arr,x,*result;
	arr = (int*)malloc(5*sizeof(int));
	result = (int*)malloc(5*sizeof(int));
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	x = createReverse(arr,5,result);
	assert(x == 420);
	assert(result[0] == 5);
	assert(result[1] == 4);
	assert(result[2] == 3);
	assert(result[3] == 2);
	assert(result[4] == 1);
	free(arr);
	free(result);
}

void test_createReverse_arr_of_size_1() {
	int *arr,x,*result;
	arr = (int*)malloc(1*sizeof(int));
	result = (int*)malloc(1*sizeof(int));
	arr[0] = 1;
	x = createReverse(arr,1,result);
	assert(x == 420);
	assert(result[0] == 1);
	free(arr);
	free(result);
}

void test_createReverse_arr_of_size_0() {
	int *arr,x,*result;
	x = createReverse(arr,0,result);
	assert(x == 0);
}

void test_slice_with_array_size_5_and_range_2_4() {
	int *arr,x,*result,length=5;
	arr = (int*)malloc(length*sizeof(int));
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	x = slice(arr,length,2,4,&result);
	assert(x==3);
	assert(result[0]==2);
	assert(result[1]==3);	
	assert(result[2]==4);
	free(arr);	
}

void test_slice_with_array_size_5_and_range_is_negative() {
	int *arr,x,*result,length=5;
	x = slice(arr,length,-2,4,&result);
	assert(x==0);
}

void test_slice_with_array_size_5_and_range_4_2() {
	int *arr,x,*result,length=5;
	arr = (int*)malloc(length*sizeof(int));
	x = slice(arr,length,4,2,&result);
	assert(x==0);
}

void test_slice_with_array_size_5_and_range_2_2() {
	int *arr,x,*result,length=5;
	arr = (int*)malloc(length*sizeof(int));
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	x = slice(arr,length,2,2,&result);
	assert(x==1);
	assert(result[0]==2);
	free(arr);
}

void test_primeInRange_gives_0_for_negative() {
	int x,*result;
	x = primeInRange(-1,8,&result);
	assert(x == 0);
	x = primeInRange(1,-8,&result);
	assert(x == 0);
}

void test_primeInRange_gives_4_for_1_8() {
	int x,*result;
	x = primeInRange(1,8,&result);
	assert(x == 4);
}

void test_primeInRange_gives_0_for_start_greater_than_end() {
	int x,*result;
	x = primeInRange(8,1,&result);
	assert(x == 0);
}

void test_primeInRange_gives_0_for_same_start_and_end() {
	int x,*result;
	x = primeInRange(1,1,&result);
	assert(x == 0);
}

void test_primeInRange_gives_3_for_2_6() {
	int x,*result;
	x = primeInRange(2,6,&result);
	assert(x == 3);
}

void test_primeInRange_gives_2_for_3_6() {
	int x,*result;
	x = primeInRange(3,6,&result);
	assert(x == 2);
}

void test_primeInRange_gives_6_for_2_15() {
	int x,*result;
	x = primeInRange(2,15,&result);
	assert(x == 6);
}

void test_primeInRange_gives_239_for_2_1500() {
	int x,*result;
	x = primeInRange(2,1500,&result);
	assert(x == 239);
}

// void test_primeInRange_gives_114155_for_2_1500000() {
// 	int x,*result;
// 	x = primeInRange(2,1500000,&result);
// 	assert(x == 114155);
// }

// void test_primeInRange_gives_114155_for_2_15000000() {
// 	int x,*result;
// 	x = primeInRange(2,15000000,&result);
// 	printf("%d\n",x);
// 	assert(x == 970704);
// }

// void test_primeInRange_gives_114155_for_2_150000000() {
// 	int x,*result;
// 	x = primeInRange(2,result,&1500000000);
// 	printf("%d\n",x);
// 	assert(x == 8444396);
// }


void test_compare_string_gives_0_for_string_emptyString() {
	char *w1 = "hello";
	char *w2 = "";
	int expected = compareString(w1,w2);
	assertEqual(expected, strcmp(w1,w2));
}

void test_compare_string_gives_0_for_string_space() {
	char *w1 = "hello";
	char *w2 = " ";
	int expected = compareString(w1,w2);
	assertEqual(expected, strcmp(w1,w2));
}

void test_compare_string_gives_0_for_same_strings_same_size() {
	char *w1 = "hello",actual = 0;
	char *w2 = "hello";
	int expected = compareString(w1,w2);
	assertEqual(expected, actual);
}

void test_compare_string_gives_0_for_different_strings_different_size() {
	char *w1 = "hello";
	char *w2 = "helloo";
	int expected = compareString(w1,w2);
	assertEqual(expected, strcmp(w1,w2));
}

void test_compare_string_gives_0_for_different_strings_same_size() {
	char *w1 = "hello";
	char *w2 = "helLo";
	int expected = compareString(w1,w2);
	assertEqual(expected, strcmp(w1,w2));
}

void test_compare_string_compares_0_ram_and_sum() {
	char *w1 = "ram";
	char *w2 = "sam";
	int expected = compareString(w1,w2);
	assertEqual(expected, strcmp(w1,w2));
}

void test_compare_string_compares_0_empty_and_sum() {
	char *w1 = "";
	char *w2 = "sam";
	int expected = compareString(w1,w2);
	assertEqual(expected, strcmp(w1,w2));
}

void test_compare_string_compares_spaces_empty() {
	char *w1 = "    ";
	char *w2 = "  ";
	int expected = compareString(w1,w2);
	assertEqual(expected, strcmp(w1,w2));
}

void test_forEach_1_2_3_gives_an_array_2_3_4() {
	int *arr,expected = 1,actual,length=3;
	arr = (int*)malloc(length*sizeof(int));
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	actual = forEachInt(&arr,increament,3);
	assertEqual(expected,actual);
	assertEqual(arr[0],2);
	assertEqual(arr[1],3);
	assertEqual(arr[2],4);
	free(arr);
}

void test_forEach_0_gives_an_array_1_() {
	int *arr,expected = 1,actual,length=1;
	arr = (int*)malloc(length*sizeof(int));
	arr[0] = 0;
	actual = forEachInt(&arr,increament,3);
	assertEqual(expected,actual);
	assertEqual(arr[0],1);
}

void test_forEach_a_b_c_gives_an_array_A_B_C() {
	int expected = 1,actual,length=3;
	char *arr; 
	arr = (int*)malloc(length*sizeof(char));
	arr[0] = 'a';
	arr[1] = 'b';
	arr[2] = 'c';
	actual = forEachChar(&arr,lowerCaseToUpperCase,3);
	assertEqual(expected,actual);
	assertEqual(arr[0],'A');
	assertEqual(arr[1],'B');
	assertEqual(arr[2],'C');
	free(arr);
}

void test_jsFilterInt_gives_0_for_0_length() {
	int *arr,*result,length=0,expected=0,threshold=9;
	int actual = jsFilterInt(&arr,length,predicate,&result,threshold);
	assertEqual(expected, actual);
	free(result);
}

void test_jsFilterInt_gives_0_for_negative_length() {
	int *arr,*result,length=-420,expected=0,threshold=9;
	int actual = jsFilterInt(&arr,length,predicate,&result,threshold);
	assertEqual(expected, actual);
	free(result);
}

void test_jsFilterInt_gives_lenght_of_filtered_array_for_positive_length() {
	int arr[] = {1,2,3,4,5},*result,length=5,expected=3,threshold=3;
	int actual = jsFilterInt(&arr,length,predicate,&result,threshold);
	assertEqual(expected, actual);
	free(result);
}

void test_jsFilterInt_gives_lenght_of_filtered_array_for_positive_length_and_result_array() {
	int arr[] = {1,2,3,4,5},*result,length=5,expected=3,threshold=3;
	int actual = jsFilterInt(&arr,length,predicate,&result,threshold);
	assertEqual(expected, actual);
	assert(result[0] == 3);
	assertEqual(result[1], 4);
	assertEqual(result[2], 5);
	free(result);
}

void test_jsFilterInt_gives_0_for_0_length_result() {
	int arr[] = {1,2,3,4,5},*result,length=5,expected=0,threshold=30;
	int actual = jsFilterInt(&arr,length,predicate,&result,threshold);
	assertEqual(expected, actual);
	free(result);
}

void test_jsFilterInt_gives_result_for_threshold_less_than_all() {
	int arr[] = {1,2,3,4,5},*result,length=5,expected=5,threshold=-3;
	int actual = jsFilterInt(&arr,length,predicate,&result,threshold);
	assertEqual(expected, actual);
	assert(result[0] == 1);
	assert(result[1] == 2);
	assert(result[2] == 3);
	assert(result[3] == 4);
	assert(result[4] == 5);
	free(result);
}

void test_jsFilterChar_gives_0_for_0_length() {
	char *arr,*result;
	int length=0,expected=0,threshold=9;
	int actual = jsFilterChar(&arr,length,predicate,&result,threshold);
	assertEqual(expected, actual);
	free(result);
}

void test_jsFilterChar_gives_0_for_negative_length() {
	char *arr,*result;
	int length=0,expected=0,threshold=9;
	int actual = jsFilterChar(&arr,length,predicate,&result,threshold);
	assertEqual(expected, actual);
	free(result);
}

void test_jsFilterChar_gives_lenght_of_filtered_array_for_positiveChar_length() {
	char arr[] = {'a','b','c','d','e'},*result,threshold = 'c';
	int length=5,expected=3;
	int actual = jsFilterChar(&arr,length,predicate,&result,threshold);
	assertEqual(expected, actual);
	assert(result[0] == 'c');
	assertEqual(result[1], 'd');
	assertEqual(result[2], 'e');
	free(result);
}

void test_jsMapInt_gives_0_for_0_length() {
	int arr[] = {1},length = 0,expected=0,actual;
	actual = jsMapInt(&arr,length,increament);
	assertEqual(expected, actual);
}

void test_jsMapInt_gives_0_for_negative_length() {
	int arr[] = {1},length = -3,expected=0,actual;
	actual = jsMapInt(&arr,length,increament);
	assertEqual(expected, actual);
}

void test_jsMapInt_gives_2_3_4_for_1_2_3_() {
	int arr[] = {1,2,3},length = 3,*actual;
	actual = jsMapInt(&arr,length,increament);
	assert(actual[0] == 2);
	assert(actual[1] == 3);
	assert(actual[2] == 4);
}

void test_jsMapInt_gives_0_0_0() {
	int arr[] = {-1,-1,-1},length = 3,*actual;
	actual = jsMapInt(&arr,length,increament);
	assert(actual[0] == 0);
	assert(actual[1] == 0);
	assert(actual[2] == 0);
}

void test_jsMapChar_gives_0_for_0_length() {
	char arr[] = {'a'};
	int length = 0,expected=0,actual;
	actual = jsMapChar(&arr,length,lowerCaseToUpperCase);
	assertEqual(expected, actual);
}

void test_jsMapChar_gives_0_for_negative_length() {
	char arr[] = {'a'};
	int length = -3,expected=0,actual;
	actual = jsMapChar(&arr,length,lowerCaseToUpperCase);
	assertEqual(expected, actual);
}

void test_jsMapChar_gives_a_b_c_for_A_B_C_() {
	char arr[] = {'a','b','c'},*actual;
	int length = 3;
	actual = jsMapChar(&arr,length,lowerCaseToUpperCase);
	assert(actual[0] == 'A');
	assert(actual[1] == 'B');
	assert(actual[2] == 'C');
}

void test_indexOf_gives_negative_if_character_is_not_found() {
	char string[] = "prasenjit",letter;
	int position;
	letter = 'y';
	position = indexOf(string,letter);
	assert(position==-1);
}

void test_indexOf_gives_position_if_character_is_found() {
	char string[] = "prasenjit",letter;
	int position;
	letter = 'p';
	position = indexOf(string,letter);
	assertEqual(position,0);
}

void test_reduce_returns_0_for_0_length() {
	int *arr[] = {1,2,3,4},result,length = 0;
	result = reduceInt(&arr,length,add,0);
	assertEqual(result,0);
}

void test_reduce_returns_0_for_negative_length() {
	int *arr[] = {1,2,3,4},result,length = -420;
	result = reduceInt(&arr,length,add,0);
	assertEqual(result,0);
}

void test_reduce_returns_10_for_add_with_following_array() {
	int *arr[] = {1,2,3,4},result,length = 4;
	result = reduceInt(&arr,length,add,0);
	assertEqual(result,10);
}

void test_reduce_returns_15_for_add_with_following_array() {
	int *arr[] = {1,2,3,4,5},result,length = 5;
	result = reduceInt(&arr,length,add,0);
	assertEqual(result,15);
}

void test_reduce_returns_5_for_add_with_following_array() {
	int *arr[] = {1,2,3,4,-5},result,length = 5;
	result = reduceInt(&arr,length,add,0);
	assertEqual(result,5);
}

void test_reduce_returns_o_for_largerChar_with_following_array() {
	char *arr[] = {'a','b','c','d','e'},result;
	int length = 5;
	result = reduceChar(&arr,length,largeChar,'o');
	assertEqual(result,'o');
}

void test_reduce_returns_y_for_largerChar_with_following_array() {
	char *arr[] = {'a','b','c','d','e'},result;
	int length = 5;
	result = reduceChar(&arr,length,largeChar,'y');
	assertEqual(result,'y');
}

void test_jsMapStrig_returns_result_array(){
	char *a[] = {"prasenjit","chakraborty"},**output,*w[]={"PRASENJIT","CHAKRABORTY"};
	output = jsMapStrig(a,2,lowerCaseToUpperCase);
	assert(strcmp(output[0],w[0])==0);
	assert(strcmp(output[1],w[1])==0);
}

void test_indexOfString_returns_starting_position_of_a_substring_if_it_is_present_in_the_string() {
	char *str[] = {"prasenjit"},*subStr[] = {"sen"};
	int expected = 4,actual;
	actual = indexOfString(str,subStr);
	assertEqual(expected,actual);
}