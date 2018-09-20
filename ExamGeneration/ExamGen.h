#pragma once
#ifndef EXAMGEN_H
#define EXAMGEN_H

#include<iostream>
using namespace std;

typedef unsigned int ValueType;	//ValueType定义，可用于快速修改值的变量类型
typedef enum 
{ 
	en_success = 0, 
	en_fail, 
	en_true, 
	en_false, 
	en_nullptr 
}Status;	//Status状态变量定义，用于表明运行状态，常作为函数返回值。
typedef enum 
{ 
	sym_plus = '+', 
	sym_minus = '-', 
	sym_multiply = '*', 
	sym_divide = '/' 
}Symbol;	//Symbol枚举变量定义，用于表明运算符号类型。
typedef struct GenNode
{
	bool isElem;				//标识当前二叉树节点是否为运算数值，若为表达式则值为false
	bool isExpressionHead;		//标识当前二叉树节点是否为运算表达式的第一个元素
								//是的话该值为true，nodeSymbol不能为sym_multiply或sym_divide；
								//否则值为false，nodeSymbol取值不限。

	Symbol nodeSymbol;			//表示当前二叉树节点的运算符号类型
	ValueType value;			//表示当前二叉树节点的运算值，若为表达式，则值为0

	pGenNode nextElem;			//指向下一个运算数值节点的指针，若为NULL则说明已至当前表达式的末尾
	pGenNode expressionHead;	//指向下一个运算表达式节点的指针，若为NULL则说明当前节点为数值节点
}GenNode,*pGenNode;
typedef enum
{
	lv_easy = 0,		//小学生模式，此难度下四则运算数值仅为1位数，且无括号，表达式内运算数值个数不超过3个
	lv_normal = 1,		//中学生模式，此难度下题目四则运算数值有2位数，有一层括号嵌套，表达式内运算数值或子表达式个数不超过3个
	lv_hard = 2,		//大学生模式，此难度下题目四则运算数值有3位数，有两层括号嵌套，表达式内运算数值或子表达式个数不超过3个
	lv_Hardcore = 3		//硬核模式，此难度下题目四则运算数值有4位数，有三层括号嵌套，表达式内运算数值或子表达式个数不超过4个
}Level;		//Level枚举变量定义，表明生成题目的难度。


class clExamGen
{
public:
	unsigned int maxNumOfElem;				//存储一个表达式中运算值及子表达式的最大个数
	unsigned int numOfExpression;			//存储一个题目中表达式嵌套的个数
	Level lvMode;							//存储题目难度
	string strExam;							//存储由二叉树整理出来的题目字符串
	pGenNode genNodeRoot;					//题目二叉树头节点
	ValueType maxiumOfValue;				//生成数值的最大值

	Status SetLevel(Level IN_level);		//根据传入的IN_level设置类内参数lvMode、maxNumOfElem、numOfExpression、maxiumOfValue
	Status GetNode(pGenNode &pNode);		//动态申请GenNode大小的内存，成功则将该内存地址返回给pNode并返回en_success;否则输出错误信息并返回en_fail
	Status SetNode(
		pGenNode	pNode,					//被写值节点的节点指针
		bool		IN_isElem,				//待写入的运算数值标识
		bool		IN_isExpressionHead,	//待写入的表达式头节点标识
		Symbol		IN_nodeSymbol,			//待写入的运算符号枚举变量
		ValueType	IN_value,				//代写入的运算数值
		pGenNode	IN_nextElem,			//当前表达式中代写入的下一个数值节点指针
		pGenNode	IN_expressionHead		//当前表达式中代写入的下一个子表达式节点指针
	);		//设置pNode指向的结构体的值,函数成功则返回en_success;pNode值为空则输出错误信息，返回en_nullptr

	

	void workMain();						//功能执行主函数



};





#endif // !EXAMGEN_H
