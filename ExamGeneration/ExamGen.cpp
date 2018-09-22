#include "ExamGen.h"

Status clExamGen::GetRandom(ValueType &Data, ValueType IN_Minima, ValueType IN_Maxima)	//获取取值区间为[Minima,Maxima)的随机数,将该数传给Data
{
	if (IN_Maxima <= IN_Minima)		//取值区间不符合[Minima,Maxima)的输入都进行判错处理
	{
		cout << "GetRandom:Input is illegal.Get the Random failed!" << endl;
		return en_fail;
	}
	Data = (rand() % (IN_Maxima - IN_Minima)) + IN_Minima;	//Data赋值为[Minima,Maxima)内的一个随机数
	return en_success;

}

Status clExamGen::SetLevel(Level IN_level)		//根据传入的IN_level设置类内参数lvMode、maxNumOfElem、numOfExpression、maxiumOfValue
{
	switch (lvMode)
	{
	case lv_easy:	//小学生模式，此难度下四则运算数值仅为个位数，且无括号，表达式内运算数值个数为[maxNumOfElem-2,maxNumOfElem)个
	{
		maxiumOfValue = 10;
		maxNumOfElem = 4;		//表达式内运算数值或子表达式个数为2-3个
		numOfExpression = 0;
	}break;

	case lv_normal:	//中学生模式，此难度下题目四则运算数值有十位数，至多有一层括号嵌套，表达式内运算数值或子表达式个数为[maxNumOfElem-2,maxNumOfElem)个
	{
		maxiumOfValue = 100;
		maxNumOfElem = 4;		//表达式内运算数值或子表达式个数为2-3个
		numOfExpression = 1;
	}break;

	case lv_hard:	//大学生模式，此难度下题目四则运算数值有百位数，至多有两层括号嵌套，表达式内运算数值或子表达式个数为[maxNumOfElem-2,maxNumOfElem)个
	{
		maxiumOfValue = 1000;
		maxNumOfElem = 4;		//表达式内运算数值或子表达式个数为2-3个
		numOfExpression = 2;
	}break;

	case lv_Hardcore:	//硬核模式，此难度下题目四则运算数值有千位数，至多有三层括号嵌套，表达式内运算数值或子表达式个数为[maxNumOfElem-2,maxNumOfElem)个
	{
		maxiumOfValue = 10000;
		maxNumOfElem = 5;		//表达式内运算数值或子表达式个数为3-4个
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
	p = (pGenNode)malloc(sizeof(GenNode));
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

Status clExamGen::CreateBiTree(pGenNode &pFather, int times)	//以pFather为表达式节点，递归生成子试题二叉树，传参times为递归计数
{
	if (times < 0)	//传参判断，times<0为异常，返回错误枚举值
	{
		cout << "CreatBiTree:times < 0 ,recursion failed!" << endl;
		return en_fail;
	}
	else if (!pFather)	//传参判断，pFather为空指针时判断为异常，返回错误枚举值
	{
		cout << "CreatBiTree:pFather is a nullptr,function failed" << endl;
		return en_nullptr;
	}

	int i;
	pGenNode pNode;								//存储当前操作的节点地址
	pGenNode pLast;								//存储上一个操作的节点地址
	bool nodeIsElem;							//存储当前节点的随机元素标识
	Symbol nodeSymbol;							//存储当前节点的随机符号枚举变量
	ValueType nodeValue;						//存储当前节点的随机运算数值
	unsigned int numOfElem = maxNumOfElem - 2 + rand() % 2;	//存储当前表达式链表中的节点数
	
	pLast = NULL;

	for (i = 0; i < numOfElem; ++i)
	{
		//动态申请当前节点内存空间
		if (en_success != GetNode(pNode))	
		{
			cout << "CreateBiTree:GetNode failed!" << endl;
			return en_fail;
		}

		//节点类型决定环节，若已递归至最底层(times == 0)则表达式内所有节点均为数值节点，否则将随机决定当前节点为运算数值节点还是子表达式节点
		if (0 == times)
		{
			nodeIsElem = true;
		}
		else
		{
			//随机决定当前节点为运算数值节点还是子表达式节点
			nodeIsElem = rand() % 2;
		}

		//当前节点的赋值操作
		if (nodeIsElem == true)	//当前节点为运算数值节点时，运算符号不限
		{
			GetRandom(nodeValue, 1, maxiumOfValue);
			nodeSymbol = (Symbol)(rand() % 4);		//随机生成 +、-、*、/运算符号
			SetNode(pNode,
				true,
				false,
				nodeSymbol,
				nodeValue,
				pLast,
				NULL);

		}
		else					//当前节点为子表达式节点时，运算符号不限
		{
			nodeSymbol = (Symbol)(rand() % 4);		//随机生成 +、-、*、/运算符号
			SetNode(pNode,
				false,
				false,
				nodeSymbol,
				0,
				pLast,
				NULL);
			if (en_success != CreateBiTree(pNode, times - 1))	//以pNode为头节点，递归生成试题二叉树，传参times-1为递归次数
			{
				cout << "CreateBiTree: Create son tree failed!" << endl;
				return en_fail;
			}
		}
		pLast = pNode;
	}
	pFather->expressionHead = pNode;	//将pFather对应节点的子表达式指针指向pNode，至此pFather的子试题树生成完毕
	pFather->expressionHead->nodeSymbol = sym_plus;	//将子表达式中头节点符号置为加号

	return en_success;
}