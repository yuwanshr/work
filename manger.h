#pragma once
#include"worker.h"
#include<iostream>
#include<string>
//创建经理类，继承Worker类中的属性，并重写方法
class Manger :public Worker {
public:
	//和Employee一样，我们也希望在创建对象的时候直接实例化
	Manger(int id, string name, int deptId);

	// 重写Worker中的方法

	void showInfo();

	string getDeptName();



};


