#include "MyForm.h"
#include "Header.hpp"

System::Void Matrix::MyForm::button12_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView5);
	A = new double* [rowCountA];
	CreateArray(dataGridView1, A, rowCountA, columnCountA, &isArrayExistA);
	B = new double* [rowCountB];
	CreateArray(dataGridView2, B, rowCountB, columnCountB, &isArrayExistB);

	if (isArrayExistA == true && isArrayExistB == true) {
		if (radioButton6->Checked) {
			if (columnCountA == rowCountB) {
				C = new double* [rowCountA];
				isArrayExistC = true;
				MatrixMultiply(A, B, C, rowCountA, columnCountA, rowCountB, columnCountB);
				PrintMatrix(dataGridView5, C, rowCountA, columnCountB);
				DeleteArray(C, rowCountA, columnCountB, isArrayExistC);
				DeleteArray(A, rowCountA, columnCountA, isArrayExistA);
				DeleteArray(B, rowCountB, columnCountB, isArrayExistB);
			} else System::Windows::Forms::MessageBox::Show("Произведение A*B невозможно: \
количество столбцов матрицы A должно быть равно количеству строк матрицы B", "Ошибка!");
		}
		if (radioButton5->Checked) {
			if (columnCountB == rowCountA) {
				C = new double* [rowCountB];
				isArrayExistC = true;
				MatrixMultiply(B, A, C, rowCountB, columnCountB, rowCountA, columnCountA);
				PrintMatrix(dataGridView5, C, rowCountB, columnCountA);
				DeleteArray(C, rowCountB, columnCountA, isArrayExistC);
				DeleteArray(A, rowCountA, columnCountA, isArrayExistA);
				DeleteArray(B, rowCountB, columnCountB, isArrayExistB);
			} else System::Windows::Forms::MessageBox::Show("Произведение B*A невозможно: \
количество столбцов матрицы B должно быть равно количеству строк матрицы A", "Ошибка!");
		}
	}
}

//Очистка результата произведения двух матриц
System::Void Matrix::MyForm::button11_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView5);
}