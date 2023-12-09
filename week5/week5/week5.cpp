#include <iostream>

using namespace std;


int RecFibonacci(int n);

int LoopFibonacci(int N);


int main()
{

//********************************************************************************** While Loop **************************************************************************************

   cout << "Enter an integer between 10 and 20: ";

   int number;
   cin >> number;

   bool isValid = (number >= 10) && (number <= 20);

   while (!isValid) {

	   cout << "number is not between 10 and 20!" << endl;
	   cout << "Enter an integer between 10 and 20: ";
	   cin >> number;
	   isValid = (number >= 10) && (number <= 20);

   }

   cout << "Thanks for entering " << number << ", the number is between 10 and 20." << endl;



   cout << "Enter rows: ";
   int rows;
   cin >> rows;

   cout << "Enter columns: ";
   int columns;
   cin >> columns;

   int currentColumns = 0;

   while (currentColumns < columns) {

	   int currentRows = 0;
	   while (currentRows < rows) {

		   cout << "#";
		   currentRows++; // same as currentRow + 1
	   }

	   cout << endl;
	   currentColumns++;
   } 

   //********************************************************************************** Do While Loop **************************************************************************************
   
   do {
	   cout << "Enter an integer between 10 and 20: ";
	   cin >> number;
	   isValid = (number >= 10) && (number <= 20);

	   if (!isValid) {

		   cout << "number is not between 10 and 20!" << endl;
	   }

   } while (!isValid);

   cout << "Thanks for entering " << number << ", the number is between 10 and 20." << endl;


   //********************************************************************************** for Loop **************************************************************************************

   cout << "Enter a number: ";
   cin >> number;

   for (int i = 1; i <= number; i += 2) {   // if i is 1 then it will show Odd.

	   cout << i << " ";
   }

   cout << endl;

   for (int i = 0; i <= number; i += 2) {   

	   cout << i << " ";
   }

   cout << endl;

   cout << "Enter a number: ";
   cin >> number;

   for (int i = 0; i <= number; i++) {  

	   cout << i << " ";
   }

   cout << endl;

   for (int i = number; i >= 0; i--) {  

	   cout << i << " ";
   }

   cout << endl;

   //********************************************************************************** Continue and break **************************************************************************************

   for (int i = 0; i < 10; i++) {

	   if (i == 5) {
		   break;
	   }
	   cout << i << " ";
   }

   cout << endl;

   for (int i = 0; i < 10; i++) {

	   if (i == 5) {
		   continue;
	   }
	   cout << i << " ";
   }

   cout << endl;

   //********************************************************************************** Validating Input **************************************************************************************

   do {

	   cout << "Enter a number: ";
	   cin >> number;

	   if (cin.fail()) {

			   cin.clear();
			   cin.ignore(99, '\n');
			   cout << "That is not a number." << endl;
	   }

	   else {
		   break;
	   }

   } while (true);



}

//********************************************************************************** Loops vs Recursion

int RecFibonacci(int n) { // Using Recursion


	if (n <= 1) {

		return n;
	}
	else {

		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int LoopFibonacci(int N) { // Using Loops


	if ((N == 1)||(N == 2)) {

		return 1;
	}
	else {

		prev = 1, current = 1, next = 0;
		for (int i = 3; i <= N; ++i) {
			next = prev + current;
			prev = current;
			current = next;
		}
		return next;
	}
}