//#include <iostream>
//#include <string>
//#include <ctime>
//
//using namespace std;
//
//void MyTestFunc(int intsValues[], int size);
//template <typename T, size_t N>
//int Length(T(&values)[N]);
//
//void TestFunc(int& values) {
//	values++;
//}
//
//int main() {
//	setlocale(LC_ALL, "Rus");
//	srand(time(NULL));
//	int value;
//	cin >> value;
//	cout << value;

//	//int firstValue = 5;
//	//int* pFirstValue = &firstValue;
//	//cout << pFirstValue << endl;
//	//cout << *pFirstValue;
//	//*pFirstValue = 2;
//	//cout << *pFirstValue;
//
//	//TestFunc(*pFirstValue);
//	//cout << *pFirstValue;
//}
//
//
//void MyTestFunc(int intsValues[], int size) {
//	for (int i = 0; i < size; i++) {
//		cout << intsValues[i] << "\n";
//	}
//}
//
//
//template <typename T, size_t N>
//int Length(T(values)[N]) {
//	return N;
//}

//			\b	-	Удаление последнего символа
//			\n	-	Перейти на начало новой строки
//			\t	-	Перейти к следующей позиции табуляции

//			\\	-	Вывести обратную черту
//			\"	-	Вывести двойную кавычку
//			\'	-	Вывести одинарную кавычку


#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <winuser.h>
#include <time.h>

enum CalculatorOperation {
	Sum = 1,
	Minus,
	Multiply,
	Divide
};

enum Input {
	Left,
	Right,
	Down,
	Up
};

void Calculator() {
	CalculatorOperation operation = Sum;
	bool selectOperationInputResult = false;
	int actionResult;
	float firstValue;
	float secondValue;
	float result;

	do {
		printf("Select action\n1 - +\n2 - -\n3 - *\n4 - /\n");
		scanf_s("%d", &actionResult);

		selectOperationInputResult = actionResult >= Sum && actionResult <= Divide;

		if (selectOperationInputResult) {
			operation = (CalculatorOperation)actionResult;
		}
		else {
			system("cls");
			printf("Error input\n");
		}
	} while (!selectOperationInputResult);

	printf("\nInput first value: ");
	scanf_s("%f", &firstValue);
	printf("\nInput second value: ");
	scanf_s("%f", &secondValue);

	switch (operation) {
	case Sum:result = firstValue + secondValue; break;
	case Minus:result = firstValue - secondValue; break;
	case Multiply:result = firstValue * secondValue; break;
	case Divide:result = firstValue / secondValue; break;
	}

	printf("Result = %.2f", result);
}

void ShowScreen(int xSize, int ySize, int currentPlayerYPosition, int currentPlayerXPosition, bool isFirstShow, int applePosX, int applePosY) {
	system("cls");

	for (int y = 0; y < ySize; y++) {
		for (int x = 0; x < xSize; x++) {
			if (x == 0 || y == 0 || x == xSize - 1 || y == ySize - 1) {
				printf("#");
				continue;
			}

			if (applePosX == x && applePosY == y) {
				printf("*");
				continue;
			}

			if (currentPlayerYPosition == y && currentPlayerXPosition == x) {
				printf("@");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main() {
	/*Calculator();*/
	int const xSize = 100;
	int const ySize = 10;
	int currentPlayerXPosition = 50;
	int currentPlayerYPosition = 5;
	int appleCounter = 0;
	char arr[ySize][xSize];
	char inputChar;
	Input input;

	srand(time(NULL));
	int appleXPos = rand() * 1.0 / RAND_MAX * xSize + 1;
	int appleYPos = rand() * 1.0 / RAND_MAX * ySize + 1;

	ShowScreen(xSize, ySize, currentPlayerYPosition, currentPlayerXPosition, true, appleXPos, appleYPos);

	while (true) {
		inputChar = _getch();

		if (inputChar == 'w') {
			if (currentPlayerYPosition - 1 >= 1) {
				currentPlayerYPosition--;
			}
		}
		else if (inputChar == 's') {
			if (currentPlayerYPosition + 1 < ySize - 1) {
				currentPlayerYPosition++;
			}
		}
		else if (inputChar == 'd') {
			if (currentPlayerXPosition + 1 < xSize - 1) {
				currentPlayerXPosition++;
			}
		}
		else if (inputChar == 'a') {
			if (currentPlayerXPosition - 1 >= 1) {
				currentPlayerXPosition--;
			}
		}
		else {
			ShowScreen(xSize, ySize, currentPlayerYPosition, currentPlayerXPosition, false, appleXPos, appleYPos);
			printf("Check keyboard");
			continue;
		}
		if (currentPlayerYPosition == appleYPos && currentPlayerXPosition == appleXPos) {
			appleXPos = rand() * 1.0 / RAND_MAX * (xSize - 1) + 1;
			appleYPos = rand() * 1.0 / RAND_MAX * (ySize - 1) + 1;
			appleCounter++;
		}

		ShowScreen(xSize, ySize, currentPlayerYPosition, currentPlayerXPosition, false, appleXPos, appleYPos);
		printf("Apple count: %d", appleCounter);
	}
}