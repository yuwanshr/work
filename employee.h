
#pragma once
#include"worker.h"
#include<iostream>
#include<string>

// 普通员工类，继承worker类别
class Employee :public Worker {
public:
	// 构造函数，我们希望在创建员工类对象的时候直接就初始化员工的信息
	// 因此在构造函数里，我们需要设立职工编号。职工姓名。职工部门三个编号
	// 在写以下代码的时候，千万不可以加{}，加上这就是函数的实现，在cpp文件中在次实现会报错。
	Employee(int id, string name, int deptId);
	// 重写父类中的方法
	void showInfo();
	string getDeptName();



};
