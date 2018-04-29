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
	int id;// ѧ��
	string name;// ����
	string tel;// �绰
};

struct Node {
	Student student;//��ǰѧ��ʵ��
	Node *next;// ָ����һ�ڵ��ָ��
};

// ��ʼ��ѧ����Ϣ
Node* init() {

	    Node* head = new Node();

		Node *p = head;
	
		Node *yangwen = new Node();
		Student *stu = new Student();
		stu->id = 178101;
		stu->name = "����";
		stu->tel = "13788041567";
		yangwen->student = *stu;

		head->next = yangwen;

		Node * zhangjiang = new Node();
		stu = new Student();
		stu->id = 178102;
		stu->name = "�Ž�";
		stu->tel = "13478920019";
		zhangjiang->student = *stu;

		yangwen->next = zhangjiang;



		Node * lihua = new Node();
		stu = new Student();
		stu->id = 178103;
		stu->name = "�";
		stu->tel = "15077402345";
		lihua->student = *stu;

		zhangjiang->next = lihua;



	

		Node * huangli = new Node();
		stu = new Student();
		stu->id = 178104;
		stu->name = "����";
		stu->tel = "15867748903";
		huangli->student = *stu;

		lihua->next = huangli;

		
		Node * liuning = new Node();
		stu = new Student();
		stu->id = 178105;
		stu->name = "����";
		stu->tel = "18977410656";
		liuning->student = *stu;

		huangli->next = liuning;

		return p;

}


void showStudents(Node *head) {

	head = head->next;

	cout << "========================== Ĭ��ѧ����Ϣ =====================" << endl << endl;

	while (head!=0)
	{
		if (!head->student.name.empty()) {
			cout << "ѧ�ţ�" << head->student.id << "\t������" << head->student.name << "\t�绰��" << head->student.tel << endl;
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
			cout << "\n\n����ҵ�ѧ����Ϣ��     ѧ�ţ�" << head->student.id << "\t������" << head->student.name << "\t�绰��" << head->student.tel << endl << endl;
			found = true;
		}

		head = head->next;
	}

	if (!found) {
		cout << "\n\nδ�ҵ�����Ϊ "<<name<<" ��ѧ��\n\n";
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
		cout << "\n\nλ�� " <<p<<" ������"<< endl;
		return;
	}

	Student *stu = new Student();
	cout << "������ѧ��ѧ��:";
	cin >> stu->id;

	cout << "������ѧ������:";
	cin >> stu->name;

	cout << "������ѧ���绰:";
	cin >> stu->tel;



	Node * theNew = new Node();
	theNew->student = *stu;
	theNew->next = head->next;

	head->next = theNew;

	cout << "\n\n����ɹ�\n\n";
}

void deleteStu(Node * head, int p) {

	
	int current = 1;

	while (head != 0 && head->next != 0 && current<p)
	{
		current++;
		head = head->next;
	}

	if (current < p) {
		cout << "\n\nλ�� " << p << " ������" << endl;
		return;
	}

	head->next = head->next->next;

	cout << "\n\nɾ���ɹ�\n\n";
}

void showMenu() {

	cout << "=========== �˵� ============" << endl << endl;
	cout << "1. ��ʾ����ѧ����Ϣ" << endl << endl;
	cout << "2. ����������" << endl << endl;
	cout << "3. ����ѧϰ��Ϣ" << endl << endl;
	cout << "4. ɾ��ѧϰ��Ϣ" << endl << endl;
	cout << "5. �˳�" << endl << endl;
	cout << "=============================" << endl << endl;
	cout << "��ѡ��";
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
			cout << "������ѧ������:";
			cin >> name;

			system("cls");

			find(p,name);
			break;

		case 3:

			system("cls");

			cout << "���������λ��:";

			cin >> position;		

			insert(p,position);
			break;

		case 4:
			cout << "������ɾ����λ��:";
			cin >> position;
			deleteStu(p, position);

		default:
			break;
		}		

	} while (select != 5);
	

    return 0;
}

