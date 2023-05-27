#pragma once	// 防止头文件重复包含
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manger.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager {
public:
	 WorkerManager();

	 // 添加成员函数，展示菜单
	 void Show_Menu();

	 // 退出系统
	 void Exit_System();

	 // 添加人员函数
	 void addEmp();

	 // 保存人员到文件中函数
	 void save();

	 // 统计文件中的人数
	 int get_EmpNUM();

	 // 初始化员工
	 void init_Emp();

	 int m_EmpNum;	// 记录文件中的人员个数
	 /*
	 指针和对象的关系可以用一个简单的比喻来理解：
	 指针就像是一个遥控器，它可以控制一个对象，也就是电视机。
	 对象有自己的属性和方法，比如电视机有品牌、型号、颜色等属性，还有开关、换台、调音量等方法。
	 指针可以通过遥控器上的按钮来访问或修改对象的属性和方法，比如按开关按钮可以打开或关闭电视机，按换台按钮可以切换电视机的频道，按音量按钮调节声音
	 指针也有自己的地址，就像遥控器上有一个编号，可以用来区分不同的遥控器。
	 指针的地址可以存储在另一个指针中，就像一个遥控器可以控制另一个遥控器，这就是双指针的概念。
	 双指针可以用来创建动态的数组，就像一组遥控器可以控制一组电视机。
	 */

	 // 显示职工
	 void Show_Emp();

	 // 删除职工
	 void Del_Emp();

	 // 判断职工是否存在
	 int IsExist(int id);

	 // 修改职工的信息
	 void Mod_Emp();

	 // 查找职工的信息
	 void Find_Emp();

	 bool Find_mark;//用来结束死循环
	 // 按编号查找
	 void FindbyId();
	// 按名字查找
	 void FindbyName();

	 // 按照编号进行排序
	 void Sort_Emp();

	 // 清空文件函数
	 void Clean_File();

	 // Worker** m_EmpArray是一个双指针
	 // 它指向一个Worker类型的指针数组，这个数组可以存储多个Worker类型的指针，每个指针又指向一个Worker类的对象。
	 // 数组里的元素是Worker*类型的指针，也就是指向Worker类对象的指针。每个元素都可以用来访问或修改Worker类对象的属性和方法。
	 Worker** m_EmpArray;	// 指向员工数组的指针。
	
	 // 标志文件是否为空(方便于后期的读文件);
	 bool m_FileIsEmpty;

	 ~WorkerManager();

};