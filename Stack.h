#ifndef StackH
#define StackH

struct Stack
{
	char data;
	Stack *next;
};

Stack *top;
Stack *InStack(Stack *, char);       //������ � ����
Stack *OutStack(Stack *, char *);    //���������� �� ����� (� ���������)

class OPZ
{
	public:
	int Priority (char);               //��������� �������� ��� ��������
	float Rezult(String, float*);             //������� �������� ���������
	void IntoOPZ(TEdit*, TEdit*);      //�������������� � ����������� �����
};

#endif






