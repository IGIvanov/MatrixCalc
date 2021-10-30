#include "MyForm.h"
#include "Header.hpp"

int rowCountA{ 0 }, columnCountA{ 0 }, rowCountB{ 0 }, columnCountB{ 0 }, rowCountC{ 0 }, columnCountC{ 0 };
bool isArrayExistA = false, isArrayExistB = false, isArrayExistC = false;
double** A;
double** B;
double** C;

//���������� ����� � �������� � dataGridView
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

//�������� ����� � �������� �� dataGridView
void DeleteColumnRow(System::Windows::Forms::DataGridView^ matrix) {
	while ((matrix->RowCount - 1) >= 0) {
		matrix->Rows->RemoveAt(matrix->RowCount - 1);
	}
	while ((matrix->ColumnCount - 1) >= 0) {
		matrix->Columns->RemoveAt(matrix->ColumnCount - 1);
	}
}

//�������� textBox �� ������������ ����� ������ ��� ���� double
bool CheckTextBox(System::Windows::Forms::TextBox^ inputBox, double* number) {
	bool isNumber;
	System::String^ str = System::Convert::ToString(inputBox->Text);
	if (System::Double::TryParse(str, *number)) {
		isNumber = true;
	}
	else System::Windows::Forms::MessageBox::Show("����� �� ������� ��� ������� �������", "������!");
	return isNumber;
}

//�������� textBox �� ������������ ����� ������ ��� ���� int
bool CheckTextBox(System::Windows::Forms::TextBox^ inputBox, int* number) {
	bool isNumber;
	System::String^ str = System::Convert::ToString(inputBox->Text);
	if (System::Int32::TryParse(str, *number)) {
		isNumber = true;
	}
	else System::Windows::Forms::MessageBox::Show("����� �� ������� ��� ������� �������", "������!");
	return isNumber;
}

//�������� ������������� �������, ������ ��������� � dataGridView ������
void CreateArray(System::Windows::Forms::DataGridView^ matrix, double** array, int rowCount, int columnCount, 	bool *isArrayExist) {
	if (rowCount > 0 && columnCount > 0) {
		double number;
		System::String^ str;
		for (int i = 0; i < rowCount; i++) array[i] = new double[columnCount];
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				str = matrix->Rows[i]->Cells[j]->FormattedValue->ToString();
				if (System::Double::TryParse(str, number)) {
					array[i][j] = number;
					*isArrayExist = true;
				}
				else {
					System::Windows::Forms::MessageBox::Show(
						"��������� ������ ������� �� ��������� ��� ������ �����������", "������!");
					*isArrayExist = false;
					break;
				}
			}
			if (*isArrayExist == false) break;
		}
	} else System::Windows::Forms::MessageBox::Show(
		"���� ��� ��� ������� �� ������������", "������!");
}

//�������� ������������� �������
void DeleteArray(double** array, int rowCount, int columnCount, bool isArrayExist) {
	if (isArrayExist == true) {
		for (int i = 0; i < rowCount; i++) delete[]array[i];
		delete[]array;
	}
	isArrayExist = false;
}

//��������� ������� �� �����
void NumberMultiply(double** initMatrix, double** resultMatrix, int rowCount, int columnCount, double* koef) {
	for (int i = 0; i < rowCount; i++) resultMatrix[i] = new double[columnCount];
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			resultMatrix[i][j] = *koef * initMatrix[i][j];
		}
	}
}

//������� ������� �� �����
void NumberDevide(double** initMatrix, double** resultMatrix, int rowCount, int columnCount, double* koef, bool* numberIsNull) {
	for (int i = 0; i < rowCount; i++) resultMatrix[i] = new double[columnCount];
	if (*koef != 0) {
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				resultMatrix[i][j] = initMatrix[i][j] / *koef;
			}
		}
	}
	else {
		System::Windows::Forms::MessageBox::Show("������ �� ���� ������!", "������!");
		*numberIsNull = 1;
	}
}

//����� (������) ������� � dataGridView
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
			matrix->Columns[j]->Width = 50;
		}
	}
}

//����� ���� ������
void Summa(double** A, double** B, double** C, int rowCount, int columnCount) {
	for (int i = 0; i < rowCount; i++) C[i] = new double[columnCount];
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

//�������� ���� ������
void Difference(double** A, double** B, double** C, int rowCount, int columnCount) {
	for (int i = 0; i < rowCount; i++) C[i] = new double[columnCount];
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}

//������������ ������
void MatrixMultiply(double** matrix1, double** matrix2, double** matrix3, int row1, int column1, int row2, int column2) {
	for (int i = 0; i < row1; i++) C[i] = new double[column2];
	for (int m = 0; m < row1; m++) {
		for (int n = 0; n < column2; n++) {
			matrix3[m][n] = 0;
		}
	}
	
	for (int m = 0; m < row1; m++) {
		for (int n = 0; n < column2; n++) {
			for (int k = 0; k < column1; k++) {
				matrix3[m][n] = matrix3[m][n] + matrix1[m][k] * matrix2[k][n];
			}
		}
	}
}

//���������� ������� � ������������ ����
void ToStepMatrix(double** initMatrix, double** resultMatrix, int rowCount, int columnCount) {
	for (int i = 0; i < rowCount; i++) resultMatrix[i] = new double[columnCount];
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			resultMatrix[i][j] = initMatrix[i][j];
		}
	}

	for (int k = 0; k < rowCount - 1; k++) {
		if (resultMatrix[k][k] == 0) DiagonalNotNull(resultMatrix, rowCount, columnCount, k);
		for (int i = k + 1; i < rowCount; i++) {
			for (int j = columnCount - 1; j >= k; j--) {
				resultMatrix[i][j] = resultMatrix[i][j] * resultMatrix[k][k] -
									 resultMatrix[k][j] * resultMatrix[i][k];
			}
		}
	}
}

//������ ������� ������������ ����������� �� ��������� (��� ���������� � ������������ ����)
void DiagonalNotNull(double** matrix, int rowCount, int columnCount, int k) {
	for (int i = k + 1; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
			matrix[k][j] = matrix[k][j] + matrix[i][j];
		}
		if (matrix[k][k] != 0) break;
	}
	if (matrix[k][k] == 0) {
		for (int i = k + 1; i < columnCount; i++) {
			for (int j = 0; j < rowCount; j++) {
				matrix[j][k] = matrix[j][k] + matrix[j][i];
			}
			if (matrix[k][k] != 0) break;
		}
	}
}

//������ ������� ������������ ����������� �� ��������� (��� ���������� �������� �������)
void DiagonalNotNull(double** initMatrix, double** resultMatrix, int count, int k) {
	for (int i = k + 1; i < count; i++) {
		for (int j = 0; j < count; j++) {
			initMatrix[k][j] = initMatrix[k][j] + initMatrix[i][j];
			resultMatrix[k][j] = resultMatrix[k][j] + resultMatrix[i][j];
		}
		if (initMatrix[k][k] != 0) break;
	}
}

//���������� ������������ �������
double DeterminantCalc(double** initMatrix, int count) {
	double** resultMatrix = new double* [count];
	for (int i = 0; i < count; i++) resultMatrix[i] = new double[count];
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			resultMatrix[i][j] = initMatrix[i][j];
		}
	}

	double divider{ 1 };
	for (int k = 0; k < count - 1; k++) {
		if (resultMatrix[k][k] == 0) DiagonalNotNull(resultMatrix, count, count, k);
		for (int i = k + 1; i < count; i++) {
			for (int j = count - 1; j >= k; j--) {
				resultMatrix[i][j] = resultMatrix[i][j] * resultMatrix[k][k] -
									 resultMatrix[k][j] * resultMatrix[i][k];
			}
			divider = divider * resultMatrix[k][k];
		}
	}

	double determinant{ 1 };
	for (int i = 0; i < count; i++) {
		determinant = determinant * resultMatrix[i][i];
		if (determinant == 0) break;
	}
	return determinant / divider;
}

//���������� �������� �������
void InverseMatrixCalc(double** initMatrix, double** inverseMatrix, int count) {
	for (int i = 0; i < count; i++) inverseMatrix[i] = new double[count];
	double** unitMatrix = new double* [count];
	for (int i = 0; i < count; i++) unitMatrix[i] = new double[count];
	
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (i == j) inverseMatrix[i][j] = 1;
			else inverseMatrix[i][j] = 0;
			unitMatrix[i][j] = initMatrix[i][j];
		}
	}

	double equalCoef1, equalCoef2;
	for (int k = 0; k < count - 1; k++) {
		if (unitMatrix[k][k] == 0) DiagonalNotNull(unitMatrix, inverseMatrix, count, k);
		for (int i = k + 1; i < count; i++) {
			equalCoef1 = unitMatrix[i][k];
			for (int j = count - 1; j >= 0; j--) {
				inverseMatrix[i][j] = inverseMatrix[i][j] * unitMatrix[k][k] -
									 inverseMatrix[k][j] * equalCoef1;
				unitMatrix[i][j]= unitMatrix[i][j] * unitMatrix[k][k] -
								  unitMatrix[k][j] * unitMatrix[i][k];
			}
		}
	}

	for (int k = count - 1; k > 0; k--) {
		for (int i = k - 1; i >= 0; i--) {
			equalCoef2 = unitMatrix[i][k];
			for (int j = 0; j < count; j++) {
				inverseMatrix[i][j] = inverseMatrix[i][j] * unitMatrix[k][k] -
									 inverseMatrix[k][j] * equalCoef2;
				unitMatrix[i][j] = unitMatrix[i][j] * unitMatrix[k][k] -
								   unitMatrix[k][j] * unitMatrix[i][k];
			}
		}
	}

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			inverseMatrix[i][j] = inverseMatrix[i][j] / unitMatrix[i][i];
		}
	}
}

int RangCalc(double** matrix, int rowCount, int columnCount) {
	double** stepMatrix = new double* [rowCount];
	for (int i = 0; i < rowCount; i++) stepMatrix[i] = new double[columnCount];
	
	ToStepMatrix(matrix, stepMatrix, rowCount, columnCount);

	int rang{ 0 };
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < columnCount; j++) {
			if (stepMatrix[i][j] != 0) {
				rang++;
				break;
			}
		}
	}

	return rang;
}

void TranspositionCalc(double** initMatrix, double** resultMatrix, int rowCount, int columnCount) {
	for (int i = 0; i < columnCount; i++) resultMatrix[i] = new double[rowCount];

	for (int i = 0; i < columnCount; i++) {
		for (int j = 0; j < rowCount; j++) {
			resultMatrix[i][j] = initMatrix[j][i];
		}
	}
}