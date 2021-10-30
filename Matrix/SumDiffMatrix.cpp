#include "MyForm.h"
#include "Header.hpp"

//���������� �����/�������� ������	
System::Void Matrix::MyForm::button7_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView3);
	if (radioButton1->Checked) {
		A = new double* [rowCountA];
		CreateArray(dataGridView1, A, rowCountA, columnCountA, &isArrayExistA);
		B = new double* [rowCountB];
		CreateArray(dataGridView2, B, rowCountB, columnCountB, &isArrayExistB);

		if (isArrayExistA == true && isArrayExistB == true) {
			if ((rowCountA == rowCountB) && (columnCountA == columnCountB)) {
				C = new double* [rowCountA];
				isArrayExistC = true;
				Summa(A, B, C, rowCountA, columnCountA);
				PrintMatrix(dataGridView3, C, rowCountA, columnCountA);
				DeleteArray(C, rowCountA, columnCountA, isArrayExistC);
				DeleteArray(A, rowCountA, columnCountA, isArrayExistA);
				DeleteArray(B, rowCountB, columnCountB, isArrayExistB);
			}
			else System::Windows::Forms::MessageBox::Show(
				"������� ������ �� ���������", "������!");
		}
	}
	
	if (radioButton2->Checked) {
		A = new double* [rowCountA];
		CreateArray(dataGridView1, A, rowCountA, columnCountA, &isArrayExistA);
		B = new double* [rowCountB];
		CreateArray(dataGridView2, B, rowCountB, columnCountB, &isArrayExistB);

		if (isArrayExistA == true && isArrayExistB == true) {
			if ((rowCountA == rowCountB) && (columnCountA == columnCountB)) {
				C = new double* [rowCountA];
				isArrayExistC = true;
				Difference(A, B, C, rowCountA, columnCountA);
				PrintMatrix(dataGridView3, C, rowCountA, columnCountA);
				DeleteArray(C, rowCountA, columnCountA, isArrayExistC);
				DeleteArray(A, rowCountA, columnCountA, isArrayExistA);
				DeleteArray(B, rowCountB, columnCountB, isArrayExistB);
			}
			else System::Windows::Forms::MessageBox::Show(
				"������� ������ �� ���������", "������!");
		}
	}
}

//������� ���������� �����/�������� ������
System::Void Matrix::MyForm::button8_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView3);
}