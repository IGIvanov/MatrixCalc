#include "MyForm.h"
#include "Header.hpp"

//Вычислить умножение/деление матрицы на число
System::Void Matrix::MyForm::button10_Click(System::Object^ sender, System::EventArgs^ e) {
	double koef{ 0 }; //множитель/делитель
	bool numberIsNull{ 0 }; //проверка деления на ноль
	DeleteColumnRow(dataGridView4);
	if (CheckTextBox(textBox5, &koef)) {
		if (radioButton18->Checked) {
			if (rowCountA != 0 && columnCountA != 0) {
				C = new double* [rowCountA];
				if (radioButton4->Checked) NumberMultiply(A, C, rowCountA, columnCountA, &koef);
				if (radioButton3->Checked) NumberDevide(A, C, rowCountA, columnCountA, &koef, &numberIsNull);
				if (numberIsNull != 1) {
					PrintMatrix(dataGridView4, C, rowCountA, columnCountA);
					DeleteArray(C, rowCountA, columnCountA);
				}

			}
			else System::Windows::Forms::MessageBox::Show("Выбрана не та матрица или она не создана", "Ошибка!");
		}
		if (radioButton17->Checked) {
			if (rowCountB != 0 && columnCountB != 0) {
				C = new double* [rowCountB];
				if (radioButton4->Checked) NumberMultiply(B, C, rowCountB, columnCountB, &koef);
				if (radioButton3->Checked) NumberDevide(B, C, rowCountB, columnCountB, &koef, &numberIsNull);
				if (numberIsNull != 1) {
					PrintMatrix(dataGridView4, C, rowCountB, columnCountB);
					DeleteArray(C, rowCountB, columnCountB);
				}
			}
			else System::Windows::Forms::MessageBox::Show("Выбрана не та матрица или она не создана", "Ошибка!");
		}
	}
}

//Очистка результата умножения/деления на число
System::Void Matrix::MyForm::button9_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView4);
}

void NumberMultiply(double** initMatrix, double** resultMatrix, int rowCount, int columnCount, double* koef) {
	for (int i = 0; i < rowCount; i++) resultMatrix[i] = new double[columnCount];
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			resultMatrix[i][j] = *koef * initMatrix[i][j];
		}
	}
}

void NumberDevide(double** initMatrix, double** resultMatrix, int rowCount, int columnCount, double* koef, bool* numberIsNull) {
	for (int i = 0; i < rowCount; i++) resultMatrix[i] = new double[columnCount];
	if (*koef != 0) {
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				resultMatrix[i][j] = initMatrix[i][j] / *koef;
			}
		}
	}
	else {
		System::Windows::Forms::MessageBox::Show("Делить на ноль нельзя!", "Ошибка!");
		*numberIsNull = 1;
	}
}