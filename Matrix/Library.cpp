#include "MyForm.h" 

void AddColumnRow(System::Windows::Forms::DataGridView^ matrix, System::Windows::Forms::TextBox^ inputBox1, System::Windows::Forms::TextBox^ inputBox2, int *rowCount, int* columnCount) {
	int number1, number2;
	System::String^ str1 = System::Convert::ToString(inputBox1->Text);
	System::String^ str2 = System::Convert::ToString(inputBox2->Text);
	if (System::Int32::TryParse(str1, number1) && System::Int32::TryParse(str2, number2)) {
		*rowCount = number1;
		*columnCount = number2;
	}
	else {
		System::Windows::Forms::MessageBox::Show(
			"Количество строк или столбцов не указано или указано некорректно", "Ошибка!");
	}

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

void DeleteColumnRow(System::Windows::Forms::DataGridView^ matrix) {
	while ((matrix->RowCount - 1) >= 0) {
		matrix->Rows->RemoveAt(matrix->RowCount-1);
	}
	while ((matrix->ColumnCount - 1) >= 0) {
		matrix->Columns->RemoveAt(matrix->ColumnCount - 1);
	}
}

void DeleteArray(double** array, int rowCount) {
	for (int i = 0; i < rowCount; i++) delete[]array[i];
	delete[]array;
}

void Summa(double** A, double** B, double** C, int rowCount, int columnCount) {
	for (int i = 0; i < rowCount; i++) C[i] = new double[columnCount];
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void Difference(double** A, double** B, double** C, int rowCount, int columnCount) {
	for (int i = 0; i < rowCount; i++) C[i] = new double[columnCount];
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}

void PrintMatrix(System::Windows::Forms::DataGridView^ matrix, double** C, int rowCount, int columnCount) {
	for (int j = 0; j < columnCount; j++) {
		matrix->Columns->Add("", "");
		matrix->AutoResizeColumns();
	}
	for (int i = 0; i < rowCount; i++) {
		matrix->Rows->Add("", "");
		matrix->AutoResizeRows();
	}
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			matrix->Rows[i]->Cells[j]->Value = C[i][j];
		}
	}
}

void NumberMultiply(double** initMatrix, double** resultMatrix, int rowCount, int columnCount, double* koef) {
	for (int i = 0; i < rowCount; i++) resultMatrix[i] = new double[columnCount];
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			resultMatrix[i][j] = *koef * initMatrix[i][j];
		}
	}
}

void NumberDevide(double** initMatrix, double** resultMatrix, int rowCount, int columnCount, double* koef) {
	for (int i = 0; i < rowCount; i++) resultMatrix[i] = new double[columnCount];
	if (*koef != 0) {
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				resultMatrix[i][j] = initMatrix[i][j]/ *koef;
			}
		} 
	}
	else {
		System::Windows::Forms::MessageBox::Show("Делить на ноль нельзя!", "Ошибка!");
		//resultMatrix = nullptr;
	}
}

bool CheckTextBox(System::Windows::Forms::TextBox^ inputBox, double* number) {
	bool isNumber;
	System::String^ str = System::Convert::ToString(inputBox->Text);
	if (System::Double::TryParse(str, *number)) {
		isNumber = true;
	} else System::Windows::Forms::MessageBox::Show("Число не указано или указано неверно", "Ошибка!");
	return isNumber;
}