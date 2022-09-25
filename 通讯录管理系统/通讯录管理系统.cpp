#include<iostream>
using namespace std;
#include<string>
#include "ͨѶ¼����ϵͳ.h"
#define MAX 1000

//��Ա�ṹ��
struct person
{
	string name;
	int sex;
	int age;
	string phone_number;
	string addr;
};

//��ַ���ṹ��
struct addrbooks
{
	struct person peo[MAX];
	int size;
};

//���
void addperson(addrbooks * abs)
{
	//�ж��Ƿ�����
	if (abs->size >= MAX)
	{
		cout << "ͬͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->peo[abs->size].name = name;

		//�Ա�
		int sex = 0;
		while (true)
		{
			cout << "�������Ա�(1.��  2.Ů)" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->peo[abs->size].sex = sex;
				break;
			}
			else
				cout << "�����������������룡" << endl;
		}

		//����
		int age = 0;
		while (true)
		{
			cout << "���������䣺" << endl;
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->peo[abs->size].age = age;
				break;
			}
			else
				cout << "���䳬����Χ���ƣ������������������룡" << endl;
		}
		
		//�绰
		string number;
		while (true)
		{
			cout << "�����루11λ���绰���룺" << endl;
			cin >> number;
			if (number.length() == 11)
			{
				abs->peo[abs->size].phone_number = number;
				break;
			}
			else
				cout << "���벻�淶����ȷ�Ϻ��������룡" << endl;
		}

		//סַ
		string addr;
		cout << "�������ͥסַ" << endl;
		cin >> addr;
		abs->peo[abs->size].addr = addr;

		abs->size++;
		cout << "��ӳɹ���";
		system("pause");
		system("cls");
	}
}

//��ʾ
void showperson(addrbooks * abs)
{
	if (abs->size == 0 )
	{
		cout << "ͨѶ¼�м�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "������" << abs->peo[i].name << "\t";
			cout << "�Ա�" << (abs->peo[i].sex == 1 ? "��": "Ů") << "\t";
			cout << "���䣺" << abs->peo[i].age << "\t";
			cout << "�绰��" << abs->peo[i].phone_number << "\t";
			cout << "סַ��" << abs->peo[i].addr << endl;
		}
		system("pause");
		system("cls");
	}
}

//������
int isexist(addrbooks * abs , string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (name == abs->peo->name)
			return i;

	}
	return -1;
}

//ɾ��
void deleteperson(addrbooks * abs,int a)
{	//����ǰ��
	for (int i = a; i < abs->size; i++)
	{
		abs->peo[i] = abs->peo[i + 1];
	}
	cout << "ɾ���ɹ�" << endl;
	abs->size--;
}

//����
void findperson(addrbooks * abs)
{
	cout << "��������Ҫ���ҵ�������" << endl;
	string name;
	cin >> name;
	int ret;
	ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->peo[ret].name << "\t";
		cout << "�Ա�" << (abs->peo[ret].sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->peo[ret].age << "\t";
		cout << "�绰��" << abs->peo[ret].phone_number << "\t";
		cout << "סַ��" << abs->peo[ret].addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//�޸�
void editperson(addrbooks* abs)
{
	//�ж��Ƿ�ղ�
	if (abs->size == 0)
	{
		cout << "ͬͨѶ¼Ϊ�գ��޷��޸�" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "��������Ҫ�޸���Ա��������" << endl;
		string name;
		cin >> name;
		int ret;
		ret = isexist(abs, name);
		if (ret != -1)
		{
			//����
			string name;
			cout << "������������" << endl;
			cin >> name;
			abs->peo[ret].name = name;


			//�Ա�
			int sex = 0;
			while (true)
			{
				cout << "�������Ա�(1.��  2.Ů)" << endl;
				cin >> sex;
				if (sex == 1 || sex == 2)
				{
					abs->peo[ret].sex = sex;
					break;
				}
				else
					cout << "�����������������룡" << endl;
			}

			//����
			int age = 0;
			while (true)
			{
				cout << "���������䣺" << endl;
				cin >> age;
				if (age >= 0 || age <= 120)
				{
					abs->peo[ret].age = age;
					break;
				}
				else
					cout << "���䳬����Χ���ƣ������������������룡" << endl;
			}

			//�绰
			string number;
			while (true)
			{
				cout << "�����루11λ���绰���룺" << endl;
				cin >> number;
				if (number.length() == 11)
				{
					abs->peo[ret].phone_number = number;
					break;
				}
				else
					cout << "���벻�淶����ȷ�Ϻ��������룡" << endl;
			}

			//סַ
			string addr;
			cout << "�������ͥסַ" << endl;
			cin >> addr;
			abs->peo[ret].addr = addr;
			cout << "�޸ĳɹ���";
		}
		else
		{
			cout << "���޴���" << endl;
		}
		system("pause");
		system("cls");
	};
}

//���
void clearall(addrbooks* abs)
{
	abs->size = 0;
	cout << "������" << endl;
	system("pause");
	system("cls");
}

//��ʾ�˵�����
void showmeun()
{
	cout << "***************************" << endl;
	cout << "*****  1. �����ϵ��  *****"<< endl;
	cout << "*****  2. ��ʾ��ϵ��  *****" << endl;
	cout << "*****  3. ɾ����ϵ��  *****" << endl;
	cout << "*****  4. ������ϵ��  *****" << endl;
	cout << "*****  5. �޸���ϵ��  *****" << endl;
	cout << "*****  6. �����ϵ��  *****" << endl;
	cout << "*****  0. �˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

int main() 
{	//ʵ����
	addrbooks abs;
	abs.size = 0;

	int select = 0;
	while(true)
	{ 
		showmeun();	
		cin >> select;
		switch (select)
		{
		case 1://���
			addperson(&abs);
			break;
		case 2://��ʾ
			showperson(&abs);
			break;
		case 3://ɾ��
		{
			cout << "��������ϵ�˵�������" << endl;
			string name;
			cin >> name;
			int ret = isexist(&abs, name);
			if (ret != -1)
			{			
				deleteperson(&abs,ret);
			}
			else
			{
				cout << "���޴���" << endl;
			}
			system("pause");
			system("cls");

		}
			break;
		case 4://����
			findperson(&abs);
			break;
		case 5://�޸�
			editperson(&abs);
			break;
		case 6://���
			clearall(&abs);
			break;
		case 0://�˳�
			cout << "��лʹ�ã�" << endl;
			return 0;
		default:
			cout << "ѡ�������������������룡" << endl;
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}