﻿#pragma once
#ifndef EXAMGEN_H
#define EXAMGEN_H

#include<iostream>
#include<random>
#include<string>
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
	sym_plus = 0, 
	sym_minus = 1, 
	sym_multiply = 2, 
	sym_divide = 3 
}Symbol;	//Symbol枚举变量定义，用于表明运算符号类型。
typedef struct GenNode
{
	bool isElem;				//标识当前二叉树节点是否为运算数值，若为表达式则值为false
	bool isExpressionHead;		//标识当前二叉树节点是否为运算表达式的第一个元素
								//是的话该值为true，nodeSymbol不能为sym_multiply或sym_divide
								//否则值为false，nodeSymbol取值不限。
	bool isFraction;			//标识当前运算数值是否为真分数，是则为true，否则为false

	Symbol nodeSymbol;			//表示当前二叉树节点的运算符号类型
	ValueType value;			//表示当前二叉树节点的运算值，若为表达式，则值为0
	ValueType molecular;		//表示当前二叉树节点的真分数分子
	ValueType denominator;		//表示当前二叉树节点的真分数分母

	GenNode *nextElem;			//指向下一个运算数值节点的指针，若为NULL则说明已至当前表达式的末尾
	GenNode *expressionHead;	//指向下一个运算表达式节点的指针，若为NULL则说明当前节点为数值节点
}GenNode, *pGenNode;

typedef enum
{
	lv_easy = 0,		//小学生模式，此难度下四则运算数值仅为个位数，且无括号，表达式内运算数值个数为4个
	lv_normal = 1,		//中学生模式，此难度下题目四则运算数值有十位数，至多有一层括号嵌套，表达式内运算数值或子表达式个数为3个
	lv_hard = 2,		//大学生模式，此难度下题目四则运算数值有百位数，至多有两层括号嵌套，表达式内运算数值或子表达式个数为3个
	lv_Hardcore = 3,	//硬核模式，此难度下题目四则运算数值有千位数，至多有三层括号嵌套，表达式内运算数值或子表达式个数位4个
	lv_UserDefine = 4	//自定义模式,此难度下题目四则运算数值、括号层数、运算数值或子表达式可自定义。
}Level;		//Level枚举变量定义，表明生成题目的难度。


class clExamGen
{
public:
	bool ifFraction;						//存储当前题目生成是否包括真分数
	unsigned int maxNumOfElem;				//存储一个表达式中运算值及子表达式的最大个数
	unsigned int numOfExpression;			//存储一个题目中表达式嵌套的个数
	Level lvMode;							//存储题目难度
	string strExam;							//存储由二叉树整理出来的题目字符串
	pGenNode genNodeRoot;					//题目二叉树头节点
	ValueType maxiumOfValue;				//生成数值的最大值
	ValueType maxiumOfDenominator;			//生成分母的最大值
	ValueType maxiumOfMolecular;			//生成分子的最大值

	char SymbolToChar(Symbol IN_symbol);	//根据传入的IN_symbol输出对应符号的ASCII
	Status GetRandom(ValueType &Data, ValueType IN_Minima, ValueType IN_Maxima);	//获取[Minima,Maxima)的随机数,将该数传给Data
	Status GetRandom1(ValueType &Data, ValueType IN_Minima, ValueType IN_Maxima);	//获取[Minima,Maxima]的随机数,将该数传给Data
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
	Status SetNode(
		pGenNode	pNode,					//被写值节点的节点指针
		bool		IN_isElem,				//待写入的运算数值标识
		bool		IN_isExpressionHead,	//待写入的表达式头节点标识
		bool		IN_isFraction,			//待写入的表达式运算数值真分数标识
		Symbol		IN_nodeSymbol,			//待写入的运算符号枚举变量
		ValueType	IN_value,				//代写入的运算数值
		ValueType	IN_molecular,			//代写入的真分数分子
		ValueType	IN_denominator,			//代写入的真分数分母
		pGenNode	IN_nextElem,			//当前表达式中代写入的下一个数值节点指针
		pGenNode	IN_expressionHead		//当前表达式中代写入的下一个子表达式节点指针
	);		//(真分数)设置pNode指向的结构体的值,函数成功则返回en_success;pNode值为空则输出错误信息，返回en_nullptr

	Status CreateBiTree(pGenNode &pFather, int times);	//以pFather为头节点，递归生成试题二叉树，传参times为递归次数
	Status DeleteBiTree(pGenNode &pFather);	//递归释放二叉树节点空间
	//Status CreateExamToString(Level IN_lvmode, string &Out_dst);	//根据传入的试题难度自动生成试题，并将试题字符串化，复制到Out_dst的string引用对象中
	Status CreateExamToString(
		Level IN_lvmode,						//传入的题目生成难度，仅接受自定义难度，其他难度则报错并返回en_fail
		string &Out_dst,						//输出的string类引用，当函数成功生成一道题目时会将其字符串化并输出至该引用对应的对象				
		ValueType IN_maxiumOfValue,				//待生成题目的数值最大值，题目生成参数，若为50,则运算数值范围为[1,50)
		ValueType IN_maxiumOfMolecular,			//待生成题目的真分数分子最大值
		ValueType IN_maxiumOfDenominator,		//待生成题目的真分数分母最大值
		unsigned int IN_numOfElem,				//待生成题目中一个表达式中运算值及子表达式的最大个数
		unsigned int IN_numOfExpression			//待生成题目中的括号嵌套层数
	);	//(用户自定义难度)根据传入的试题参数自动生成试题，并将试题字符串化，复制到Out_dst的string引用对象中,返回值为Status状态枚举值
	Status CreateExamToString1(
		Level IN_lvmode,						//传入的题目生成难度，仅接受自定义难度，其他难度则报错并返回en_fail
		string &Out_dstCout,					//(无分数转换)输出的string类引用，当函数成功生成一道题目时会将其字符串化并输出至该引用对应的对象		
		string &Out_dstCal,						//(有分数转换)输出的string类引用，当函数成功生成一道题目时会将其字符串化并输出至该引用对应的对象	
		ValueType IN_maxiumOfValue,				//待生成题目的数值最大值，题目生成参数，若为50,则运算数值范围为[1,50)
		ValueType IN_maxiumOfMolecular,			//待生成题目的真分数分子最大值
		ValueType IN_maxiumOfDenominator,		//待生成题目的真分数分母最大值
		unsigned int IN_numOfElem,				//待生成题目中一个表达式中运算值及子表达式的最大个数
		unsigned int IN_numOfExpression			//待生成题目中的括号嵌套层数
	);	//(用户自定义难度)(真分数转换)根据传入的试题参数自动生成试题，并将试题字符串化，复制到Out_dst的string引用对象中,返回值为Status状态枚举值
	Status DeleteOneElemExpression(pGenNode pLast, pGenNode pNode);	//对于仅含有一个元素的表达式时，进行表达式节点删除操作，类似单链表的中间节点删除

	void BiTreeInfoIntoString(pGenNode pFather, string &dst);	//将试题的信息输入至dst对应字符串中
	void BiTreeInfoIntoString1(pGenNode pFather, string &dstCal, string &dstCout);	//将试题的信息输入至dstCal(真分数转换)、dstCout(无真分数转换)对应字符串中
	void ShowTree(pGenNode pFather);		//递归输出试题树的信息



};





#endif // !EXAMGEN_H
