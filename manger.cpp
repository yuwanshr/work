#include<iostream>
#include"manger.h"
#include<string>

// ʵ��manger���еĹ��캯����
Manger::Manger(int id, string name, int deptId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

// ʵ��manger���showInfo()����
void Manger::showInfo() {
	cout << "���Ϊ��" << m_Id << "\t" << "����Ϊ��" << m_Name<<"\t" << "����Ϊ��" << this->getDeptName()<<"\t" << "��λְ��ƽƽ����С����" << endl;

}

// ʵ��manger���е�getDeptName����
string Manger::getDeptName() {
	return string("����");

}