#pragma once
#include<iostream>
#include"worker.h"
#include<string>
using namespace std;

class Boss :public Worker {
	public:
	//和Employee一样，我们也希望在创建对象的时候直接实例化
	Boss(int id, string name, int deptId);

	// 重写父类中的函数
	void showInfo();

	string getDeptName();

};