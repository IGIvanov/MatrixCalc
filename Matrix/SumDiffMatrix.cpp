#include "MyForm.h"
#include "Header.hpp"

//Вычисление суммы/разности матриц	
System::Void Matrix::MyForm::button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if ((rowCountA == rowCountB) && (columnCountA == columnCountB) && rowCountA != 0 && columnCountA != 0) {
		C = new double* [rowCountA];
		if (radioButton1->Checked) Summa(A, B, C, rowCountA, columnCountA);
		if (radioButton2->Checked) Difference(A, B, C, rowCountA, columnCountA);
		DeleteColumnRow(dataGridView3);
		PrintMatrix(dataGridView3, C, rowCountA, columnCountA);
		DeleteArray(C, rowCountA, columnCountA);
	}
	else System::Windows::Forms::MessageBox::Show("Размеры матриц не совпадают или они не созданы", "Ошибка!");
}

//Очистка результата суммы/разности матриц
System::Void Matrix::MyForm::button8_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView3);
}

void Summa(double** A, double** B, double** C, int rowCount, int columnCount) {
	for (int i = 0; i < rowCount; i++) C[i] = new double[columnCount];
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void Difference(double** A, double** B, double** C, int rowCount, int columnCount) {
	for (int i = 0; i < rowCount; i++) C[i] = new double[columnCount];
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}