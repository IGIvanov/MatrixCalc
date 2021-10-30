#include "MyForm.h"
#include "Header.hpp"

//¬ычислить умножение/деление матрицы на число
System::Void Matrix::MyForm::button10_Click(System::Object^ sender, System::EventArgs^ e) {
	double koef{ 0 }; //множитель/делитель
	bool numberIsNull{ 0 }; //проверка делени€ на ноль
	DeleteColumnRow(dataGridView4);
	if (CheckTextBox(textBox5, &koef)) {
		if (radioButton18->Checked) {
			A = new double* [rowCountA];
			CreateArray(dataGridView1, A, rowCountA, columnCountA, &isArrayExistA);
			if (isArrayExistA == true) {
				C = new double* [rowCountA];
				isArrayExistC = true;
				if (radioButton4->Checked) NumberMultiply(A, C, rowCountA, columnCountA, &koef);
				if (radioButton3->Checked) NumberDevide(A, C, rowCountA, columnCountA, &koef, &numberIsNull);
				if (numberIsNull != 1) {
					PrintMatrix(dataGridView4, C, rowCountA, columnCountA);
					DeleteArray(C, rowCountA, columnCountA, isArrayExistC);
					DeleteArray(A, rowCountA, columnCountA, isArrayExistA);
				}

			}
		}
		if (radioButton17->Checked) {
			B = new double* [rowCountB];
			CreateArray(dataGridView2, B, rowCountB, columnCountB, &isArrayExistB);
			if (isArrayExistB == true) {
				C = new double* [rowCountB];
				isArrayExistC = true;
				if (radioButton4->Checked) NumberMultiply(B, C, rowCountB, columnCountB, &koef);
				if (radioButton3->Checked) NumberDevide(B, C, rowCountB, columnCountB, &koef, &numberIsNull);
				if (numberIsNull != 1) {
					PrintMatrix(dataGridView4, C, rowCountB, columnCountB);
					DeleteArray(C, rowCountB, columnCountB, isArrayExistC);
					DeleteArray(B, rowCountB, columnCountB, isArrayExistB);
				}
			}
		}
	}
}

//ќчистка результата умножени€/делени€ на число
System::Void Matrix::MyForm::button9_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView4);
}