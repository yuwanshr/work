#pragma once
#include<iostream>
using namespace std;
#include<string>
// 在这个头文件里，我们需要建立一个职工的基类。
// 公司中职工分为三类：普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位.
// 在这个类中定义三个属性：编号，姓名，所在部门名称编号.
// 定义两种行为：岗位职责信息描述，获取岗位名称
class Worker {

public:

	// 定义两种行为,设置为纯虚函数，方便子类重写
	// 显示个人信息
	virtual void showInfo() = 0;
	// 显示部门名称
	virtual string getDeptName() = 0;

	int m_Id;		  // 职工编号
	string m_Name;	  // 职工姓名
	int m_DeptId;	  // 部门编号

};
