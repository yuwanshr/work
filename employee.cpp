// ��������У�������Ҫʵ��employee�ķ���
#include"employee.h"
#include<iostream>
using namespace std;

// ʵ��employee�еĹ��캯��
Employee::Employee(int id, string name, int deptId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

// ʵ��employee�е�showInfo����
void Employee::showInfo() {
	cout << "���Ϊ��" << m_Id << "\t" << "����Ϊ��" << m_Name << "\t" << "����Ϊ��" << this->getDeptName() << "\t" << "��λְ��ƽƽ�������" << endl;
}

// ʵ��employee�е�getDeptName����
string Employee::getDeptName() {
	return string("Ա��");
}