#pragma hdrstop

#include "Stack.h"

Stack* InStack(Stack *top, char data)
{
	Stack *item = new Stack;
	item->data = data;
	item->next = top;
	return item;
}

Stack* OutStack(Stack *top, char *data)
{
	Stack *item = top;
	*data = top->data;
	top = top->next;
	delete item;
	return top;
}


int OPZ :: Priority (char symbol)
{
	switch(symbol)
	{
		case '*':
		case '/': return 3;
		case '+':
		case '-': return 2;
		case '(': return 1;
	}
	return 0;
}

void OPZ :: IntoOPZ(TEdit *Edit1, TEdit *Edit2)
{
	top = NULL;
	String inputStr, outputStr;  //������ � ��������� � ����������� �������
	outputStr = "";
	char inSymb, outSymb;   //������� ������ � ��������� � ����������� �������
	inputStr = Edit1->Text;
	int length = inputStr.Length();
	for (int i = 1; i <= length; i++)
	{
		inSymb = inputStr[i];
		if (inSymb == '(')                //���� ������ ������� ������ (
			top = InStack(top, inSymb);   //�������� ��� � ����
		if (inSymb == ')')                //���� ������ ������� ������ )
		{
			while (top->data != '(')      //���� � ����� �� ����� �� (
			{
				top = OutStack(top, &outSymb);  //��������� ������� �� �����
				outputStr += outSymb;           //� ���������� �� � �������� ������
			}
			top = OutStack(top, &outSymb);      //������� �� ����� ( � ������
		}
		if (inSymb >= 'a' && inSymb <= 'z')    //���� ������ ������� ������ �����
			outputStr += inSymb;               //�������� ��� � �������� ������
		//���� ������ - ���� ��������
		if (inSymb =='*' || inSymb =='/' || inSymb =='+' || inSymb =='-')
		{
			while (top != NULL && Priority(top->data) >= Priority(inSymb))
			{
				top = OutStack(top, &outSymb);  //������� ��������� ������ �����
				outputStr += outSymb;           //� �������� ������
			}
			top = InStack(top, inSymb);         //� ���� �������� ������� ������
		}
	}
	while (top != NULL)			//����� ������� ����������� ���������
	{                           // � �������� ������ ���, ��� ��������
		top = OutStack(top, &outSymb);
		outputStr += outSymb;
	}
	Edit2->Text = outputStr;
}

float OPZ :: Rezult(String outputStr, float *array)
{
	char variable, variable1, variable2;   //��� ���� ����������
	//��� �������� ���������� � ���������� �������� ��� ����
	double value1, value2, rez;
	char valueRez = 'z' + 1;   //��� "����� ����������" ����� ���������� ��������
	for (int i = 1; i <= outputStr.Length(); i++)
	{
		variable = outputStr[i];
		if (variable !='*' && variable !='/' && variable !='+' && variable !='-')
			top = InStack(top, variable);     //���������� � ���� ������ ����������
		else
		{                                     //���� ������ - ����
			top = OutStack(top, &variable1);  //����� 2 ���������� �� �����
			top = OutStack(top, &variable2);
			value1 = array[int(variable1)];   //����� �� �������� � �������
			value2 = array[int(variable2)];
			switch(variable)
			{
				case '+': rez = value2 + value1; break;
				case '-': rez = value2 - value1; break;
				case '*': rez = value2 * value1; break;
				case '/': rez = value2 / value1; break;
			}
			//������ ���������� �������� � ����� ������ �������� ����������
			array[int(valueRez)] = rez;
			//������ "����� ����������"(��������� �������� ��� �������) � ����
			top = InStack(top, valueRez);
			//����� ��� ������ � ����� ������ �� ��������� ������ ����������
			valueRez++;
		}
	}
	return rez;
}

#pragma package(smart_init)
