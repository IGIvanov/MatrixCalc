#include "MyForm.h"
#include "Header.hpp"

//������� ���������� ���������� �������� � ����� � ������� A
System::Void Matrix::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView1);
	if (CheckTextBox(textBox1, &rowCountA) && CheckTextBox(textBox2, &columnCountA)) {
		if (rowCountA != 0 && columnCountA != 0) {
			AddColumnRow(dataGridView1, &rowCountA, &columnCountA);
		}
		else System::Windows::Forms::MessageBox::Show(
			"���������� ����� ��� �������� �� ����� ���� �������", "������!");
	}
}

//������� ���������� ���������� �������� � ����� � ������� B
System::Void Matrix::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView2);
	if (CheckTextBox(textBox3, &rowCountB) && CheckTextBox(textBox4, &columnCountB)) {
		if (rowCountB != 0 && columnCountB != 0) {
			AddColumnRow(dataGridView2, &rowCountB, &columnCountB);
		}
		else System::Windows::Forms::MessageBox::Show(
			"���������� ����� ��� �������� �� ����� ���� �������", "������!");
	}
}

//�������� ����� � �������� �� ������� �
System::Void Matrix::MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView1);
	textBox1->Text = L"";
	textBox2->Text = L"";
	rowCountA = 0;
	columnCountA = 0;
}

//�������� ����� � �������� �� ������� B
System::Void Matrix::MyForm::button6_Click(System::Object^ sender, System::EventArgs^ e) {
	DeleteColumnRow(dataGridView2);
	textBox3->Text = L"";
	textBox4->Text = L"";
	rowCountB = 0;
	columnCountB = 0;
}

