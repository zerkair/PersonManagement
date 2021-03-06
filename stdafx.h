// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

class person
{
protected:
	string name;
	string sex;
	string IDnumber;
	unsigned int age;
public:
	person() {}
	person(string nname, string nsex,
		string nIDnumber, unsigned int nage)
	{
		name = nname;
		sex = nsex;
		age = nage;
		IDnumber = nIDnumber;
	}
	person(const person &p)
	{
		name = p.name;
		sex = p.sex;
		age = p.age;
		IDnumber = p.IDnumber;
	}
	
	virtual ofstream & operator<<(ofstream & ofs)
	{
		ofs << this->name << ',' << this->sex << ',' << this->IDnumber << ','
			<< this->age << endl;
		return ofs;
	}
	
	/*
	定义输入方法，用逗号分隔各个对象属性
	输入顺序规定为：姓名，性别，学（工）号，年龄
	*/
	virtual istream & operator>>(istream & ist)
	{
		getline(ist, this->name, ',');
		getline(ist, this->sex, ',');
		getline(ist, this->IDnumber, ',');
		ist >> this->age;
		return ist;
	}
	virtual void print_info()
	{
		cout << setw(5) << "Name:" << setw(10) << name
			<< setw(5) << "Sex:" << setw(8) << sex
			<< setw(5) << "ID:" << setw(8) << IDnumber
			<< setw(5) << "Age:" << setw(5) << age
			<< endl;
	}
};

//定义本科生类
class u_student :public person
{
private:
	unsigned int score = 60;
public:
	u_student() {}
	u_student(string nname,string nsex,
		string nIDnumber, unsigned int nage,
		unsigned int nscore) :
		person(nname, nsex, nIDnumber, nage), score(nscore) {}
	u_student(const u_student & stu)
	{
		name = stu.name;
		sex = stu.sex;
		age = stu.age;
		IDnumber = stu.IDnumber;
		score = stu.score;
	}
	//定义输出文件方法，输出到csv文件
	ofstream & operator<<(ofstream & ofs)
	{
		ofs << this->name << ',' << this->sex << ',' << this->IDnumber << ','
			<< this->age << ',' << this->score << endl;
		return ofs;
	}
	/*
	定义输入方法，用逗号分隔各个对象属性
	输入顺序规定为：姓名，性别，学（工）号，年龄，成绩
	*/
	istream & operator>>(istream & ist)
	{
		getline(ist, this->name, ',');
		getline(ist, this->sex, ',');
		getline(ist, this->IDnumber, ',');
		ist >> this->age;
		if (ist.get() == ',')
			ist >> this->score;
		return ist;
	}
	//设置成绩
	void reset_score(int newscore)
	{
		if (newscore < 0 || newscore>100)
			cout << "错误的成绩值" << endl;
		else
			score = newscore;
	}
	//打印基本信息
	void print_info()
	{
		cout << setw(5) << "Name:" << setw(10) << name
			<< setw(5) << "Sex:" << setw(8) << sex
			<< setw(5) << "ID:" << setw(8) << IDnumber
			<< setw(5) << "Age:" << setw(3) << age
			<< setw(8) << "Score:" << setw(5) << score
			<< endl;
	}
	~u_student() {}

};

//全日制研究生类
class g_student_f : public person
{
private:
	int salary;
	string pro;
public:
	g_student_f() {}
	g_student_f(string nname, string nsex,
		string nIDnumber, unsigned int nage,
		int nsalary, string npro) :
		person(nname, nsex, nIDnumber, nage),
		salary(nsalary), pro(npro) {}
	g_student_f(const g_student_f & stu)
	{
		name = stu.name;
		sex = stu.sex;
		IDnumber = stu.IDnumber;
		age = stu.age;
		salary = stu.salary;
		pro = stu.pro;
	}
	//定义输出文件方法，输出到csv文件
	ofstream & operator<<(ofstream & ofs)
	{
		ofs << this->name << ',' << this->sex << ',' << this->IDnumber << ','
			<< this->age << ',' << this->salary << ',' << this->pro << endl;
		return ofs;
	}
	/*
	定义输入方法，用逗号分隔各个对象属性
	输入顺序规定为：姓名，性别，学（工）号，年龄，
	全日制标识，工资，专业
	*/
	istream & operator>>(istream & ist)
	{
		getline(ist, this->name, ',');
		getline(ist, this->sex, ',');
		getline(ist, this->IDnumber, ',');
		ist >> this->age;
		if (ist.get() == ',')
			ist >> this->salary;
		if (ist.get() == ',')
			getline(ist, this->pro);
		return ist;
	}
	//打印基本信息
	void print_info()
	{
		cout << setw(5) << "Name:" << setw(10) << name
			<< setw(5) << "Sex:" << setw(8) << sex
			<< setw(5) << "ID:" << setw(8) << IDnumber
			<< setw(5) << "Age:" << setw(3) << age
			<< setw(8) << "Salary:" << setw(5) << salary
			<< setw(5) << "Pro:" << setw(10) << pro
			<< endl;
	}
	~g_student_f() {}
};

//非全日制研究生类
class g_student_n : public person
{
private:
	string pro;

public:
	g_student_n() {}
	g_student_n(string nname, string nsex,
		string nIDnumber, unsigned int nage,
		string npro) :person(nname, nsex, nIDnumber, nage), pro(npro) {}
	g_student_n(const g_student_n & stu)
	{
		name = stu.name;
		sex = stu.sex;
		IDnumber = stu.IDnumber;
		age = stu.age;
		pro = stu.pro;
	}
	//定义输出文件方法，输出到csv文件
	ofstream & operator<<(ofstream & ofs)
	{
		ofs << this->name << ',' << this->sex << ',' << this->IDnumber << ','
			<< this->age << ',' << this->pro << endl;
		return ofs;
	}
	/*
	定义输入方法，用逗号分隔各个对象属性
	输入顺序规定为：姓名，性别，学（工）号，年龄，
	全日制标识，工资，专业
	*/
	istream & operator>>(istream & ist)
	{
		getline(ist, this->name, ',');
		getline(ist, this->sex, ',');
		getline(ist, this->IDnumber, ',');
		ist >> this->age;
		if (ist.get() == ',')
			getline(ist, this->pro);
		return ist;
	}
	//打印基本信息
	void print_info()
	{
		cout << setw(5) << "Name:" << setw(10) << name
			<< setw(5) << "Sex:" << setw(8) << sex
			<< setw(5) << "ID:" << setw(8) << IDnumber
			<< setw(5) << "Age:" << setw(3) << age
			<< setw(5) << "Pro:" << setw(10) << pro
			<< endl;
	}
	~g_student_n() {}
};

//定义职工类
class staff :public person
{
protected:
	int salary;
public:
	staff() {}
	staff(string nname, string nsex, string nIDnumber,
		unsigned int nage, int nsalary) :
		person(nname, nsex, nIDnumber, nage)
	{
		salary = nsalary;
	}
	staff(const staff & sta)
	{
		name = sta.name;
		sex = sta.sex;
		IDnumber = sta.IDnumber;
		age = sta.age;
		salary = sta.salary;
	}
	//定义输出文件方法，输出到csv文件
	virtual ofstream & operator<<(ofstream & ofs)
	{
		ofs << this->name << ',' << this->sex << ',' << this->IDnumber << ','
			<< this->age << ',' << this->salary << endl;
		return ofs;
	}
	//打印基本信息
	virtual void print_info()
	{
		cout << setw(5) << "Name:" << setw(10) << name
			<< setw(5) << "Sex:" << setw(8) << sex
			<< setw(5) << "ID:" << setw(8) << IDnumber
			<< setw(5) << "Age:" << setw(3) << age
			<< setw(8) << "Salary:" << setw(5) << salary
			<< endl;
	}
	~staff() {}
};

//定义管理人员类
class steward :public staff
{
private:
	string position;
public:
	steward() {}
	steward(string nname, string nsex, string nIDnumber, unsigned int nage,
		int nsalary, string nposition) :
		staff(nname, nsex, nIDnumber, nage, nsalary)
	{
		position = nposition;
	}
	steward(const steward & sta)
	{
		name = sta.name;
		sex = sta.sex;
		IDnumber = sta.IDnumber;
		age = sta.age;
		salary = sta.salary;
		position = sta.position;
	}
	//定义输出文件方法，输出到csv文件
	ofstream & operator<<(ofstream & ofs)
	{
		ofs << this->name << ',' << this->sex << ',' << this->IDnumber << ','
			<< this->age << ',' << this->salary << ','
			<< this->position << endl;
		return ofs;
	}
	/*
	定义输入方法，用逗号分隔各个对象属性
	输入顺序规定为：姓名，性别，学（工）号，年龄，工资，岗位
	*/
	istream & operator>>(istream & ist)
	{
		getline(ist, this->name, ',');
		getline(ist, this->sex, ',');
		getline(ist, this->IDnumber, ',');
		ist >> this->age;
		if (ist.get() == ',')
			ist >> this->salary;
		if (ist.get() == ',')
			getline(ist, this->position);
		return ist;
	}
	void print_info()
	{
		cout << setw(5) << "Name:" << setw(10) << name
			<< setw(5) << "Sex:" << setw(8) << sex
			<< setw(5) << "ID:" << setw(8) << IDnumber
			<< setw(5) << "Age:" << setw(3) << age
			<< setw(8) << "Salary:" << setw(5) << salary
			<< setw(10) << "Position:" << setw(12) << position
			<< endl;
	}
	~steward() {}
};

//定义教师类
class teacher :public staff
{
private:
	string profession;
public:
	teacher() {}
	teacher(string nname, string nsex, string nIDnumber,
		unsigned int nage, int nsalary, string nprofession) :
		staff(nname, nsex, nIDnumber, nage, nsalary)
	{
		profession = nprofession;
	}
	teacher(const teacher & sta)
	{
		name = sta.name;
		sex = sta.sex;
		IDnumber = sta.IDnumber;
		age = sta.age;
		salary = sta.salary;
		profession = sta.profession;
	}
	//定义输出文件方法，输出到csv文件
	ofstream & operator<<(ofstream & ofs)
	{
		ofs << this->name << ',' << this->sex << ',' << this->IDnumber << ','
			<< this->age << ',' << this->salary << ','
			<< this->profession << endl;
		return ofs;
	}
	/*
	定义输入方法，用逗号分隔各个对象属性
	输入顺序规定为：姓名，性别，学（工）号，年龄，工资，专业
	*/
	istream & operator>>(istream & ist)
	{
		getline(ist, this->name, ',');
		getline(ist, this->sex, ',');
		getline(ist, this->IDnumber, ',');
		ist >> this->age;
		if (ist.get() == ',')
			ist >> this->salary;
		if (ist.get() == ',')
			getline(ist, this->profession);
		return ist;
	}
	void print_info()
	{
		cout << setw(5) << "Name:" << setw(10) << name
			<< setw(5) << "Sex:" << setw(8) << sex
			<< setw(5) << "ID:" << setw(8) << IDnumber
			<< setw(5) << "Age:" << setw(3) << age
			<< setw(8) << "Salary:" << setw(5) << salary
			<< setw(10) << "Pro:" << setw(12) << profession
			<< endl;
	}
	~teacher() {}
};

template<class T> class List;

//定义结点类
template<class T> class Node
{
private:
	Node<T> * last;
	T * data;
	Node<T> * next;
public:
	Node() :last(NULL), data(NULL), next(NULL)
	{}
	Node(T * n_data) :last(NULL), data(n_data), next(NULL)
	{}
	void print()
	{
		data->print_info();
	}
	friend class List<T>;
};

//定义链表
template<class T> class List
{
private:
	int length;
	Node<T> * head;
	Node<T> * tail;
public:
	//创建一个空元素节点 
	List() :length(0)
	{
		head = tail = NULL;
	}
	friend class message;
	//将元素从链表表尾插入
	void insert(T * ndata)
	{
		Node<T>* temp = new Node<T>(ndata);
		if (length != 0)
		{
			temp->next = NULL;
			temp->last = tail;
			tail->next = temp;
			tail = temp;
			length++;
		}
		else
		{
			head = tail = temp;
			length++;
		}
	}
	//找到第k个数据，以打印的方式表示
	void show()
	{
		if (length == 0)
		{
			cout << "没有数据可以显示！" << endl;
		}
		else
		{
			int k = 0;
			cout << "请输入显示信息的序号:";
			cin >> k;
			Node<T> * position = head;
			for (int i = 1; i < k; i++)
			{
				position = position->next;
			}
			position->data->print_info();
		}
	}

	void delete_data()
	{
		if (length == 0)
		{
			cout << "Error:没有任何数据!" << endl;
		}
		else
		{
			int k = 0;
			cout << "请输入删除信息的序号:";
			cin >> k;
			if (k <0 || k>length)
				cout << "错误的序号数" << endl;
			else
			{
				Node<T> * position = head;
				if (k == length)
				{
					position = tail;
					tail = tail->last;
					tail->next = NULL;
					delete position;
					length--;
				}
				else
				{
					if (k == 1)
					{
						position = head;
						head = head->next;
						head->last = NULL;
						delete position;
						length--;
					}
					else
					{
						for (int i = 1; i < k; i++)
						{
							position = position->next;
						}
						position->last->next = position->next;
						position->next->last = position->last;
						delete position;
						length--;
					}
				}

			}
		}
		
	}
	void print_all()
	{
		if (length == 0)
			cout << "当前没有数据！" << endl;
		else
		{
			Node<T> * temp;
			for (temp = head; temp; temp = temp->next)
			{
				temp->data->print_info();
			}
		}
	}
	void save2file()
	{
		if (length == 0)
		{
			cout << "没有数据可以保存！" << endl;
		}
		else
		{
			string filepath;
			filepath = "E:\\TemporaryData\\C++Test\\data.csv";
			ofstream outFile;
			outFile.open(filepath, ios::out);
			Node<T> * p = head;
			while (p != NULL)
			{
				*p->data << outFile;
				p = p->next;
			}
			outFile.close();
		}
	}
	void delete_all()
	{
		{
			Node<T> * q;
			Node<T> * p = head;
			while (p != NULL)
			{
				q = p;
				p = p->next;
				delete q;
			}
			p = NULL;
			q = NULL;
			List();
		}
	}
	void show_length()
	{
		cout << "现有" << length << "条数据！" << endl;
	}
	~List()
	{
		Node<T> * q;
		Node<T> * p = head;
		while (p != NULL)
		{
			q = p;
			p = p->next;
			delete q;
		}
		p = NULL;
		q = NULL;
		length = 0;
	}
};


// TODO: 在此处引用程序需要的其他头文件
