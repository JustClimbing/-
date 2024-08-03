/*通讯录管理系统
1、系统需求通讯录是一个可以记录亲人、好友信息的工具。
本教程主要利用C++来实现一个通讯录管理系统系统中需要实现的功能如下：
·添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
·显示联系人：显示通讯录中所有联系人信息
·删除联系人：按照姓名进行删除指定联系人
·查找联系人：按照姓名查看指定联系人信息
·修改联系人：按照姓名重新修改指定联系人
·清空联系人：清空通讯录中所有信息
·退出通讯录：退出当前使用的通讯录*/
#include <iostream>
using namespace std;

//菜单界面
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****"  << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

int main()
{
	showMenu(); //调用菜单

	int select = 0;
	
	//选择功能
	while (true)//使其只有按0时才能退出
	{
		cin >> select;
		switch (select)
		{
		case 1:// 1、添加联系人 
			break;
		case 2:// 2、显示联系人 
			break;
		case 3:// 3、删除联系人 
			break;
		case 4:// 4、查找联系人 
			break;
		case 5:// 5、修改联系人 
			break;
		case 6:// 6、清空联系人
			break;
		case 0://退出功能
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	

	system("pause"); //按任意键继续，不会让程序一闪而过
		return 0;
}
