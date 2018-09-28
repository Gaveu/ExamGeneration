#include "ExamGen.h"

Status clExamGen::GetRandom(ValueType &Data, ValueType IN_Minima, ValueType IN_Maxima)	//获取取值区间为[Minima,Maxima)的随机数,将该数传给Data
{
	if (IN_Maxima < IN_Minima)		//取值区间不符合[Minima,Maxima)的输入都进行判错处理
	{
		cout << "GetRandom:Input is illegal.Get the Random failed!" << endl;
		return en_fail;
	}
	Data = (rand() % (IN_Maxima - IN_Minima)) + IN_Minima;	//Data赋值为[Minima,Maxima)内的一个随机数
	return en_success;

}

Status clExamGen::GetRandom1(ValueType &Data, ValueType IN_Minima, ValueType IN_Maxima)	//获取取值区间为[Minima,Maxima)的随机数,将该数传给Data
{
	if (IN_Maxima < IN_Minima)		//取值区间不符合[Minima,Maxima)的输入都进行判错处理
	{
		cout << "GetRandom:Input is illegal.Get the Random failed!" << endl;
		return en_fail;
	}
	Data = (rand() % (IN_Maxima - IN_Minima + 1)) + IN_Minima;	//Data赋值为[Minima,Maxima)内的一个随机数
	return en_success;

}

Status clExamGen::SetLevel(Level IN_level)		//根据传入的IN_level设置类内参数lvMode、maxNumOfElem、numOfExpression、maxiumOfValue
{
	switch (IN_level)
	{
	case lv_easy:	//小学生模式，此难度下四则运算数值仅为个位数，且无括号，表达式内运算数值个数为4个
	{
		maxiumOfValue = 10;
		maxNumOfElem = 4;		//表达式内运算数值或子表达式个数为4个
		numOfExpression = 0;
	}break;

	case lv_normal:	//中学生模式，此难度下题目四则运算数值有十位数，至多有一层括号嵌套，表达式内运算数值或子表达式个数为3个
	{
		maxiumOfValue = 100;
		maxNumOfElem = 3;		//表达式内运算数值或子表达式个数为3个
		numOfExpression = 1;
	}break;

	case lv_hard:	//大学生模式，此难度下题目四则运算数值有百位数，至多有两层括号嵌套，表达式内运算数值或子表达式个数为3个
	{
		maxiumOfValue = 1000;
		maxNumOfElem = 3;		//表达式内运算数值或子表达式个数为3个
		numOfExpression = 2;
	}break;

	case lv_Hardcore:	//硬核模式，此难度下题目四则运算数值有千位数，至多有三层括号嵌套，表达式内运算数值或子表达式个数为4个
	{
		maxiumOfValue = 10000;
		maxNumOfElem = 4;		//表达式内运算数值或子表达式个数为4个
		numOfExpression = 3;
	}break;

	case lv_UserDefine:	//用户自定义模式，由于正常执行用户自定义模式的流程时并不会触发该函数，运行到这里可认为是误操作，输出错误信息并结束该函数的执行
	{
		cout << "SetLevel:Input Error!" << endl;
		cout << "If you want to using UserDefine mode ,please running the other same name function!" << endl;
		return en_fail;
	}break;

	default:
	{
		cout << "SetLevel:Level set failed,the input is illegal!" << endl;
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

Status clExamGen::SetNode(
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
)		//(真分数)设置pNode指向的结构体的值,函数成功则返回en_success;pNode值为空则输出错误信息，返回en_nullptr
{
	if (!pNode)
	{
		cout << "SetNode:pNode is nullptr!GenNode set failed" << endl;
		return en_nullptr;
	}
	if (IN_molecular > IN_denominator)
	{
		cout << "SetNode:molecular is bigger than the denominator!Function error!" << endl;
		return en_fail;
	}

	pNode->isElem = IN_isElem;
	pNode->isExpressionHead = IN_isExpressionHead;
	pNode->isFraction = IN_isFraction;
	pNode->nodeSymbol = IN_nodeSymbol;
	pNode->value = IN_value;
	pNode->molecular = IN_molecular;
	pNode->denominator = IN_denominator;
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

	pGenNode pNode;								//存储当前操作的节点地址
	pGenNode pLast;								//存储上一个操作的节点地址
	bool nodeIsElem;							//存储当前节点的随机元素标识
	bool nodeIsFraction;						//存储当前节点的随机真分数标识
	Symbol nodeSymbol;							//存储当前节点的随机符号枚举变量
	ValueType nodeValue;						//存储当前节点的随机运算数值
	ValueType nodeMolecular;					//存储当前节点的真分数分子
	ValueType nodeDenominator;					//存储当前节点的真分数分母
	//unsigned int numOfElem = maxNumOfElem;		//存储当前表达式链表中的节点数
	int explimit = 2;

	pNode = NULL;
	pLast = NULL;

	while (maxNumOfElem != 0 && explimit)
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
			explimit--;
		}
		else
		{
			//随机决定当前节点为运算数值节点还是子表达式节点
			nodeIsElem = rand() % 2;
		}

		//当前节点的赋值操作
		if (nodeIsElem == false)	//当前节点为子表达式节点时，运算符号不限
		{
			nodeSymbol = (Symbol)(rand() % 4);		//随机生成 +、-、*、/运算符号
			SetNode(pNode,
				false,
				false,
				false,
				nodeSymbol,
				0,
				0,
				0,
				pLast,
				NULL);
			if (en_success != CreateBiTree(pNode, times - 1))	//以pNode为头节点，递归生成试题二叉树，传参times-1为递归次数
			{
				cout << "CreateBiTree: Create son tree failed!" << endl;
				return en_fail;
			}
		}
		else					//当前节点为运算数值节点时，运算符号不限
		{
			nodeIsFraction = rand() % 2;
			if (nodeIsFraction == true && ifFraction == true)		//真分数节点生成
			{
				GetRandom(nodeValue, 0, maxiumOfValue);	//真分数则真数值范围为[0,maxiumOfValue)
				GetRandom1(nodeDenominator, 2, maxiumOfDenominator);	//真分数分母取值为[2,maxiumOfMolecular]

				//真分数分子取值为[1,nodeDenominator-1或maxiumOfMolecular的最小者]
				GetRandom1(nodeMolecular, 1, nodeDenominator > maxiumOfMolecular ? maxiumOfMolecular : nodeDenominator - 1);

				nodeSymbol = (Symbol)(rand() % 4);		//随机生成 +、-、*、/运算符号
				SetNode(pNode,
					true,
					false,
					true,
					nodeSymbol,
					nodeValue,
					nodeMolecular,
					nodeDenominator,
					pLast,
					NULL);

			}
			else //真值节点生成
			{
				GetRandom(nodeValue, 1, maxiumOfValue);	//数值范围为[1,maxiumOfValue)
				nodeSymbol = (Symbol)(rand() % 4);		//随机生成 +、-、*、/运算符号
				SetNode(pNode,
					true,
					false,
					false,
					nodeSymbol,
					nodeValue,
					0,
					0,
					pLast,
					NULL);
			}
		}

		pLast = pNode;
		if (0 == maxNumOfElem || 0 == explimit)
		{
			break;
		}
		else
		{
			maxNumOfElem--;
		}
	}
	pFather->expressionHead = pNode;	//将pFather对应节点的子表达式指针指向pNode，至此pFather的子试题树生成完毕
	pFather->expressionHead->nodeSymbol = sym_plus;	//将子表达式中头节点符号置为加号
	pFather->expressionHead->isExpressionHead = true;	//将子表达式中头节点的头节点标识isExpressionHead置为true

	return en_success;
}

Status clExamGen::DeleteBiTree(pGenNode &pFather)		//递归释放二叉树节点空间
{
	if (pFather->expressionHead)
	{
		DeleteBiTree(pFather->expressionHead);
	}
	if (pFather->nextElem)
	{
		DeleteBiTree(pFather->nextElem);
	}
	free(pFather);
	pFather = NULL;
	return en_success;
}

void clExamGen::ShowTree(pGenNode pFather)		//递归输出试题树的信息
{
	if (!pFather)
	{
		return;
	}

	//运算符号显示环节
	if (pFather->isExpressionHead == false)	//非表达式的头节点则显示运算符号
	{
		cout << ' ' << SymbolToChar(pFather->nodeSymbol);	//将当前节点的运算符号枚举值转换为ASCII值，存储至ch_symbol中
	}

	//运算数值或表达式输出环节
	if (pFather->isElem == false)	//节点为表达式节点则显示“ ( 表达式 )”
	{
		cout << ' ' << '(';
		ShowTree(pFather->expressionHead);
		cout << ' ' << ')';
	}
	else	//节点为数值节点时显示运算数值
	{
		cout << ' ' << pFather->value;
	}
	ShowTree(pFather->nextElem);
}

char clExamGen::SymbolToChar(Symbol IN_symbol)	//根据传入的IN_symbol输出对应符号的ASCII
{
	switch (IN_symbol)
	{
	case sym_plus:
	{
		return '+';
	}break;
	case sym_minus:
	{
		return '-';
	}break;
	case sym_multiply:
	{
		return '*';
	}break;
	case sym_divide:
	{
		return '/';
	}break;
	default:
	{
		return '\0';
	}
	}
}

void clExamGen::BiTreeInfoIntoString(pGenNode pFather, string &dst)	//将试题的信息输入至dst对应字符串中
{
	if (!pFather)
	{
		return;
	}

	//运算符号显示环节
	if (pFather->isExpressionHead == false)	//非表达式的头节点则显示运算符号
	{
		dst.insert(dst.size(), 1, ' ');
		dst.insert(dst.size(), 1, SymbolToChar(pFather->nodeSymbol));
	}

	//运算数值或表达式输出环节
	if (pFather->isElem == false)	//节点为表达式节点则显示“ ( 表达式 )”
	{
		dst.insert(dst.size(), " (");
		BiTreeInfoIntoString(pFather->expressionHead, dst);
		dst.insert(dst.size(), " )");
	}
	else	//节点为数值节点时显示运算数值
	{
		dst.insert(dst.size(), 1, ' ');
		if (pFather->value != 0)
		{
			dst.insert(dst.size(), to_string(pFather->value));
		}
		if (pFather->isFraction == true)
		{
			if (pFather->value != 0)
			{
				dst.insert(dst.size(), 1, '`');
			}
			dst.insert(dst.size(), to_string(pFather->molecular));
			dst.insert(dst.size(), 1, '/');
			dst.insert(dst.size(), to_string(pFather->denominator));
		}
	}
	BiTreeInfoIntoString(pFather->nextElem, dst);
}

void clExamGen::BiTreeInfoIntoString1(pGenNode pFather, string &dstCal, string &dstCout)	//(真分数转换)将试题的信息输入至dst对应字符串中
{
	if (!pFather)
	{
		return;
	}

	//运算符号显示环节
	if (pFather->isExpressionHead == false)	//非表达式的头节点则显示运算符号
	{
		dstCal.insert(dstCal.size(), 1, ' ');
		dstCal.insert(dstCal.size(), 1, SymbolToChar(pFather->nodeSymbol));

		dstCout.insert(dstCout.size(), 1, ' ');
		dstCout.insert(dstCout.size(), 1, SymbolToChar(pFather->nodeSymbol));
	}

	//运算数值或表达式输出环节
	if (pFather->isElem == false)	//节点为表达式节点则显示“ ( 表达式 )”
	{
		dstCal.insert(dstCal.size(), " (");
		dstCout.insert(dstCout.size(), " (");
		BiTreeInfoIntoString1(pFather->expressionHead, dstCal, dstCout);
		dstCal.insert(dstCal.size(), " )");
		dstCout.insert(dstCout.size(), " )");
	}
	else	//节点为数值节点时显示运算数值
	{
		dstCal.insert(dstCal.size(), 1, ' ');
		dstCout.insert(dstCout.size(), 1, ' ');
		if (pFather->isFraction == true)
		{
			dstCal.insert(dstCal.size(), to_string(pFather->molecular + pFather->value * pFather->denominator));
			dstCal.insert(dstCal.size(), 1, '/');
			dstCal.insert(dstCal.size(), to_string(pFather->denominator));

			if (pFather->value != 0)
			{
				dstCout.insert(dstCout.size(), to_string(pFather->value));
				dstCout.insert(dstCout.size(), 1, '`');
			}
			dstCout.insert(dstCout.size(), to_string(pFather->molecular));
			dstCout.insert(dstCout.size(), 1, '/');
			dstCout.insert(dstCout.size(), to_string(pFather->denominator));

		}
		else
		{
			dstCal.insert(dstCal.size(), to_string(pFather->value));
			dstCout.insert(dstCout.size(), to_string(pFather->value));
		}
	}
	BiTreeInfoIntoString1(pFather->nextElem, dstCal, dstCout);
}

/*Status clExamGen::CreateExamToString(Level IN_lvmode, string &Out_dst)	//根据传入的试题难度自动生成试题，并将试题字符串化，复制到Out_dst的string引用对象中
{
	if (IN_lvmode < 0 || IN_lvmode > 4)
	{
		cout << "CreateExamToString:Input is illegal!" << endl;
		return en_fail;
	}
	random_device rd;
	srand(rd());
	if (en_success != SetLevel(IN_lvmode))	//设置难度等级
	{
		cout << "SetLevel failed!" << endl;
		return en_false;
	}

	GetNode(genNodeRoot);	//申请根节点空间
	SetNode(genNodeRoot, false, true, sym_plus, 0, NULL, NULL);	//根节点设置为符号为+的表达式节点
	unsigned int tmp = maxNumOfElem;		//临时保存maxNumOfElem
	CreateBiTree(genNodeRoot, numOfExpression);	//以genNodeRoot为根节点生成试题树
	maxNumOfElem = tmp;	//恢复maxNumOfElem备份

	//DeleteOneElemExpression(genNodeRoot, genNodeRoot->expressionHead);

	//cout << "Lv: " << lvMode << endl;
	BiTreeInfoIntoString(genNodeRoot->expressionHead, strExam);
	Out_dst = strExam;
	//cout << Out_dst.c_str() << endl;
	DeleteBiTree(genNodeRoot);	//试题树摧毁结束
	strExam.erase();
}*/

Status clExamGen::CreateExamToString(
	Level IN_lvmode,						//传入的题目生成难度，仅接受自定义难度，其他难度则报错并返回en_fail
	string &Out_dst,						//输出的string类引用，当函数成功生成一道题目时会将其字符串化并输出至该引用对应的对象				
	ValueType IN_maxiumOfValue,				//待生成题目的数值最大值，题目生成参数，若为50,则运算数值范围为[1,50)
	ValueType IN_maxiumOfMolecular,			//待生成题目的真分数分子最大值
	ValueType IN_maxiumOfDenominator,		//待生成题目的真分数分母最大值
	unsigned int IN_numOfElem,				//待生成题目中一个表达式中运算值及子表达式的最大个数
	unsigned int IN_numOfExpression			//待生成题目中的括号嵌套层数
)	//(用户自定义难度)根据传入的试题参数自动生成试题，并将试题字符串化，复制到Out_dst的string引用对象中
{
	if (IN_lvmode != lv_UserDefine || IN_maxiumOfValue < 0 || IN_numOfElem < 0 || IN_numOfExpression < 0)
	{
		cout << "CreateExamToString:Input is illegal!" << endl;
		return en_fail;
	}
	if (IN_maxiumOfDenominator < IN_maxiumOfMolecular)
	{
		cout << "CreateExamToString:maxiumOfMolecular is greater than the maxiumOfDenominator!" << endl;
		return en_fail;
	}

	if (0 == IN_maxiumOfDenominator && 0 == IN_maxiumOfDenominator)	//分子与分母最大值均为0则不生成含真分数的式子
	{
		ifFraction = false;
	}
	else if (IN_maxiumOfDenominator < 2)
	{
		cout << "CreateExamToString:maxiumOfDenominator shouldn't < 2!" << endl;
		return en_fail;
	}
	else if (IN_maxiumOfMolecular < 1)
	{
		cout << "CreateExamToString:maxiumOfMolecular shouldn't < 1!" << endl;
		return en_fail;
	}
	else
	{
		ifFraction = true;
	}
	random_device rd;
	srand(rd());

	//SetLevel(IN_lvmode);		//设置难度等级


	//自定义难度下试题类的参数配置
	maxiumOfValue = IN_maxiumOfValue;
	maxNumOfElem = IN_numOfElem;
	maxiumOfDenominator = IN_maxiumOfDenominator;
	maxiumOfMolecular = IN_maxiumOfMolecular;
	numOfExpression = IN_numOfExpression;

	GetNode(genNodeRoot);	//申请根节点空间
	SetNode(genNodeRoot, false, true, false, sym_plus, 0, 0, 0, NULL, NULL);	//根节点设置为符号为+的表达式节点

	unsigned int tmp = maxNumOfElem;		//临时保存maxNumOfElem
	CreateBiTree(genNodeRoot, numOfExpression);	//以genNodeRoot为根节点生成试题树
	maxNumOfElem = tmp;	//恢复maxNumOfElem备份

	DeleteOneElemExpression(genNodeRoot, genNodeRoot->expressionHead);

	//cout << "Lv: " << lvMode << endl;
	BiTreeInfoIntoString(genNodeRoot->expressionHead, strExam);
	Out_dst = strExam;
	//cout << Out_dst.c_str() << endl;
	DeleteBiTree(genNodeRoot);	//试题树摧毁结束
	strExam.erase();
}

Status clExamGen::DeleteOneElemExpression(pGenNode pLast, pGenNode pNode)	//对于仅含有一个元素的表达式时，进行表达式节点删除操作，类似单链表的中间节点删除
{
	if (!pNode)
	{
		return en_success;
	}

	if (pLast->isElem == false)
	{
		if (pNode->isExpressionHead == true && pNode->isElem == false && pNode->expressionHead && pNode->expressionHead->nextElem == NULL)
		{
			pLast->expressionHead = pNode->expressionHead;
			pLast->expressionHead->nextElem = pNode->nextElem;
			free(pNode);
			pNode = pLast->expressionHead;
		}
	}
	else if (pLast->isElem == true)
	{
		if (pNode->isElem == false && pNode->expressionHead && pNode->expressionHead->nextElem == NULL)
		{
			pLast->nextElem = pNode->expressionHead;
			pLast->nextElem->nextElem = pNode->nextElem;
			free(pNode);
			pNode = pLast->nextElem;
		}
	}

	if (pNode->expressionHead)
	{
		DeleteOneElemExpression(pNode, pNode->expressionHead);
	}

	if (pNode->nextElem)
	{
		DeleteOneElemExpression(pNode, pNode->nextElem);
	}




	/*if (pNode->isElem == false && pNode->isExpressionHead == true && pNode->nextElem == NULL)
	{
		pNode->nextElem = pNode->expressionHead->nextElem;
		pNode->expressionHead->nextElem = pNode->expressionHead->nextElem->nextElem;
		pNode->nextElem->nextElem = NULL;
	}*/

	return en_success;
}

Status clExamGen::CreateExamToString1(
	Level IN_lvmode,						//传入的题目生成难度，仅接受自定义难度，其他难度则报错并返回en_fail
	string &Out_dstCout,					//(无分数转换)输出的string类引用，当函数成功生成一道题目时会将其字符串化并输出至该引用对应的对象		
	string &Out_dstCal,						//(有分数转换)输出的string类引用，当函数成功生成一道题目时会将其字符串化并输出至该引用对应的对象	
	ValueType IN_maxiumOfValue,				//待生成题目的数值最大值，题目生成参数，若为50,则运算数值范围为[1,50)
	ValueType IN_maxiumOfMolecular,			//待生成题目的真分数分子最大值
	ValueType IN_maxiumOfDenominator,		//待生成题目的真分数分母最大值
	unsigned int IN_numOfElem,				//待生成题目中一个表达式中运算值及子表达式的最大个数
	unsigned int IN_numOfExpression			//待生成题目中的括号嵌套层数
)	//(用户自定义难度)根据传入的试题参数自动生成试题，并将试题字符串化，复制到Out_dst的string引用对象中
{
	if (IN_lvmode != lv_UserDefine || IN_maxiumOfValue < 0 || IN_numOfElem < 0 || IN_numOfExpression < 0)
	{
		cout << "CreateExamToString:Input is illegal!" << endl;
		return en_fail;
	}
	if (IN_maxiumOfDenominator < IN_maxiumOfMolecular)
	{
		cout << "CreateExamToString:maxiumOfMolecular is greater than the maxiumOfDenominator!" << endl;
		return en_fail;
	}

	if (0 == IN_maxiumOfDenominator && 0 == IN_maxiumOfDenominator)	//分子与分母最大值均为0则不生成含真分数的式子
	{
		ifFraction = false;
	}
	else if (IN_maxiumOfDenominator < 2)
	{
		cout << "CreateExamToString:maxiumOfDenominator shouldn't < 2!" << endl;
		return en_fail;
	}
	else if (IN_maxiumOfMolecular < 1)
	{
		cout << "CreateExamToString:maxiumOfMolecular shouldn't < 1!" << endl;
		return en_fail;
	}
	else
	{
		ifFraction = true;
	}
	random_device rd;
	srand(rd());

	string sCout;
	string sCal;

	//SetLevel(IN_lvmode);		//设置难度等级


	//自定义难度下试题类的参数配置
	maxiumOfValue = IN_maxiumOfValue;
	maxNumOfElem = IN_numOfElem;
	maxiumOfDenominator = IN_maxiumOfDenominator;
	maxiumOfMolecular = IN_maxiumOfMolecular;
	numOfExpression = IN_numOfExpression;

	GetNode(genNodeRoot);	//申请根节点空间
	SetNode(genNodeRoot, false, true, false, sym_plus, 0, 0, 0, NULL, NULL);	//根节点设置为符号为+的表达式节点

	unsigned int tmp = maxNumOfElem;		//临时保存maxNumOfElem
	CreateBiTree(genNodeRoot, numOfExpression);	//以genNodeRoot为根节点生成试题树
	maxNumOfElem = tmp;	//恢复maxNumOfElem备份

	DeleteOneElemExpression(genNodeRoot, genNodeRoot->expressionHead);

	BiTreeInfoIntoString1(genNodeRoot->expressionHead, sCal, sCout);
	Out_dstCal = sCal;
	Out_dstCout = sCout;


	//cout << Out_dst.c_str() << endl;
	DeleteBiTree(genNodeRoot);	//试题树摧毁结束

}