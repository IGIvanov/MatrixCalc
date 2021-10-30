#include "MyForm.h"
#include "Header.hpp"

//Нахождение обратной матрицы
System::Void Matrix::MyForm::button16_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView6);
	if (radioButton10->Checked) {
		A = new double* [rowCountA];
		CreateArray(dataGridView1, A, rowCountA, columnCountA, &isArrayExistA);
		if (isArrayExistA == true) {
			if (rowCountA == columnCountA) {
				if (DeterminantCalc(A, rowCountA) != 0) {
					C = new double* [rowCountA];
					isArrayExistC = true;
					InverseMatrixCalc(A, C, rowCountA);
					PrintMatrix(dataGridView6, C, rowCountA, columnCountA);
					DeleteArray(C, rowCountA, columnCountA, isArrayExistC);
					DeleteArray(A, rowCountA, columnCountA, isArrayExistA);
				}
				else System::Windows::Forms::MessageBox::Show(
					"Определитель равен нулю - обратной матрицы не существует", "Ошибка!");
			}
			else System::Windows::Forms::MessageBox::Show(
				"Обратная матрица существует только для квадратной матрицы", "Ошибка!");
		}
	}

	if (radioButton9->Checked) {
		B = new double* [rowCountB];
		CreateArray(dataGridView2, B, rowCountB, columnCountB, &isArrayExistB);
		if (isArrayExistB == true) {
			if (rowCountB == columnCountB) {
				if (DeterminantCalc(B, rowCountB) != 0) {
					C = new double* [rowCountB];
					isArrayExistC = true;
					InverseMatrixCalc(B, C, rowCountB);
					PrintMatrix(dataGridView6, C, rowCountB, columnCountB);
					DeleteArray(C, rowCountB, columnCountB, isArrayExistC);
					DeleteArray(B, rowCountB, columnCountB, isArrayExistB);
				}
				else System::Windows::Forms::MessageBox::Show(
					"Определитель равен нулю - обратной матрицы не существует", "Ошибка!");
			}
			else System::Windows::Forms::MessageBox::Show(
				"Обратная матрица существует только для квадратной матрицы", "Ошибка!");
		}
	}
}

//Удаление результата вычисления обратной матрицы
System::Void Matrix::MyForm::button15_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView6);
}
