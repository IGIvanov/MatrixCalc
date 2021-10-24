#include "MyForm.h"
#include "Header.hpp"

//Записать данные в массив A[][]
System::Void Matrix::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	A = new double* [rowCountA];
	if (rowCountA > 0 && columnCountA > 0) {
		CreateArray(dataGridView1, A, rowCountA, columnCountA);
	}
}

//Записать данные в массив B[][]
System::Void Matrix::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	B = new double* [rowCountB];
	if (rowCountB > 0 && columnCountB > 0) {
		CreateArray(dataGridView2, B, rowCountB, columnCountB);
	}
}

void CreateArray(System::Windows::Forms::DataGridView^ matrix, double** array, int rowCount, int columnCount) {
	double number;
	System::String^ str;
	bool isFailed{ 0 };
	for (int i = 0; i < rowCount; i++) array[i] = new double[columnCount];
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			str = matrix->Rows[i]->Cells[j]->FormattedValue->ToString();
			if (System::Double::TryParse(str, number)) {
				array[i][j] = number;
			}
			else {
				System::Windows::Forms::MessageBox::Show(
					"Некоторые ячейки матрицы не заполнены или данные некорректны", "Ошибка!");
				isFailed = 1;
				array = nullptr;
				break;
			}
		}
		if (isFailed) break;
	}
	if (array!=nullptr) System::Windows::Forms::MessageBox::Show("Данные считаны", "Готово");
}

void DeleteArray(double** array, int rowCount, int columnCount) {
	if (rowCount != 0 && columnCount != 0) {
		for (int i = 0; i < rowCount; i++) delete[]array[i];
		delete[]array;
	}
}

