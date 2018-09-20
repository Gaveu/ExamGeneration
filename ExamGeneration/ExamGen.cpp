#include "ExamGen.h"

Status clExamGen::SetLevel(Level IN_level)		//根据传入的IN_level设置类内参数lvMode、maxNumOfElem、numOfExpression、maxiumOfValue
{
	switch (lvMode)
	{
	case lv_easy:	//小学生模式，此难度下四则运算数值仅为1位数，且无括号，表达式内运算数值个数不超过3个
	{
		maxiumOfValue = 10;
		maxNumOfElem = 3;
		numOfExpression = 0;
	}break;

	case lv_normal:	//中学生模式，此难度下题目四则运算数值有2位数，有一层括号嵌套，表达式内运算数值或子表达式个数不超过3个
	{
		maxiumOfValue = 100;
		maxNumOfElem = 3;
		numOfExpression = 1;
	}break;

	case lv_hard:	//大学生模式，此难度下题目四则运算数值有3位数，有两层括号嵌套，表达式内运算数值或子表达式个数不超过3个
	{
		maxiumOfValue = 1000;
		maxNumOfElem = 3;
		numOfExpression = 2;
	}break;

	case lv_Hardcore:	//硬核模式，此难度下题目四则运算数值有4位数，有三层括号嵌套，表达式内运算数值或子表达式个数不超过4个
	{
		maxiumOfValue = 10000;
		maxNumOfElem = 4;
		numOfExpression = 3;
	}break;

	default:
	{
		cout<<"SetLevel:Level set failed,the input is illegal!"<<endl;
		return en_fail;
	}
	}
	lvMode = IN_level;
	return en_success;
}

Status clExamGen::GetNode(pGenNode &pNode)	//动态申请GenNode大小的内存，成功则将该内存地址返回给pNode并返回en_success;否则输出错误信息并返回en_fail

{
	pGenNode p;
	p = (GenNode *)malloc(sizeof(GenNode));
	if (!p)
	{
		cout << "GetNode:malloc failed" << endl;
		return en_fail;
	}
	pNode = p;
	return en_success;
}

Status clExamGen::SetNode(				//设置pNode指向的结构体的值,函数成功则返回en_success;pNode值为空则输出错误信息，返回en_nullptr
	pGenNode	pNode,					//被写值节点的节点指针
	bool		IN_isElem,				//待写入的运算数值标识
	bool		IN_isExpressionHead,	//待写入的表达式头节点标识
	Symbol		IN_nodeSymbol,			//待写入的运算符号枚举变量
	ValueType	IN_value,				//代写入的运算数值
	pGenNode	IN_nextElem,			//当前表达式中代写入的下一个数值节点指针
	pGenNode	IN_expressionHead		//当前表达式中代写入的下一个子表达式节点指针
)		
{
	if (!pNode)
	{
		cout << "SetNode:pNode is nullptr!GenNode set failed" << endl;
		return en_nullptr;
	}

	pNode->isElem = IN_isElem;
	pNode->isExpressionHead = IN_isExpressionHead;
	pNode->nodeSymbol = IN_nodeSymbol;
	pNode->value = IN_value;
	pNode->nextElem = IN_nextElem;
	pNode->expressionHead = IN_expressionHead;
	return en_success;
}