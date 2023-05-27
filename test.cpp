#include<iostream>
using namespace std;
void exit() {
	cout << "欢迎下次使用" << endl;
	exit(0);
}
int main() {

	int choice = 0;
	while (true)
	{
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			exit();
			break;
		case 1:
			cout << "您输入的为1" << endl;
			break;
		case 2:
			cout << "您输入的为2" << endl;
			break;
		case 3:
			cout << "您输入的为3" << endl;
			break;
		default:
			break;
		}
	}

	cin.get();



}