# 通讯录管理系统

# c++入门级别实战项目——通讯录管理系统

> 作为c++入门级别的实战项目，此通讯管理系统项目不仅仅是对c++入门阶段学习成果的检验，也是对c++基础知识的回顾，体会c++在实战制作中的思路,代码总行数大约300行

![img](https://p26.toutiaoimg.com/origin/tos-cn-i-qvj2lq49k0/00c721549a504c458f04b686c6c99a2c?from=pc)

## 一、通讯录管理系统简介

系统需求通讯录是一个可以记录亲人、好友信息的工具。

本教程主要利用C++来实现一个通讯录管理系统系统中需要实现的功能如下：

- 添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
- 显示联系人：显示通讯录中所有联系人信息
- 删除联系人：按照姓名进行删除指定联系人
- 查找联系人：按照姓名查看指定联系人信息
- 修改联系人：按照姓名重新修改指定联系人
- 清空联系人：清空通讯录中所有信息
- 退出通讯录：退出当前使用的通讯录

## 二、功能实现

### 2.1 实现菜单界面

> 这一步简单只需要封装一个showMenu函数，再在main中调用即可

``` c++
#include <iostream>
using namespace std;

//菜单界面
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

//主函数
int main()
{
	
	showMenu(); //调用菜单
	system("pause"); //按任意键继续，不会让程序一闪而过
		return 0;
}
```

## 2.2 实现表面选择功能与退出功能

> 这一步用switch函数实现选择功能，在在其中实现退出功能只需在主函数中修改，其他功能只写了个函数名还未进行实现

```c++
int main()
{
	int select = 0;//将初始选择设置为0
	
	//选择功能
	while (true)//使其只有按0时才能退出
	{
		showMenu(); //调用菜单
		cin >> select;
		switch (select)
		{
		case 1:// 1、添加联系人 
			addPerson(&abs);
			break;
		case 2:// 2、显示联系人
			showPerson(&abs);
			break;
		case 3:// 3、删除联系人 
			deletePerson(&abs);
			break;
		case 4:// 4、查找联系人 
			findPerson(&abs);
			break;
		case 5:// 5、修改联系人 
			modifyPerson(&abs);
			break;
		case 6:// 6、清空联系人
			clean(&abs);
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
```

## 2.3 添加联系人功能实现

> 首先创造联系人结构体与通讯录结构体，注意添加头文件#include <string>

``` c++
//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//年龄
	int m_Age;
	//性别 男1 女2
	int m_Sex;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
	Person pesrsonArray[MAX];//通讯录中保存的联系人数组
	int m_Size;//通讯录中人员个数

};
```

> 在主函数中创造通讯录对象，并初始化人数，并包装addPerson函数

```c++
#include <iostream>
using namespace std;
#include <string>

//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//年龄
	int m_Age;
	//性别 男1 女2
	int m_Sex;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
	Person pesrsonArray[MAX];//通讯录中保存的联系人数组
	int m_Size;//通讯录中人员个数

};

//添加联系人功能函数
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否满
	if (abs->m_Size >= MAX)
	{
		cout << "通讯录已满！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		abs->pesrsonArray[abs->m_Size].m_Name = name;
		//年龄
		int age;
		cout << "请输入联系人年龄：" << endl;
		
		while (true)//判断年龄是否符合要求
		{
			cin >> age;
			if (age > 0&&age<100)
			{
				abs->pesrsonArray[abs->m_Size].m_Age = age;
				break;
			}
			if (age >= 100)
			{
				abs->pesrsonArray[abs->m_Size].m_Age = age;
				cout << "先生，请教我长寿秘诀！" << endl;
				break;
			}
			cout << "你搁娘胎里啊？老弟！" << endl;
			cout << "请输入正确年龄：" << endl;
		}
		//性别
		int sex;
		cout << "请输入联系人性别：" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->pesrsonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "世界上只有两种性别，老弟" << endl;
			cout << "请输入正确性别：" << endl;
		}
		//电话
		string phone;
		cout << "请输入联系人电话：" << endl;
		cin >> phone;
		abs->pesrsonArray[abs->m_Size].m_Phone = phone;

		//地址
		string address;
		cout << "请输入联系人地址：" << endl;
		cin >> address;
		abs->pesrsonArray[abs->m_Size].m_Addr = address;

		//添加成功
		cout << "添加成功" << endl;
		
		abs->m_Size++;
		system("pause");
		system("cls");

	}
}

//菜单界面
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

//主函数
int main()
{
    int select = 0;//将初始选择设置为0
    //创建通讯录结构
    Addressbooks abs;
    //初始化人数
    abs.m_Size = 0;
	//选择功能
	while (true)//使其只有按0时才能退出
	{
		showMenu(); //调用菜单
		cin >> select;
		switch (select)
		{
		case 1:// 1、添加联系人 
			addPerson(&abs);
			break;
		case 2:// 2、显示联系人
			showPerson(&abs);
			break;
		case 3:// 3、删除联系人 
			deletePerson(&abs);
			break;
		case 4:// 4、查找联系人 
			findPerson(&abs);
			break;
		case 5:// 5、修改联系人 
			modifyPerson(&abs);
			break;
		case 6:// 6、清空联系人
			clean(&abs);
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
```



## 2.4 显示联系人功能实现

## 2.5 删除联系人功能实现

## 2.6 查找联系人功能实现

## 2.7 修改联系人功能实现

## 2.8 清空联系人功能实现

## 2.9 退出通讯录功能实现

上方功能不多赘述，完整代码如下:

>system("pause");//表示按任意键继续
>	system("cls");//表示清空一次屏幕

``` c++
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
#include <string>
#define MAX 1000 //便于维护

//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//年龄
	int m_Age;
	//性别 男1 女2
	int m_Sex;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
	Person pesrsonArray[MAX];//通讯录中保存的联系人数组
	int m_Size;//通讯录中人员个数

};
//菜单界面
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

//添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否满
	if (abs->m_Size >= MAX)
	{
		cout << "通讯录已满！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入联系人姓名：" << endl;
		cin >> name;
		abs->pesrsonArray[abs->m_Size].m_Name = name;
		//年龄
		int age;
		cout << "请输入联系人年龄：" << endl;
		
		while (true)//判断年龄是否符合要求
		{
			cin >> age;
			if (age > 0&&age<100)
			{
				abs->pesrsonArray[abs->m_Size].m_Age = age;
				break;
			}
			if (age >= 100)
			{
				abs->pesrsonArray[abs->m_Size].m_Age = age;
				cout << "先生，请教我长寿秘诀！" << endl;
				break;
			}
			cout << "你搁娘胎里啊？老弟！" << endl;
			cout << "请输入正确年龄：" << endl;
		}
		//性别
		int sex;
		cout << "请输入联系人性别：" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->pesrsonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "世界上只有两种性别，老弟" << endl;
			cout << "请输入正确性别：" << endl;
		}
		//电话
		string phone;
		cout << "请输入联系人电话：" << endl;
		cin >> phone;
		abs->pesrsonArray[abs->m_Size].m_Phone = phone;

		//地址
		string address;
		cout << "请输入联系人地址：" << endl;
		cin >> address;
		abs->pesrsonArray[abs->m_Size].m_Addr = address;

		//添加成功
		cout << "添加成功" << endl;
		
		abs->m_Size++;
		system("pause");
		system("cls");

	}
}

//显示联系人
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "您的通讯录无联系人" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名："<<abs->pesrsonArray[i].m_Name << "\t";//输出名字
			cout << "年龄："<<abs->pesrsonArray[i].m_Age << "\t";//输出年龄
			//输出性别
			/*if (abs->pesrsonArray[i].m_Sex == 1)
			{
				cout << "性别：男" << "\t";
			}
			else {
				cout << "性别：女" << "\t";
			}*/
			cout << "性别：" << (abs->pesrsonArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "电话：" << abs->pesrsonArray[i].m_Phone << "\t";//输出电话
			cout << "地址：" << abs->pesrsonArray[i].m_Addr << endl;//输出住址
		}
	}
	system("pause");
	system("cls");
}


//检测联系人是否存在，下方功能基本都需用到
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->pesrsonArray[i].m_Name == name)
		{
			return i;
		}
	}return -1;
}

//删除联系人功能
//找到并删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您想要删除的联系人：" << endl;
	string name;
	cin >> name;
	if (isExist(abs, name) == -1)
	{
		cout << "查无此人"<<endl;
	}
	else
	{
		for (int i = isExist(abs, name); i < abs->m_Size; i++)
		{
			abs->pesrsonArray[i] = abs->pesrsonArray[i + 1];
		}
		abs->m_Size--;
		cout << "成功删除，可按2查看" << endl;
	}
	system("pause");
	system("cls");


}

//查找联系人功能
// 判断，找不到输出查无此人，找到了显示联系人
void findPerson(Addressbooks* abs)
{
	//输入想要查找的名字
	string name;
	cout << "请输入你想要查找的联系人的名字："<<endl;
	cin >> name;
	if (isExist(abs, name) == -1)
	{
		cout << "查无此人" << endl;
	}
	else {
		cout << "姓名：" << abs->pesrsonArray[isExist(abs, name)].m_Name << "\t";//输出名字
		cout << "年龄：" << abs->pesrsonArray[isExist(abs, name)].m_Age << "\t";//输出年龄
		cout << "性别：" << (abs->pesrsonArray[isExist(abs, name)].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "电话：" << abs->pesrsonArray[isExist(abs, name)].m_Phone << "\t";//输出电话
		cout << "地址：" << abs->pesrsonArray[isExist(abs, name)].m_Addr << endl;//输出住址
	}
	system("pause");
	system("cls");

}
//修改联系人功能
void modifyPerson(Addressbooks* abs)
{
	cout << "请您选择你想要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		//姓名
		string Name;
		cout << "请修改联系人姓名：" << endl;
		cin >> Name;
		abs->pesrsonArray[ret].m_Name = Name;
		//年龄
		int age;
		cout << "请修改联系人年龄：" << endl;

		while (true)//判断年龄是否符合要求
		{
			cin >> age;
			if (age > 0 && age < 100)
			{
				abs->pesrsonArray[ret].m_Age = age;
				break;
			}
			if (age >= 100)
			{
				abs->pesrsonArray[ret].m_Age = age;
				cout << "先生，请教我长寿秘诀！" << endl;
				break;
			}
			cout << "你搁娘胎里啊？老弟！" << endl;
			cout << "请输入正确年龄：" << endl;
		}
		//性别
		int sex;
		cout << "请修改联系人性别：" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->pesrsonArray[ret].m_Sex = sex;
				break;
			}
			cout << "世界上只有两种性别，老弟" << endl;
			cout << "请输入正确性别：" << endl;
		}
		//电话
		string phone;
		cout << "请修改联系人电话：" << endl;
		cin >> phone;
		abs->pesrsonArray[ret].m_Phone = phone;

		//地址
		string address;
		cout << "请修改联系人地址：" << endl;
		cin >> address;
		abs->pesrsonArray[ret].m_Addr = address;
		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");

}
//清空通讯录
void clean(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "已清空" << endl;
	system("pause");
	system("cls");
}

int main()
{
	

	int select = 0;
	//创建通讯录结构
	Addressbooks abs;
	//初始化人数
	abs.m_Size = 0;
	
	//选择功能
	while (true)//使其只有按0时才能退出
	{
		showMenu(); //调用菜单
		cin >> select;
		switch (select)
		{
		case 1:// 1、添加联系人 
			addPerson(&abs);
			break;
		case 2:// 2、显示联系人
			showPerson(&abs);
			break;
		case 3:// 3、删除联系人 
			deletePerson(&abs);
			break;
		case 4:// 4、查找联系人 
			findPerson(&abs);
			break;
		case 5:// 5、修改联系人 
			modifyPerson(&abs);
			break;
		case 6:// 6、清空联系人
			clean(&abs);
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

```

