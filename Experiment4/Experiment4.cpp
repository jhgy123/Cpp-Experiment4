// Experiment4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
template <class T> class Stack {
private:
	int size;	//栈空间大小
	int top;	//栈指针
	T* space; //动态数组指针
public:
	Stack(int size = 10) {//初始化函数，默认值为10
		this->size = size;
		space = new T[size];   //初始化栈 分配大小 指向第一个数据
		top = size;
	}
	~Stack() {//析构函数，销毁分配的内存空间
		delete[]space;
		space = NULL;
	}

	bool push(const T& value) {
		if (IsFull())//判断栈是否满
			return false;
		space[--top] = value;
		return true;
	}

	T  pop() {
		if (IsEmpty()) {//判断栈是为空
			throw  0;//抛出异常
			return NULL;
		}	
		else {
			return space[top++];
		}
		
	}
	bool IsEmpty() const {
		return  top == size; 
	}
	bool IsFull() const {
		return  top == 0;
	}
};






int main()
{
	Stack<char> NameStack(50);//将模板类实例化为char类的模板栈，并生成栈模板类对象
	Stack<char> NumStack(20);//将模板类实例化为char类的模板栈，并生成栈模板类对象
	char name[50] = "gongyinhongjie";//姓名拼音
	for (int i=0; i < strlen(name); ++i) {//将姓名拼音压入栈中
		NameStack.push(name[i]);
	}
	char num[20] = "202010560449";//姓名拼音
	for (int i = 0; i < strlen(num); ++i) {//将学会压入栈中
		NumStack.push(num[i]);
	}

	for (int i = 0; i < strlen(name) + 1; ++i) {//依次从姓名栈中取出元素
		try {
			cout << NameStack.pop();//若栈空时仍然pop,则抛出异常
		}
		catch (int) {//异常处理
			cerr << endl << "栈以空，无法执行pop操作！"<<endl;
		}
	}

	for (int i = 0; i < strlen(num)+1; ++i) {//依次从学号栈中取出元素
		try {
			cout << NumStack.pop();//若栈空时仍然pop,则抛出异常
		}
		catch (int) {//异常处理
			cerr << endl << "栈以空，无法执行pop操作！"<<endl;
		}
	}
	return 0;

}

