#include "MyForm.h"
#include "Header.hpp"

//Вычисление определителя
System::Void Matrix::MyForm::button14_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox6->Text = L"";
	if (radioButton8->Checked) {
		A = new double* [rowCountA];
		CreateArray(dataGridView1, A, rowCountA, columnCountA, &isArrayExistA);
		if (isArrayExistA == true) {
			if (rowCountA == columnCountA) {
				textBox6->Text = System::Convert::ToString(DeterminantCalc(A, rowCountA));
				DeleteArray(A, rowCountA, columnCountA, isArrayExistA);
			} else System::Windows::Forms::MessageBox::Show(
			"Определитель существует только у квадратной матрицы", "Ошибка!");
		} 
	}
	
	if (radioButton7->Checked) {
		B = new double* [rowCountB];
		CreateArray(dataGridView2, B, rowCountB, columnCountB, &isArrayExistB);
		if (isArrayExistB == true) {
			if (rowCountB == columnCountB) {
				textBox6->Text = System::Convert::ToString(DeterminantCalc(B, rowCountB));
				DeleteArray(B, rowCountB, columnCountB, isArrayExistB);
			} else System::Windows::Forms::MessageBox::Show(
			"Определитель существует только у квадратной матрицы", "Ошибка!");
		}
	}
}

//Удаление результата вычисления определителя
System::Void Matrix::MyForm::button13_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox6->Text = L"";
}