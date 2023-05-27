#include<iostream>
#include"manger.h"
#include<string>

// 实现manger类中的构造函数：
Manger::Manger(int id, string name, int deptId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

// 实现manger类的showInfo()函数
void Manger::showInfo() {
	cout << "编号为：" << m_Id << "\t" << "姓名为：" << m_Name<<"\t" << "部门为：" << this->getDeptName()<<"\t" << "岗位职责；平平无奇小经理" << endl;

}

// 实现manger类中的getDeptName函数
string Manger::getDeptName() {
	return string("经理");

}