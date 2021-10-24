#include "MyForm.h"
#include "Header.hpp"

//Удаление начальных массивов перед закрытием формы
System::Void Matrix::MyForm::MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	System::Windows::Forms::DialogResult result;
	result = MessageBox::Show("Вы действительно хотите выйти?", "Закрытие окна", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
	if (result == System::Windows::Forms::DialogResult::Yes) {
		DeleteArray(A, rowCountA, columnCountA);
		DeleteArray(B, rowCountB, columnCountB);
		return;
	}
	else e->Cancel = true;
}