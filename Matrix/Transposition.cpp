#include "MyForm.h"
#include "Header.hpp"

//Транспонирование матрицы
System::Void Matrix::MyForm::button20_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView7);
	if (radioButton14->Checked) {
		A = new double* [rowCountA];
		CreateArray(dataGridView1, A, rowCountA, columnCountA, &isArrayExistA);
		if (isArrayExistA == true) {
			C = new double* [columnCountA];
			isArrayExistC = true;
			TranspositionCalc(A, C, rowCountA, columnCountA);
			PrintMatrix(dataGridView7, C, columnCountA, rowCountA);
			DeleteArray(C, columnCountA, rowCountA, isArrayExistC);
			DeleteArray(A, columnCountA, rowCountA, isArrayExistA);
		}
	}

	if (radioButton13->Checked) {
		B = new double* [rowCountB];
		CreateArray(dataGridView2, B, rowCountB, columnCountB, &isArrayExistB);
		if (isArrayExistB == true) {
			C = new double* [columnCountB];
			isArrayExistC = true;
			TranspositionCalc(B, C, rowCountB, columnCountB);
			PrintMatrix(dataGridView7, C, columnCountB, rowCountB);
			DeleteArray(C, columnCountB, rowCountB, isArrayExistC);
			DeleteArray(B, columnCountB, rowCountB, isArrayExistB);
		}
	}
}

//Очистка результата транспонирования матрицы
System::Void Matrix::MyForm::button19_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView7);
}