#include"ExamGen.h"

int main()
{
	clExamGen *p = new clExamGen();
	string s;
	/*
	难度模式：
		lv_easy		//小学生模式，此难度下四则运算数值仅为个位数，且无括号，表达式内运算数值个数为4个
		lv_normal	//中学生模式，此难度下题目四则运算数值有十位数，至多有一层括号嵌套，表达式内运算数值或子表达式个数为3个
		lv_hard		//大学生模式，此难度下题目四则运算数值有百位数，至多有两层括号嵌套，表达式内运算数值或子表达式个数为3个
		lv_Hardcore	//硬核模式，此难度下题目四则运算数值有千位数，至多有三层括号嵌套，表达式内运算数值或子表达式个数位4个
		lv_UserDefine	//自定义模式,此难度下题目四则运算数值、括号层数、运算数值或子表达式可自定义。
	*/

	//此处演示十个选定了难度(lv_normal)的题目
	Level lv = lv_normal;
	for (int i = 0; i < 10; ++i)
	{
		//根据选定的难度lv,随机生成一道四则运算题目并将其字符串化，输出到string类的实例s中。
		//此处函数调用示例不支持自定义模式(lv_UserDefine),要调用自定义模式的话可以看下个演示
		p->CreateExamToString(lv,s);	
		cout << s.c_str() << endl;
	}
	cout <<"---------------------------------------"<< endl;

	//此处演示十个自定义难度的题目
	lv = lv_UserDefine;
	for (int i = 0; i < 10; ++i)	
	{
		/*
		Status CreateExamToString(
			Level IN_lvmode,						//传入的题目生成难度，仅接受自定义难度，其他难度则报错并返回en_fail
			string &Out_dst,						//输出的string类引用，当函数成功生成一道题目时会将其字符串化并输出至该引用对应的对象				
			ValueType IN_maxiumOfValue,				//待生成题目的数值最大值，题目生成参数，若为50,则运算数值范围为[1,50)
			unsigned int IN_numOfElem,				//待生成题目中一个表达式中运算值及子表达式的最大个数
			unsigned int IN_numOfExpression			//待生成题目中的括号嵌套层数
		);	//(用户自定义难度)根据传入的试题参数自动生成试题，并将试题字符串化，复制到Out_dst的string引用对象中
		*/
		p->CreateExamToString(lv_UserDefine, s, 50, 5, 0);
		cout << s.c_str() << endl;
	}
	cout << "---------------------------------------" << endl;
	system("PAUSE");
	return 0;
}