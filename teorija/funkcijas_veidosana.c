//data_type_of_returned_value user_funcion(place_of_arguments){ place_for_actions; return returned_value;}
// function can be with or without arguments
// funcion can be without return data_type_of_returned_value - void
//
// 1. function without arguments, without return
// 2. function without arguments, with return
// 3. function with arguments, without return
// 4. function with arguments, with return
//
// function can be defined before main
// function can be declared before main and defined after main


#include <stdio.h>

int a2 = 0; //globalais mainigais

void my_first_function()
{
	printf("Hello world! From my first function\n");
}

int my_second_function();

void my_third_function(int in_a_3)
{
	printf("Hello World From my third function\n");
	printf("in_a_3 = %d from third function\n",in_a_3);
}

double my_fourth_function(int pirmais, int otrais)
{
	double result = (float) pirmais / otrais;
	printf("Hello world! From my fourth function\n");
	return result;
}


int main()
{
	printf("Hello world! From main function\n");

	int a_main;

	my_first_function();

	my_third_function(5);

	a_main = my_second_function();
	printf("a_main = %d from main function \n",a_main);

	printf("output of second function = %d \n",my_second_function());

	double result_fourth = my_fourth_function(5,4);

	printf("result = %.3f from fourth function\n",result_fourth);
	return 0;

}

int my_second_function()
{
	int a2 = 10;
	printf("Hello world! From my seond function\n");
	return a2; //local variable, cant be used in main()
}
