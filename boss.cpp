#include<iostream>
#include"boss.h"
#include<string>
using namespace std;

// 实现boss类的构造函数
Boss::Boss(int id, string name, int deptId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

//  实现boss类的showInfo()函数
void Boss::showInfo() {
	cout << "编号为：" << m_Id << "\t" << "姓名为：" << m_Name << "\t" << "部门为：" << this->getDeptName() << "\t" << "岗位职责；牛逼无敌大总裁" << endl;
}

// 实现boss类中的getDeptName函数
string Boss::getDeptName() {
	return string("总裁");

}