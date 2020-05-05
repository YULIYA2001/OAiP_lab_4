#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Stack.h"
#include "Math.hpp"

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

//��� �������� �����
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Edit1->Text = "(a+b)*(c-d)/e";
	char symbols = 'a';
    //���������� ������� ��������
	StringGrid1->Cells[0][0] = "��� ����������";
	StringGrid1->Cells[1][0] = "��������";
	for (int i = 1; i < 6; i++)
	{
		StringGrid1->Cells[0][i] = symbols++;
	}
	StringGrid1->Cells[1][1] = 0.8;
	StringGrid1->Cells[1][2] = 4.1;
	StringGrid1->Cells[1][3] = 7.9;
	StringGrid1->Cells[1][4] = 6.2;
	StringGrid1->Cells[1][5] = 3.5;
}

OPZ *opz;     //������ ������ OPZ
//������ "���������"
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	opz->IntoOPZ(Edit1, Edit2);
}

//������ "���������"
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if (Edit2->Text == "")
		ShowMessage("������� ������� ������ \"���������\"");
	else
	{
		char variable;
		//����� ������ �������� ���������� (��������� �������� �� �������)
		float array[201];
		for (int i = 1; i < 6; i++)
		{
			variable = StringGrid1->Cells[0][i][1]; //��� ���������� �� �������
			//�������� ���������� �� ������� �������� � ������
			array[int(variable)] = StrToFloat(StringGrid1->Cells[1][i]);
		}
		//����� � Edit3 �������� �� ����������� ����� (���������� �� 2 ������)
		Edit3->Text = FloatToStrF(opz->Rezult(Edit2->Text, array), ffFixed,7,2);
		float rez;
		if (Edit1->Text == "(a+b)*(c-d)/e")
		{
	//�������� �������� �� ��������� ����� � ����� � Edit4 (���������� �� 2 ������)
			rez=(array[int('a')] + array[int('b')]) * (array[int('c')] -
			array[int('d')]) / array[int('e')];
			Edit4->Text = FloatToStrF(rez, ffFixed,7,2);
		}
		else  Edit4->Text = "";
	}
}

