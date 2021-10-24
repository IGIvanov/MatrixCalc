#include "MyForm.h"
#include "Header.hpp"

//Вставка указанного количества столбцов и строк в матрицу A
System::Void Matrix::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView1);
	if (CheckTextBox(textBox1, &rowCountA) && CheckTextBox(textBox2, &columnCountA)) {
		if (rowCountA != 0 && columnCountA != 0) {
			AddColumnRow(dataGridView1, &rowCountA, &columnCountA);
		}
		else System::Windows::Forms::MessageBox::Show(
			"Количество строк или столбцов не может быть нулевым", "Ошибка!");
	}
}

//Вставка указанного количества столбцов и строк в матрицу B
System::Void Matrix::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView2);
	if (CheckTextBox(textBox3, &rowCountB) && CheckTextBox(textBox4, &columnCountB)) {
		if (rowCountB != 0 && columnCountB != 0) {
			AddColumnRow(dataGridView2, &rowCountB, &columnCountB);
		}
		else System::Windows::Forms::MessageBox::Show(
			"Количество строк или столбцов не может быть нулевым", "Ошибка!");
	}
}

//Удаление строк и столбцов из матрицы А
System::Void Matrix::MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView1);
	A = nullptr;
	rowCountA = 0;
	columnCountA = 0;
}

//Удаление строк и столбцов из матрицы B
System::Void Matrix::MyForm::button6_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView2);
	B = nullptr;
	rowCountB = 0;
	columnCountB = 0;
}

void AddColumnRow(System::Windows::Forms::DataGridView^ matrix, int* rowCount, int* columnCount) {
	if (*rowCount > 0 && *columnCount > 0) {
		for (int j = 0; j < *columnCount; j++) {
			matrix->Columns->Add("", "");
			matrix->AutoResizeColumns();
		}
		for (int i = 0; i < *rowCount; i++) {
			matrix->Rows->Add("", "");
			matrix->AutoResizeRows();
		}
	}
}

void DeleteColumnRow(System::Windows::Forms::DataGridView^ matrix) {
	while ((matrix->RowCount - 1) >= 0) {
		matrix->Rows->RemoveAt(matrix->RowCount - 1);
	}
	while ((matrix->ColumnCount - 1) >= 0) {
		matrix->Columns->RemoveAt(matrix->ColumnCount - 1);
	}
}