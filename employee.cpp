// 在这个类中，我们需要实现employee的方法
#include"employee.h"
#include<iostream>
using namespace std;

// 实现employee中的构造函数
Employee::Employee(int id, string name, int deptId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

// 实现employee中的showInfo方法
void Employee::showInfo() {
	cout << "编号为：" << m_Id << "\t" << "姓名为：" << m_Name << "\t" << "部门为：" << this->getDeptName() << "\t" << "岗位职责；平平无奇打工人" << endl;
}

// 实现employee中的getDeptName方法
string Employee::getDeptName() {
	return string("员工");
}