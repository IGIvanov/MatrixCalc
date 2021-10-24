#include "MyForm.h"
#include "Header.hpp"

void PrintMatrix(System::Windows::Forms::DataGridView^ matrix, double** C, int rowCount, int columnCount) {
	for (int j = 0; j < columnCount; j++) {
		matrix->Columns->Add("", "");
	}
	for (int i = 0; i < rowCount; i++) {
		matrix->Rows->Add("", "");
	}
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			matrix->Rows[i]->Cells[j]->Value = C[i][j];
			matrix->Columns[i]->Width = 50;
		}
	}
}