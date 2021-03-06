// CPP1.cpp: 定义控制台应用程序的入口点。
//
/*
学校人员管理系统
    人员分为学生、教工。
	学生又分为本科生和研究生，研究生还分全日制和非全日制；
	学生有属性：
	姓名，性别，年龄，学生证号，成绩。
	研究生还有专业和工资（仅限全日制）
	教工分为教师和管理人员。
	教师有属性：
	姓名，性别，年龄，工号，专业，工资。
	管理人员有属性：
	姓名，性别，年龄，工号，岗位，工资。

*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main_menu();
int person_menu();

int main()
{
	int term = 1;
	List<person> list;
	while (term)
	{
		term = main_menu();
		switch (term)
		{
		case 1:list.print_all(); break;
		case 2:
		{
			int choice = 1;
			while (choice)
			{
				choice = person_menu();
				switch (choice)
				{
				case 1:
				{
					u_student * stu = new u_student;
					cout << "请按照如下格式依次输入本科生信息，用逗号分割：\n"
						<< "姓名，性别，学（工）号，年龄，成绩"
						<< endl;
					cin.ignore(1);
					*stu >> cin;
					list.insert(stu);
     			}
				break;
				case 2:
				{
					g_student_f * stu = new g_student_f;
					cout << "请按照如下格式依次输入研究生信息，用逗号分割：\n"
						<< "姓名，性别，学（工）号，年龄，工资，专业"
						<< endl;
					cin.ignore(1);
					*stu >> cin ;
					list.insert(stu);
				}
				break;
				case 3:
				{
					g_student_n * stu = new g_student_n;
					cout << "请按照如下格式依次输入研究生信息，用逗号分割：\n"
						<< "姓名，性别，学（工）号，年龄，专业"
						<< endl;
					cin.ignore(1);
					*stu >> cin;
					list.insert(stu);
				}
				break;
				case 4:
				{
					steward * sta = new steward;
					cout << "请按照如下格式依次输入管理人员信息，用逗号分割：\n"
						<< "姓名，性别，学（工）号，年龄，工资，岗位"
						<< endl;
					cin.ignore(1);
					*sta >> cin ;
					list.insert(sta);
				}
				break;
				case 5:
				{
					teacher * sta = new teacher;
					cout << "请按照如下格式依次输入教师信息，用逗号分割：\n"
						<< "姓名，性别，学（工）号，年龄，工资，专业"
						<< endl;
					cin.ignore(1);
					*sta >> cin;
					list.insert(sta);
				}
				break;
				default:
					break;
				}
			};
		}
		break;
		case 3:list.show(); break;
		case 4:list.show_length(); break;
		case 5:list.delete_data(); break;
		case 6:list.~List(); break;
		case 7:list.save2file(); break;
		default:
			break;
		}
	}
	//*/
	system("pause");
	return 0;
}

int main_menu()
{
	int ch;
	cout << "**********************************************************************" << endl;
	cout << "======================================================================" << endl;
	cout << "***************************学生成绩管理系统***************************" << endl; cout << endl;
	cout << "1.显示所有人员信息" << endl;
	cout << "2.添加人员信息" << endl;
	cout << "3.查询人员信息" << endl;
	cout << "4.查询当前储存信息条数" << endl;
	cout << "5.删除指定位置人员信息" << endl;
	cout << "6.删除所有信息" << endl;
	cout << "7.全部信息存入文件" << endl;
	cout << "0.退出系统" << endl; cout << endl;
	cout << "***********************************************************************" << endl;
	cout << "=======================================================================" << endl;
	cout << "***********************************************************************" << endl;
	cout << "执行操作：";
	cin >> ch;
	cout << "\n\n\n" << endl;
	return ch;
}

int person_menu()
{
	int ch;
	cout << "**********************************************************************" << endl;
	cout << "======================================================================" << endl;
	cout << "*************************选择输入哪类人员信息*************************" << endl; cout << endl;
	cout << "1.本科生" << endl;
	cout << "2.全日制研究生" << endl;
	cout << "3.非全日制研究生" << endl;
	cout << "4.管理人员" << endl;
	cout << "5.教师" << endl;
	cout << "0.返回上一级" << endl; cout << endl;
	cout << "***********************************************************************" << endl;
	cout << "=======================================================================" << endl;
	cout << "***********************************************************************" << endl;
	cin >> ch;
	cout << "\n\n\n" << endl;
	return ch;
}

