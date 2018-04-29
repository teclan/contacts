#include "stdafx.h"
#include"stdio.h"
#include<string>
#include<iostream>
#define error 0;
#define ok 1;
#define LIST_INIT_SIZE 10;
#define LIST_INCREMENT 5;
typedef int status;
using namespace std;


class  Student {

public :
	int id;// 学号
	string name;// 名字
	string tel;// 电话
};

struct Node {
	Student student;//当前学生实体
	Node *next;// 指向下一节点的指针
};

// 初始化学生信息
Node* init() {

	    Node* head = new Node();

		Node *p = head;
	
		Node *yangwen = new Node();
		Student *stu = new Student();
		stu->id = 178101;
		stu->name = "杨文";
		stu->tel = "13788041567";
		yangwen->student = *stu;

		head->next = yangwen;

		Node * zhangjiang = new Node();
		stu = new Student();
		stu->id = 178102;
		stu->name = "张江";
		stu->tel = "13478920019";
		zhangjiang->student = *stu;

		yangwen->next = zhangjiang;



		Node * lihua = new Node();
		stu = new Student();
		stu->id = 178103;
		stu->name = "李华";
		stu->tel = "15077402345";
		lihua->student = *stu;

		zhangjiang->next = lihua;



	

		Node * huangli = new Node();
		stu = new Student();
		stu->id = 178104;
		stu->name = "黄丽";
		stu->tel = "15867748903";
		huangli->student = *stu;

		lihua->next = huangli;

		
		Node * liuning = new Node();
		stu = new Student();
		stu->id = 178105;
		stu->name = "刘宁";
		stu->tel = "18977410656";
		liuning->student = *stu;

		huangli->next = liuning;

		return p;

}


void showStudents(Node *head) {

	head = head->next;

	cout << "========================== 默认学生信息 =====================" << endl << endl;

	while (head!=0)
	{
		if (!head->student.name.empty()) {
			cout << "学号：" << head->student.id << "\t姓名：" << head->student.name << "\t电话：" << head->student.tel << endl;
		}

		head = head->next;

	}
	
	cout << "\n============================================================" << endl << endl;
}


void find(Node *head,string name) {
	head = head->next;
	bool found = false;

	while (head!=0)
	{

		if (head->student.name==name) {
			cout << "\n\n你查找的学生信息：     学号：" << head->student.id << "\t姓名：" << head->student.name << "\t电话：" << head->student.tel << endl << endl;
			found = true;
		}

		head = head->next;
	}

	if (!found) {
		cout << "\n\n未找到姓名为 "<<name<<" 的学生\n\n";
	}
}


void insert(Node *head, int p) {

	int current = 1;
	
	while (head!=0 &&head->next!=0&& current<p)
	{
		current++;
		head = head->next;
	}

	if (current < p) {
		cout << "\n\n位置 " <<p<<" 不存在"<< endl;
		return;
	}

	Student *stu = new Student();
	cout << "请输入学生学号:";
	cin >> stu->id;

	cout << "请输入学生姓名:";
	cin >> stu->name;

	cout << "请输入学生电话:";
	cin >> stu->tel;



	Node * theNew = new Node();
	theNew->student = *stu;
	theNew->next = head->next;

	head->next = theNew;

	cout << "\n\n插入成功\n\n";
}

void deleteStu(Node * head, int p) {

	
	int current = 1;

	while (head != 0 && head->next != 0 && current<p)
	{
		current++;
		head = head->next;
	}

	if (current < p) {
		cout << "\n\n位置 " << p << " 不存在" << endl;
		return;
	}

	head->next = head->next->next;

	cout << "\n\n删除成功\n\n";
}

void showMenu() {

	cout << "=========== 菜单 ============" << endl << endl;
	cout << "1. 显示所有学生信息" << endl << endl;
	cout << "2. 按姓名查找" << endl << endl;
	cout << "3. 插入学习信息" << endl << endl;
	cout << "4. 删除学习信息" << endl << endl;
	cout << "5. 退出" << endl << endl;
	cout << "=============================" << endl << endl;
	cout << "请选择：";
}

int main()
{
	
	Node *head = init();

	int select=-1;
	string name;
	int position;

	do {
			

		Node * p = head;		

		showMenu();
		cin >> select;


		switch (select)
		{

		case 1:
			showStudents(p);
			break;

		case 2:
			cout << "请输入学生姓名:";
			cin >> name;

			system("cls");

			find(p,name);
			break;

		case 3:

			system("cls");

			cout << "请输入插入位置:";

			cin >> position;		

			insert(p,position);
			break;

		case 4:
			cout << "请输入删除的位置:";
			cin >> position;
			deleteStu(p, position);

		default:
			break;
		}		

	} while (select != 5);
	

    return 0;
}

