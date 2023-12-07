#include <iostream>

using namespace std;

void Swap(int* Pnum1, int* Pnum2);
void Swap(int& num1, int& num2);

int* CreateGrades(int size);

void PopulateGrades(int* pMyGrades, int size);
void DisplayGrades(int* pMyGrades, int size);

int main()
{
 
    //********************************************************************************** Pointers ************************************************************************

	int variable = 10;
	int* pointer = &variable;

	int newVariable = *pointer; // 10
	*pointer = 20; // variable == 20

	cout << "variable: " << variable << endl; // 20
	cout << "&variable: " << &variable << endl;
	cout << "pointer: " << pointer << endl;
	cout << "&pointer: " << &pointer << endl;
	cout << "*pointer: " << *pointer << endl; // 20

	int a = 1;
	int b = 2;

	Swap(&a, &b);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	Swap(a, b);

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	//********************************************************************************** Arrays and Pointers ***************************************************************

	int myArray[3] = { 10, 20, 30 };
	int* pArray = myArray;

	cout << myArray[0] << endl; // 10
	cout << myArray[1] << endl; // 20
	cout << myArray[2] << endl; // 30

	cout << pArray[0] << endl; // 10
	cout << pArray[1] << endl; // 20
	cout << pArray[2] << endl; // 30

	cout << *(pArray + 0) << endl; // 10
	cout << *(pArray + 1) << endl; // 20
	cout << *(pArray + 2) << endl; // 30

	cout << *(myArray + 0) << endl; // 10
	cout << *(myArray + 1) << endl; // 20
	cout << *(myArray + 2) << endl; // 30

	//********************************************************************************** Dinamic Allocation *******************************************************************

	bool* pBool = new bool{ true };
	delete pBool;
	pBool = nullptr;

	float* pFloat = new float{ 20.5f };
	pFloat = new float{ 30.5f };

	delete pFloat; // delete before assigning new memory 
	pFloat = nullptr;


	int* pInt = nullptr;

	for (int i = 0; i < 5; i++) {

		pInt = new int{ rand() };
		//cout << *pInt << endl;
	}

	delete pInt;
	pInt = nullptr;

	//********************************************************************************** Dinamic Array *******************************************************************

	int size;
	cout << "How many classes do you have: " << endl;
	cin >> size;

	int* pMyGrades = CreateGrades(size);

	PopulateGrades(pMyGrades, size);
	DisplayGrades(pMyGrades, size);

	delete[] pMyGrades;
	pMyGrades = nullptr;

	cout << endl;

	//********************************************************************************** Challenges *******************************************************************
	int a1; // challenge 1
	int	b1;
	int* ptrA;
	int* ptrB;

	cout << "Please Enter a number to store in 'a': ";
	cin >> a1;

	cout << "Please Enter a number to store in 'b': ";
	cin >> b1;

	ptrA = &a1;
	ptrB = &b1;

	cout << *ptrA << endl;
	cout << *ptrB << endl;

	int Input; // challenge 2
	int* ptrI;

	ptrI = &Input;

	cout << "Enter a value to display: ";
	
	cin >> Input;
	cout << *ptrI;
}

void Swap(int* Pnum1, int* Pnum2) {

	int temp = *Pnum1;
	*Pnum1 = *Pnum2;
	*Pnum2 = temp;
}

void Swap(int& num1, int& num2) {

	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int* CreateGrades(int size) {

	int* pointer = new int[size];
	return pointer;
}

void PopulateGrades(int* pMyGrades, int size) {

	for (int i = 0; i < size; i++) {

		cin >> pMyGrades[i];
	}

}

void DisplayGrades(int* pMyGrades, int size) {

	for (int i = 0; i < size; i++) {

		cout << pMyGrades[i] << " ";
	}
}