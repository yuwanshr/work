#include"workerManager.h"

// 类内定义，类外声明。
WorkerManager::WorkerManager() {
	// 判断文件是否存在
	this->Find_mark = true;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl; //测试输出
		this->m_EmpNum = 0;  //初始化人数
		this->m_FileIsEmpty = true; //初始化文件为空标志
		this->m_EmpArray = NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}

	// 文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		// 文件为空
		cout << "文件为空!" << endl;
		this->m_EmpNum = 0;  //初始化人数
		this->m_FileIsEmpty = true; //初始化文件为空标志
		this->m_EmpArray = NULL; //初始化数组
		ifs.close(); //关闭文件
		return;
	}

	// 文件存在并且数据不为空
	this->m_FileIsEmpty = false;
	int num = this->get_EmpNUM();
	cout << "职工的人数为：" << num << endl;
	//this->init_Emp();
	this->m_EmpNum = num;
	
	// 开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// 将文件中的数据，存到数组中
	this->init_Emp();

	// 测试以下
	//for (int i = 0; i < this->m_EmpNum; i++) {
	//	cout << "员工编号为：" << this->m_EmpArray[i]->m_Id
	//		<< "姓名为：" << this->m_EmpArray[i]->m_Name
	//		<< "部门编号为：" << this->m_EmpArray[i]->m_DeptId << endl;
	//}

	
}

// 实现Show_Menu函数功能，展示页面
void WorkerManager::Show_Menu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

// 实现Exit_System函数功能,退出程序
void WorkerManager::Exit_System() {
	cout << "欢迎您下次再来使用" << endl;
	system("pause");
	// 退出功能的实现.
	exit(0);
}

// 实现add_Emp函数功能，增加职工
void WorkerManager::addEmp() {
	cout << "请输入您要添加的员工人数：" << endl;
	// 用来记录输入的添加数量
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		// 计算新的人员空间个数
		int newSize = this->m_EmpNum + addNum;
		// 将新的人员个数开辟到新的空间里
		Worker** newSpace = new Worker * [newSize*sizeof(Worker)];
		// 如果原本数组中有人，我们需要将它赋值到新空间里
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// 批量添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect; //方便用户选择职位。
			cout << "请您输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请您输入所添加职工的姓名" << endl;
			cin >> name;

			bool flag = false;
			while (!flag)
			{
				cout << "请选择该职工的岗位：" << endl;
				cout << "1、普通职工" << endl;
				cout << "2、经理" << endl;
				cout << "3、老板" << endl;
				cin >> dSelect;
				if (dSelect == 1 || dSelect == 2 || dSelect == 3) {
					flag = true;
				}
				else {
					cout << "您输入有误，请重新输入" << endl;
				}
			}


			// 创建Worker类型的指针
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:	// 普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2: // 经理
				worker = new Manger(id, name, 2);
				break;
			case 3: // 总裁.
				worker = new Boss(id, name, 2);
				break;
			default:
				break;
			}

			// 将创建的职工指针保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		// 释放原有的空间
		delete[] this->m_EmpArray;

		// 更改新空间的指向
		this->m_EmpArray = newSpace;

		// 更新职工人数
		this->m_EmpNum = newSize;

		// 更新职工不为空
		this->m_FileIsEmpty = false;

		// 将数据保存到文件中
		this->save();
		cout << "添加成功！" << endl;
		// 保存数据到文件目录中
		
	}
	else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

// 实现save函数功能，保存数据
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name << " " << this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

// 实现get_EmpNUM()函数功能，统计人数
int WorkerManager::get_EmpNUM() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}
	/*
	getline是一个C++标准库函数，它用于从输入流中读取一行文本。
	它的第一个参数是一个输入流对象，第二个参数是一个字符串对象，用于存储读取到的文本。
	在上面的示例代码中，getline(ifs, line)会从file输入流中读取一行文本，并将其存储在line字符串中。
	如果读取成功，getline函数会返回true，否则返回false。
	while (getline(file, line))这一行代码的意思是：
	当能够从file输入流中读取到一行文本时，就执行循环体内的语句。当无法再从输入流中读取到文本时，循环结束。
	*/

// 实现int init_Emp()函数,将文件中的数据记录到数组中
void WorkerManager::init_Emp() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //2经理
		{
			worker = new Manger(id, name, dId);
		}
		else //总裁
		{
			worker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();

}

// 实现 void Show_Emp()函数，显示职工人员信息
void WorkerManager::Show_Emp() {

	// 判断文件是否为空
	if (this->m_FileIsEmpty) {
		cout << "职工人员信息为空！" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			//利用多态来调用程序的接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");

}

// 实现int IsExist(int id)，判断职工是否存在
int WorkerManager::IsExist(int id) {
	// 若找到则返回该职工在数据中的位数，不存在返回-1
	int indiex = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			indiex = i;
			break;
		}
	}
	return indiex;
}

// 实现void Del_Emp()函数，删除职工信息。
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "当前没有员工信息！" << endl;
	}
	else {
		cout << "请您输入要删除的员工编号:" << endl;
		int id = 0;
		cin >> id;
		int flag = IsExist(id);
		if (flag != -1) {
			for (int i = flag; i < this->m_EmpNum - 1; i++) {
				// 覆盖
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			// 更新文件中的内容
			this->save();
			cout << "删除成功！" << endl;
		}
		else {
			cout << "查无此编号！" << endl;
		}
		
	}
	system("pause");
	system("cls");



}

// 实现void Mod_Emp()函数，修改职工信息
void WorkerManager::Mod_Emp() {
	// 判断文件是否存在
	if (this->m_FileIsEmpty) {
		cout << "当前没有员工信息！" << endl;
	}
	else {
		// 让用户输入id，判断id是否存在
		cout << "请输入您要修改员工的编号：" << endl;
		int id;
		cin >> id;
		int Mod_flag = IsExist(id);
		if (Mod_flag != -1) {

			// 在数组中删除该员工的信息
			delete this->m_EmpArray[Mod_flag];

			// 让用户修改该员工的信息
			int newId;
			string newName;
			int newDeptid;

			cout << "成功查到" << id << "号员工，请您输入新编号" << endl;
			cin >> newId;
			cout << "请您输入姓名" << endl;
			cin >> newName;

			bool mark = true;
			while (mark)
			{
				cout << "请选择该职工的岗位：" << endl;
				cout << "1、普通职工" << endl;
				cout << "2、经理" << endl;
				cout << "3、老板" << endl;
				cin >> newDeptid;
				if (newDeptid == 1 || newDeptid == 2 || newDeptid == 3) {
					mark = false;
				}
				else {
					cout << "您输入有误，请您重新输入！" << endl;
				}
			}
			Worker* work = NULL;
			switch (newDeptid)
			{
			case 1:
				work = new Employee(newId, newName, newDeptid);
				break;
			case 2:
				work = new Manger(newId, newName, newDeptid);
				break;
			case 3:
				work = new Boss(newId, newName, newDeptid);
				break;
			default:
				break;
			}

			// 更新数组中的数据
			this->m_EmpArray[Mod_flag] = work;
			cout << "修改成功！" << endl;
			// 更新文件中的数据
			this->save();

		}
		else {
			cout << "修改失败，查无此人！" << endl;
		}

	}
	system("pause");
	system("cls");
}

// 实现void Find_Emp()函数，查找职工信息。
void WorkerManager::Find_Emp() {
	// 判断人员信息是否为空
	if (this->m_FileIsEmpty) {
		cout << "当前没有员工信息！" << endl;
	}
	else {
		int select = 0;
		
		while (true)
		{
			cout << "请输入您要查找的方式；" << endl;
			cout << "1、按照员工编号查找" << endl;
			cout << "2、按照员工姓名查找" << endl;
			cout << "0、退出查找" << endl;
			cin >> select;
			switch (select)
			{
			case 1:
				FindbyId();
				return;
				break;
			case 2:
				FindbyName();
				return;
				break;
			case 0:
				cout << "退出成功" << endl;
				//this->Find_mark = false;
				system("pause");
				system("cls");
				return;
				break;
			default:
				cout << "输入有误，请重新输入" << endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
}

// 按照编号查找
void WorkerManager::FindbyId() {
	cout << "请您输入要查找的员工编号；" << endl;
	int id;
	cin >> id;
	int ret = IsExist(id);
	if (ret != -1) {
		cout << "成功找到该人员信息；" << endl;
		this->m_EmpArray[ret]->showInfo();
		//this->Find_mark = false;
	}
	else {
		cout << "查无此人" << endl;
		//this->Find_mark = false;
	}
	system("pause");
	system("cls");
}

// 按照名字查找
void WorkerManager::FindbyName() {
	string name;
	cout << "请您输入要查找的员工姓名：" << endl;
	cin >> name;
	bool flag = false;  //查找到的标志
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Name == name) {
			cout << "已经成功找到，编号信息为：" << this->m_EmpArray[i]->m_Id << "的信息如下：" << endl;
			flag = true;
			this->m_EmpArray[i]->showInfo();
		}
	}
	if (!flag) {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

// 实现 void Sort_Emp()函数，员工信息排序
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请您输入选择排序的方式：" << endl;
		cout << "1、升序排序" << endl;
		cout << "2、降序排序" << endl;
		cout << "0、退出排序" << endl;
		int select;
		bool flag = true;
		while (flag)
		{
			cout << "请输入您的选择：" << endl;
			cin >> select;
			switch (select)
			{
			case 1:
				for (int i = 0; i < m_EmpNum; i++)
				{
					int minOrMax = i;
					for (int j = i + 1; j < m_EmpNum; j++)
					{
						if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
						{
							minOrMax = j;
						}
					}
					if (i != minOrMax)
					{
						Worker* temp = m_EmpArray[i];
						m_EmpArray[i] = m_EmpArray[minOrMax];
						m_EmpArray[minOrMax] = temp;
					}
				}
				cout << "排序成功,排序后结果为：" << endl;
				this->save();
				this->Show_Emp();
				flag = false;
				break;
			case 2:
				for (int i = 0; i < m_EmpNum; i++)
				{
					int minOrMax = i;
					for (int j = i + 1; j < m_EmpNum; j++)
					{
						if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
						{
							minOrMax = j;
						}
					}
					if (i != minOrMax)
					{
						Worker* temp = m_EmpArray[i];
						m_EmpArray[i] = m_EmpArray[minOrMax];
						m_EmpArray[minOrMax] = temp;
					}
				}
				cout << "排序成功,排序后结果为：" << endl;
				this->save();
				this->Show_Emp();
				flag = false;
				break;
			case 0:
				cout << "退出成功" << endl;
				flag = false;
				break;
			default:
				break;
			}
		}
	}
}

// 实现void Clean_File()函数，清空文件
void WorkerManager::Clean_File() {
	cout << "请输入您的选择" << endl;
	cout << "1、清空" << endl;
	cout << "2、返回" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		// 打开模式ios::trunc 如果存在文件，删除并且重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		// 删除维护用户信息的指针
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			delete this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清除成功" << endl;
	}
	system("pause");
	system("cls");
	
}


// 析构函数
WorkerManager::~WorkerManager() {

	// 释放开放到堆区的数据
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}