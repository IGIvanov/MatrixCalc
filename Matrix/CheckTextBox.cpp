#include "MyForm.h"
#include "Header.hpp"

bool CheckTextBox(System::Windows::Forms::TextBox^ inputBox, double* number) {
	bool isNumber;
	System::String^ str = System::Convert::ToString(inputBox->Text);
	if (System::Double::TryParse(str, *number)) {
		isNumber = true;
	}
	else System::Windows::Forms::MessageBox::Show("Число не указано или указано неверно", "Ошибка!");
	return isNumber;
}

bool CheckTextBox(System::Windows::Forms::TextBox^ inputBox, int* number) {
	bool isNumber;
	System::String^ str = System::Convert::ToString(inputBox->Text);
	if (System::Int32::TryParse(str, *number)) {
		isNumber = true;
	}
	else System::Windows::Forms::MessageBox::Show("Число не указано или указано неверно", "Ошибка!");
	return isNumber;
}