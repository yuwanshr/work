#include<iostream>
#include"boss.h"
#include<string>
using namespace std;

// ʵ��boss��Ĺ��캯��
Boss::Boss(int id, string name, int deptId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

//  ʵ��boss���showInfo()����
void Boss::showInfo() {
	cout << "���Ϊ��" << m_Id << "\t" << "����Ϊ��" << m_Name << "\t" << "����Ϊ��" << this->getDeptName() << "\t" << "��λְ��ţ���޵д��ܲ�" << endl;
}

// ʵ��boss���е�getDeptName����
string Boss::getDeptName() {
	return string("�ܲ�");

}