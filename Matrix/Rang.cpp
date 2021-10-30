#include "MyForm.h"
#include "Header.hpp"

//Вычисление ранга матрицы
System::Void Matrix::MyForm::button18_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox7->Text = L"";
	if (radioButton12->Checked) {
		A = new double* [rowCountA];
		CreateArray(dataGridView1, A, rowCountA, columnCountA, &isArrayExistA);
		if (isArrayExistA == true) {
			textBox7->Text = System::Convert::ToString(RangCalc(A, rowCountA, columnCountA));
			DeleteArray(A, rowCountA, columnCountA, isArrayExistA);
		}
	}

	if (radioButton11->Checked) {
		B = new double* [rowCountB];
		CreateArray(dataGridView2, B, rowCountB, columnCountB, &isArrayExistB);
		if (isArrayExistB == true) {
			textBox7->Text = System::Convert::ToString(RangCalc(B, rowCountB, columnCountB));
			DeleteArray(B, rowCountB, columnCountB, isArrayExistB);
		}
	}
}

//Очистка результата вычисления ранга матрицы
System::Void Matrix::MyForm::button17_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox7->Text = L"";
}