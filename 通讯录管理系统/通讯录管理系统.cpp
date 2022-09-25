#include<iostream>
using namespace std;
#include<string>
#include "通讯录管理系统.h"
#define MAX 1000

//成员结构体
struct person
{
	string name;
	int sex;
	int age;
	string phone_number;
	string addr;
};

//地址簿结构体
struct addrbooks
{
	struct person peo[MAX];
	int size;
};

//添加
void addperson(addrbooks * abs)
{
	//判断是否满簿
	if (abs->size >= MAX)
	{
		cout << "同通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->peo[abs->size].name = name;

		//性别
		int sex = 0;
		while (true)
		{
			cout << "请输入性别：(1.男  2.女)" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->peo[abs->size].sex = sex;
				break;
			}
			else
				cout << "输入有误！请重新输入！" << endl;
		}

		//年龄
		int age = 0;
		while (true)
		{
			cout << "请输入年龄：" << endl;
			cin >> age;
			if (age >= 0 && age <= 120)
			{
				abs->peo[abs->size].age = age;
				break;
			}
			else
				cout << "年龄超出范围限制（不合理）！请重新输入！" << endl;
		}
		
		//电话
		string number;
		while (true)
		{
			cout << "请输入（11位）电话号码：" << endl;
			cin >> number;
			if (number.length() == 11)
			{
				abs->peo[abs->size].phone_number = number;
				break;
			}
			else
				cout << "号码不规范！请确认后重新输入！" << endl;
		}

		//住址
		string addr;
		cout << "请输入家庭住址" << endl;
		cin >> addr;
		abs->peo[abs->size].addr = addr;

		abs->size++;
		cout << "添加成功！";
		system("pause");
		system("cls");
	}
}

//显示
void showperson(addrbooks * abs)
{
	if (abs->size == 0 )
	{
		cout << "通讯录中记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名：" << abs->peo[i].name << "\t";
			cout << "性别：" << (abs->peo[i].sex == 1 ? "男": "女") << "\t";
			cout << "年龄：" << abs->peo[i].age << "\t";
			cout << "电话：" << abs->peo[i].phone_number << "\t";
			cout << "住址：" << abs->peo[i].addr << endl;
		}
		system("pause");
		system("cls");
	}
}

//检查存在
int isexist(addrbooks * abs , string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (name == abs->peo->name)
			return i;

	}
	return -1;
}

//删除
void deleteperson(addrbooks * abs,int a)
{	//数据前移
	for (int i = a; i < abs->size; i++)
	{
		abs->peo[i] = abs->peo[i + 1];
	}
	cout << "删除成功" << endl;
	abs->size--;
}

//查找
void findperson(addrbooks * abs)
{
	cout << "请输入想要查找的姓名：" << endl;
	string name;
	cin >> name;
	int ret;
	ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->peo[ret].name << "\t";
		cout << "性别：" << (abs->peo[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->peo[ret].age << "\t";
		cout << "电话：" << abs->peo[ret].phone_number << "\t";
		cout << "住址：" << abs->peo[ret].addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//修改
void editperson(addrbooks* abs)
{
	//判断是否空簿
	if (abs->size == 0)
	{
		cout << "同通讯录为空，无法修改" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "请输入想要修改人员的姓名：" << endl;
		string name;
		cin >> name;
		int ret;
		ret = isexist(abs, name);
		if (ret != -1)
		{
			//姓名
			string name;
			cout << "请输入姓名：" << endl;
			cin >> name;
			abs->peo[ret].name = name;


			//性别
			int sex = 0;
			while (true)
			{
				cout << "请输入性别：(1.男  2.女)" << endl;
				cin >> sex;
				if (sex == 1 || sex == 2)
				{
					abs->peo[ret].sex = sex;
					break;
				}
				else
					cout << "输入有误！请重新输入！" << endl;
			}

			//年龄
			int age = 0;
			while (true)
			{
				cout << "请输入年龄：" << endl;
				cin >> age;
				if (age >= 0 || age <= 120)
				{
					abs->peo[ret].age = age;
					break;
				}
				else
					cout << "年龄超出范围限制（不合理）！请重新输入！" << endl;
			}

			//电话
			string number;
			while (true)
			{
				cout << "请输入（11位）电话号码：" << endl;
				cin >> number;
				if (number.length() == 11)
				{
					abs->peo[ret].phone_number = number;
					break;
				}
				else
					cout << "号码不规范！请确认后重新输入！" << endl;
			}

			//住址
			string addr;
			cout << "请输入家庭住址" << endl;
			cin >> addr;
			abs->peo[ret].addr = addr;
			cout << "修改成功！";
		}
		else
		{
			cout << "查无此人" << endl;
		}
		system("pause");
		system("cls");
	};
}

//清空
void clearall(addrbooks* abs)
{
	abs->size = 0;
	cout << "清空完毕" << endl;
	system("pause");
	system("cls");
}

//显示菜单界面
void showmeun()
{
	cout << "***************************" << endl;
	cout << "*****  1. 添加联系人  *****"<< endl;
	cout << "*****  2. 显示联系人  *****" << endl;
	cout << "*****  3. 删除联系人  *****" << endl;
	cout << "*****  4. 查找联系人  *****" << endl;
	cout << "*****  5. 修改联系人  *****" << endl;
	cout << "*****  6. 清空联系人  *****" << endl;
	cout << "*****  0. 退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

int main() 
{	//实例化
	addrbooks abs;
	abs.size = 0;

	int select = 0;
	while(true)
	{ 
		showmeun();	
		cin >> select;
		switch (select)
		{
		case 1://添加
			addperson(&abs);
			break;
		case 2://显示
			showperson(&abs);
			break;
		case 3://删除
		{
			cout << "请输入联系人的姓名：" << endl;
			string name;
			cin >> name;
			int ret = isexist(&abs, name);
			if (ret != -1)
			{			
				deleteperson(&abs,ret);
			}
			else
			{
				cout << "查无此人" << endl;
			}
			system("pause");
			system("cls");

		}
			break;
		case 4://查找
			findperson(&abs);
			break;
		case 5://修改
			editperson(&abs);
			break;
		case 6://清空
			clearall(&abs);
			break;
		case 0://退出
			cout << "感谢使用！" << endl;
			return 0;
		default:
			cout << "选项输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}