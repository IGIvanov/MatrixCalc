#include "MyForm.h"
#include "Header.hpp"

//Приведение матрицы к ступенчатому виду
System::Void Matrix::MyForm::button22_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView8);
	if (radioButton16->Checked) {
		A = new double* [rowCountA];
		CreateArray(dataGridView1, A, rowCountA, columnCountA, &isArrayExistA);
		if (isArrayExistA == true) {
			C = new double* [rowCountA];
			isArrayExistC = true;
			ToStepMatrix(A, C, rowCountA, columnCountA);
			PrintMatrix(dataGridView8, C, rowCountA, columnCountA);
			DeleteArray(C, rowCountA, columnCountA, isArrayExistC);
			DeleteArray(A, rowCountA, columnCountA, isArrayExistA);
		} 
	}

	if (radioButton15->Checked) {
		B = new double* [rowCountB];
		CreateArray(dataGridView2, B, rowCountB, columnCountB, &isArrayExistB);
		if (isArrayExistB == true) {
			C = new double* [rowCountB];
			isArrayExistC = true;
			ToStepMatrix(B, C, rowCountB, columnCountB);
			PrintMatrix(dataGridView8, C, rowCountB, columnCountB);
			DeleteArray(C, rowCountB, columnCountB, isArrayExistC);
			DeleteArray(B, rowCountB, columnCountB, isArrayExistB);
		} 
	}
}

// Очистка результата приведения матрицы к ступенчатому виду
System::Void Matrix::MyForm::button21_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView8);
}