[TOC]

# ExamGeneration

由[@Chernobyl](https://github.com/Pryriat)与[@-Gaveu](https://github.com/Gaveu)合力完成的四则运算题目与答案生成程序，难度可控，刷题体验良好。

~~妈妈再也不用担心我的学习~~



## 进展

实现了题目生成、计算、查重、问题与答案本地文件存储、对错判断的功能。目前进行收尾。

- 修复了漏显第一题的bug

- 修复了`-n` `-r`单独使用时报错的bug，添加了部分默认规则。`-n` 下默认生成数值10以内的题目,`-r`默认生成10道题目

- 修复了`opt_handler.h`中的逻辑错误

- 新增无控制台输出头文件`opt_handler_simplify.h`，用于测试纯后台运算速度

- 改进了题目字符串化的算法

- 添加了查重模块，对应文件`StrRepeatCheck.h`、`StrRepeatCheck.cpp`



## 功能

ExamGeneration.exe -n 20 		//生成20道数值为10以内的题目，题目与答案存放在程序同目录下的Exercises.txt文件与Answers.txt文件中

ExamGeneration.exe -r 50			//生成10道数值为50以内的题目，题目与答案存放在程序同目录下的Exercises.txt文件与Answers.txt文件中

ExamGeneration.exe -n 10 -r 50	//生成10道数值为50以内的题目，题目与答案存放在程序同目录下的Exercises.txt文件与Answers.txt文件中

ExamGeneration.exe -e Exercises.txt -a Answers.txt	//根据Exercises.txt中的题目，验证Answers.txt中的答案，分别列出正确与错误的题目数目和标号



## 调用示例

- 生成10道运算数值最大值为20的题目及计算其答案，并分别存放在程序同目录下的Exercises.txt文件与Answers.txt文件中：

```powershell
.\ExamGeneration.exe -n 10 -r 20
```

​	运行结果：

```powershell
1.  ( 2`9/10 * 8`4/6 ) - 6`1/8 = 19'1/120
2.  5`1/4 + ( 8/9 / 4`1/2 ) = 5'145/324
3.  7`1/3 * ( 7 + 7 ) = 102'2/3
4.  2/9 + ( 6 / 3 ) = 2'2/9
5.  5 * 4`6/8 - 9 = 14'3/4
6.  9`1/5 + ( 1`8/10 / 9 ) = 9'2/5
7.  ( 2`2/7 * 6`1/3 ) * 1`7/9 = 25'139/189
8.  2 + ( 7`5/7 - 7`1/5 ) = 2'18/35
9.  8 / ( 3`3/9 / 7 ) = 16'4/5
10.  1 * ( 2 + 3 ) = 5
Press any key to continue . . .
```



- 验证本地的Exercises.txt题目与Answers.txt中的答案：

```powershell
ExamGeneration.exe -e .\Exercises.txt -a .\Answers.txt
```

​	运行结果：

```powershell
Correct: 10 ( 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 )
Error: 0 ( )
```



## PSP表格

Chernobyl：

| **PSP2.1**                              | **Personal Software Process Stages**    | **预估耗时（分钟）** | **实际耗时（分钟）** |
| --------------------------------------- | --------------------------------------- | -------------------- | -------------------- |
| Planning                                | 计划                                    | 10                   | 30                   |
| · Estimate                              | · 估计这个任务需要多少时间              | 10                   | 30                   |
| Development                             | 开发                                    | 410                  | 450                  |
| · Analysis                              | · 需求分析 (包括学习新技术)             | 30                   | 20                   |
| · Design Spec                           | · 生成设计文档                          | 30                   | 50                   |
| · Design Review                         | · 设计复审 (和同事审核设计文档)         | 30                   | 30                   |
| · Coding Standard                       | · 代码规范 (为目前的开发制定合适的规范) | 0                    | 0                    |
| · Design                                | · 具体设计                              | 60                   | 80                   |
| · Coding                                | · 具体编码                              | 130 |                   |
| · Code Review                           | · 代码复审                              | 30               | 30                   |
| · Test                                  | · 测试（自我测试，修改代码，提交修改）  | 60                  | 60                   |
| Reporting                               | 报告                                    | 60                   | 70                   |
| · Test Report                           | · 测试报告                            | 30                   | 30                   |
| · Size Measurement                      | · 计算工作量                            | 40                | 10                   |
| · Postmortem & Process Improvement Plan | · 事后总结, 并提出过程改进计划          | 20                   | 30                   |
| 合计                                    |                                         | 480                  | 560                  |



-Gaveu：

| **PSP2.1**                              | **Personal Software Process Stages**    | **预估耗时（分钟）** | **实际耗时（分钟）** |
| --------------------------------------- | --------------------------------------- | -------------------- | -------------------- |
| Planning                                | 计划                                    | 30                   | 30                   |
| · Estimate                              | · 估计这个任务需要多少时间              | 600                  | 540                  |
| Development                             | 开发                                    | 350                  | 240                  |
| · Analysis                              | · 需求分析 (包括学习新技术)             | 20                   | 10                   |
| · Design Spec                           | · 生成设计文档                          | 30                   | 50                   |
| · Design Review                         | · 设计复审 (和同事审核设计文档)         | 30                   | 20                   |
| · Coding Standard                       | · 代码规范 (为目前的开发制定合适的规范) | 0                    | 10                   |
| · Design                                | · 具体设计                              | 60                   | 80                   |
| · Coding                                | · 具体编码                              | 200                  | 160                  |
| · Code Review                           | · 代码复审                              | 30                   | 60                   |
| · Test                                  | · 测试（自我测试，修改代码，提交修改）  | 30                   | 40                   |
| Reporting                               | 报告                                    | 60                   | 20                   |
| · Test Report                           | · 测试报告                              | 30                   | 20                   |
| · Size Measurement                      | · 计算工作量                            | 10                   | 10                   |
| · Postmortem & Process Improvement Plan | · 事后总结, 并提出过程改进计划          | 20                   | 30                   |
| 合计                                    |                                         | 900                  | 780                  |



## 结对分工

| 成员                          | 模块                     | 对应文件                             |
| ----------------------------- | ------------------------ | ------------------------------------ |
| Chernobyl（设计、开发、测试） | 计算模块                 | node.h                               |
|                               | 命令行参数处理与执行模块 | opt_handler.h、main.cpp              |
| -Gaveu（开发、测试、文档）    | 题目生成模块             | ExamGen.h、ExamGen.cpp               |
|                               | 计算结果字串查重模块     | StrRepeatCheck.h、StrRepeatCheck.cpp |



## 功能模块详解

### Chernobyl：

#### 流程

![CalculateModulePic01.jpg](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/CalculateModulePic01.jpg)



#### 计算模块

计算模块使用了算式生成树的实现方法，通过递归的方式进行深度优先的遍历实现优先级的分配和计算。每个数值/符号用一个结构体进行存储，结构体定义如下

```cpp
struct Node
{
	bool is_sign;//是否为符号节点
	bool re_granted;//是否重新生成算式  
	unsigned int sign_pri;//符号权重
	char sign;//符号
	unsigned int up_num;//分子值
	unsigned int button_num;//分母值
	struct Node* left;//左子节点
	struct Node* right;//右子节点
};
```

在生成算式树时，相同的节点能够简化实现。

计算类声明如下

```cpp
class caculator
{
public:
	vector<struct Node*> tmp_res;//存储临时构建的节点
	struct Node* result;//存储生成树的根节点
	string equation;//输入的等式
	string final_result;//存储最终结果
	void output_equation();//输出函数
	unsigned int tonum(const string& in);//字符串转为数字
	vector<struct Node*>::size_type find_last(const vector<struct Node*>& items, unsigned int begin, unsigned int end);//寻找临时符号节点中权重最小的节点，返回位置
	struct Node* createTree(const vector<struct Node*>& items, unsigned int begin, unsigned int end);//创建算式生成树
	vector<string> split(string str, const string& find_pattern=" ");//分割字符串
	vector<struct Node*> analyzed();//算式分析，返回临时节点数组
	struct Node* createNode(const string& in_str, const unsigned int pri);//创建节点
	struct Node* caculate_process(struct Node* left, struct Node* right, char sign);//先序遍历计算函数
	void caculate(struct Node* head);//计算具体实现
	void destory_tree(struct Node* p);//销毁生成树
	unsigned int measure(unsigned int x, unsigned int y);//计算最大公因数
	void start_process(string equation);//启动计算过程
};
```

用STL代替传统的数组，在简化代码的同时也能利用内置实现进行计算大量题目时的内存管理分配。

重点函数实现说明

##### 算式字符串处理

使用自实现的分割函数`vector<string> split(string str, const string& find_pattern=" ")`以空格为分隔符进行字符串分割。

```cpp
vector<string> caculator::split(string str, const string& find_pattern)
{
	/*
	字符串分割函数
	传入参数：待分割字符串，分隔符（默认为空格）
	返回值：分割后字符串序列
	*/
	string::size_type pos;
	vector<string> result;
	str += find_pattern;//扩展字符串以方便操作，防止末尾无法匹配
	string::size_type size = str.size();

	for (int i = 0; i < size; i++)
	{
		pos = str.find(find_pattern, i);
		if (pos < size)
		{
			std::string s = str.substr(i, pos - i);//通过内置的substr()实现分割
			result.push_back(s);
			i = pos + find_pattern.size() - 1;
		}
	}
	return result;
}
```

针对每个子字串进行分析，分为三种类型：数值、分数和符号首先对符号和数值进行区分，对符号优先级进行判别

```cpp
vector<struct Node*>  caculator::analyzed()
{
	/*
	算式分析函数
	传入参数：无
	返回值：包含算式所有运算符/数字构成节点的序列
	*/
	vector<string> tmp = split(this->equation);//将传入的字符串进行分割，分隔符为空格
	vector<struct Node*> rtn;
	unsigned int pri = 5;//运算符的基础权重，越靠后权重越小，越靠近于生成树的根。该实现仅支持不多于五个加减乘除符号的四则运算，后续扩展可增大该权重的值
	for (string x : tmp)
	{
		if (x._Equal("=")||x._Equal(" ")||x.size() == 0)
			continue;
		if (x._Equal("("))//遇到左括号提高优先级
		{
			pri += 20;
			continue;
		}
		else if (x._Equal(")"))//遇到右括号降低优先级
		{
			pri -= 20;
			continue;
		}

		if (x._Equal("*") || x._Equal("/"))//乘/除优先级高于加/减
		{
			pri += 10;
			rtn.push_back(createNode(x, pri));
			pri -= 11;
		}

		else if (x._Equal("+") || x._Equal("-"))
		{
			rtn.push_back(createNode(x, pri));
			pri -= 1;
		}

		else
			rtn.push_back(createNode(x,0));
	}
	return rtn;
}

```

生成结点时，根据结点的类型分为数值和符号结点，数值结点统一化成分数形式以便实现分数功能和计算

```cpp
struct Node* caculator::createNode(const string& in_str, const unsigned int pri=0)
{
	/*
	节点创建函数
	传入参数：符号/数字字符串，节点权重
	返回值：根据传入参数生成的节点
	*/
	struct Node* tmp = new Node;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->re_granted = false;
	if (in_str._Equal("*") || in_str._Equal("/") || in_str._Equal("+") || in_str._Equal("-"))//创建符号节点
	{
		tmp->is_sign = true;
		tmp->sign_pri = pri;
		tmp->sign = in_str[0];
		tmp->button_num = 0;
		tmp->up_num = 0;
		return tmp;
	}
	string::size_type pos = in_str.find('/');
	if (pos != string::npos)//分式
	{
		string::size_type dot_pos = in_str.find('`');
		if (dot_pos != string::npos)//假分式
		{
			string up_num_1 = in_str.substr(0, dot_pos);
			string up_num_2 = in_str.substr(dot_pos+1, pos-dot_pos-1);
			string down_num = in_str.substr(pos + 1);
			tmp->button_num = tonum(down_num);
			tmp->up_num = tonum(up_num_1)*tmp->button_num + tonum(up_num_2);
		}
		else
		{
			string up_num = in_str.substr(0, pos);
			string down_num = in_str.substr(pos + 1);
			tmp->up_num = tonum(up_num);
			tmp->button_num = tonum(down_num);
		}
		tmp->is_sign = false;
		tmp->sign = '\0';
		return tmp;
	}
	else//数字
	{
		tmp->up_num = tonum(in_str);
		tmp->button_num = 1;
		tmp->is_sign = false;
		tmp->sign = '\0';
	}
	return tmp;
}
```



##### 计算过程

对容器内结点进行迭代，根据结点的权重生成计算树。首先取出结点容器总权重最小的作为树的根节点

```cpp
vector<struct Node*>::size_type caculator::find_last(const vector<struct Node*>& items, unsigned int begin, unsigned int end)
{
	/*
	寻找节点序列中权重最小符号的位置
	传入参数：节点序列
	返回值：权重最小符号节点的位置
	*/;
	vector<struct Node*>::size_type rtn_pos = 0;
	vector<struct Node*>::size_type pos = begin;
	unsigned int pri = 999;
	for (;pos!=end;pos++)
	{
		if (!items[pos]->is_sign)
			continue;
		if (items[pos]->sign_pri < pri)
		{
			pri = items[pos]->sign_pri;
			rtn_pos = pos;
		}
	}
	return rtn_pos;
}
```

使用递归的方式构建子树，注意三种情况：左临界，右临界和两边空余

```cpp
struct Node* caculator::createTree(const vector<struct Node*>& items,unsigned int begin, unsigned int end)
{
	/*
	创建算式的计算树
	传入参数：节点序列
	返回值：树根节点
	*/
	if (end - begin == 3)//递归终点，直接构建子树
	{
		items[begin+1]->left = items[begin];
		items[begin+1]->right = items[begin+2];
		return items[begin+1];
	}

	vector<struct Node*>::size_type pos = find_last(items,begin,end);

	if (pos == begin + 1)//符号位于开头，左临界状态。左子树为数字，右子树进行递归生成
	{
		items[pos]->left = items[begin];
		items[pos]->right = createTree(items,pos + 1,end);
		return items[pos];
	}

	if (pos == end - 2)//符号位于末尾，右临界状态。右子树为数字，左子树进行递归生成
	{
		items[pos]->right = items[pos + 1];
		items[pos]->left = createTree(items, begin, begin + pos);
		return items[pos];
	}

	else//运算符处于中间，左右都有高优先运算符。对左右子树进行递归生成
	{
		items[pos]->left = createTree(items, begin, begin + pos);
		items[pos]->right = createTree(items, begin + pos + 1, end);
		return items[pos];
	}
}
```

计算时，对算式生成树进行深度优先遍历以实现运算符优先级

```cpp
void caculator :: caculate(struct Node* head)
{
	/*
	使用深度优先先序遍历计算等式
	传入参数：树根节点
	返回值:无，但是会修改树根节点的类型
	*/
	if (head->left->is_sign)
		caculate(head->left);
	if (head->right->is_sign)
		caculate(head->right);
	Node* tmp = caculate_process(head->left, head->right, head->sign);
	if (tmp == NULL)
	{
		cout << "Caculate Failed!";
		return;
	}
	head->up_num = tmp->up_num;
	head->button_num = tmp->button_num;
	head->is_sign = false;
	head->sign = '\0';
	head->re_granted = tmp->re_granted;
	delete tmp;
	return;
}
```

递归的重点为左右子树均不为符号结点，组成为数值+符号+数值。计算后需要修改符号结点类型为数值结点，同时修改符号结点的数值

```cpp
struct Node* caculator :: caculate_process(struct Node* left, struct Node* right, char sign)
{
	/*
	处理叶子节点的计算
	传入参数：左子节点，右子节点，计算符号
	返回值：包含计算结果的数值节点
	*/
	if (left->is_sign || right->is_sign)//若该节点的子节点非数字，则报错
	{
		cout << "Node Error!" << endl;
		return NULL;
	}

	//初始化操作
	struct Node* tmp_struct = new Node;
	unsigned int tmp_result_up = 0;
	unsigned int tmp_result_button = 0;
	unsigned int tmp_left_up = left->up_num;
	unsigned int tmp_left_button = left->button_num;
	unsigned int tmp_right_up = right->up_num;
	unsigned int tmp_right_button = right->button_num;
	unsigned int tmp = 0;
	tmp_struct->is_sign = false;
	tmp_struct->left = NULL;
	tmp_struct->right = NULL;
	tmp_struct->re_granted = false;
	if (left->re_granted || right->re_granted)
		tmp_struct->re_granted = true;

	//通分
	tmp_left_up *= tmp_right_button;
	tmp_right_up *= tmp_left_button;
	tmp = tmp_left_button;
	tmp_left_button *= tmp_right_button;
	tmp_right_button *= tmp;

	//计算
	switch (sign)
	{
	case '+':
		tmp_result_up = tmp_left_up + tmp_right_up;
		tmp_result_button = tmp_left_button;
		break;

	case '-':
		if (tmp_left_up < tmp_right_up)
			tmp_struct->re_granted = true;
		tmp_result_up = tmp_left_up - tmp_right_up;
		tmp_result_button = tmp_left_button;
		break;

	case '*':
		tmp_result_up = left->up_num * right->up_num;
		tmp_result_button = left->button_num * right->button_num;
		break;

	case '/':
		tmp_result_up = left->up_num * right->button_num;
		tmp_result_button = left->button_num * right->up_num;
		break;
	}

	//赋值并返回
	tmp_struct->up_num = tmp_result_up;
	tmp_struct->button_num = tmp_result_button;
	return tmp_struct;
}
```

##### 结果处理

计算完成后，树根结点存储了计算的结果，同时包含了错误信息。后续结果输出时直接对该结点进行信息读取和处理即可

```cpp
	unsigned int up = this->result->up_num;
	unsigned int down = this->result->button_num;
	if (down == 0)//分母为0，重新生成算式
		this->result->re_granted = true;
	else if (up % down)//分子除以分母无法除尽，进行转换
	{
		unsigned int div = this->measure(down, up%down);//求最大公因数
		if (up > down)//转化为假分数
			this->final_result = to_string(up / down) + "'" + to_string((up%down)/div) + "/" + to_string(down/div);
		else//真分数
			this->final_result = to_string(up/div) + "/" + to_string(down/div);
	}
	else//整数
		this->final_result = to_string(up / down);
```



#### 命令行参数处理与执行模块

##### 参数处理

将程序执行的`main`函数声明为`main(int argc, char** argv)`后，可以获取到命令行的参数信息。随后，将信息传入到命令行参数处理类。处理类`opt_handler`声明如下

```cpp
class opt_handler
{
public:
	int argc=0;
	char** argv=0;
	unsigned int problem_num=10;//生成题目个数
	unsigned int problem_size=10;//生成题目最大数值
	string exercisefile = "./Exercises.txt";//输出的练习文件
	string answerfile = "./Answers.txt";//读取的答案文件
	opt_handler(int argc, char** argv);
	void help();
	unsigned int to_num(char* in);//将字符转换为数字
	void opt_handler_process();//参数处理与执行
	void generate_problems();//生成题目
	void compare();//答案比对
};
```

参数处理函数如下，根据传入的不同参数执行不同的行为

```cpp
void opt_handler::opt_handler_process()
{
	if (this->argc == 1)
	{
		help();
		return;
	}
	bool is_judge = false;
	bool is_generate = false;
	for (int pos = 0; pos < this->argc; pos++)
	{
		if (!strncmp(this->argv[pos], "-h", 2))
		{
			help();
			return;
		}
		if (!strncmp(this->argv[pos], "-n", 2))//生成题目个数
		{
			if (this->argc-1 > pos &&  isdigit(this->argv[pos + 1][0]))
				this->problem_num = this->to_num(this->argv[pos + 1]);
			else
				this->problem_num = 10;
			is_generate = true;
			continue;
		}
		else if (!strncmp(this->argv[pos], "-r", 2))//题目数值范围
		{
			if (this->argc-1 > pos && isdigit(this->argv[pos + 1][0]))
				this->problem_size = this->to_num(this->argv[pos + 1]);
			else
				this->problem_size = 10;
			is_generate = true;
			continue;
		}
		else if (!strncmp(this->argv[pos], "-e", 2))//题目文本文件
		{
			this->exercisefile = this->argv[pos + 1];
			continue;
		}
		else if (!strncmp(this->argv[pos], "-a", 2))//题目答案文件
		{
			this->answerfile = this->argv[pos + 1];
			is_judge = true;
			continue;
		}
	}
	if (is_generate)
		this->generate_problems();
	if (is_judge)
		this->compare();
	else if (!is_generate && !is_judge)
		help();
}
```

喜闻乐见的帮助页面

```cpp
void opt_handler::help()
{
	cout << "小学生暑假杀手  充实暑假时光" << endl;
	cout << "使用方法：" << endl;
	cout << " -n: 控制生成题目的个数" << endl;
	cout << " -r: 控制题目中数值" << endl;
	cout << " -e: 题目文件" << endl;
	cout << " -a: 答案文件"<<endl;
	return;
}
```

##### 题目生成

题目生成过程需要进行两个操作：题目生成与计算。生成后需要通过计算判断算式有无异常，如无异常，则将题目与算式输出至不同的文件

```cpp
void opt_handler::generate_problems()
{
	clExamGen *p = new clExamGen();
	caculator* q = new caculator();
	ofstream Answer_File;
	ofstream Exercise_File;
	Answer_File.open(this->answerfile,ios::out| ios::trunc);//创建答案文件
	Exercise_File.open(this->exercisefile, ios::out | ios::trunc);//创建题目文件
	if (!Answer_File.is_open() || !Exercise_File.is_open())
	{
		cout << "文件创建失败";
		return;
	}
	string sCout;
	string sCal;
	int lv = lv_UserDefine;
	for (unsigned int x = 1; x < this->problem_num+1; x++)//题目生成
	{
		p->CreateExamToString1(lv_UserDefine, sCout, sCal, this->problem_size, this->problem_size, this->problem_size, 3, 1);
		q->start_process(sCal);
		if (q->result->re_granted)
		{
			x--;
			continue;
		}
		cout << to_string(x)<< ". "<<sCout << " = " << q->final_result << endl;
		Exercise_File << to_string(x)<<". "<<sCout << " = " << endl;
		Answer_File<< to_string(x) << ". " << q->final_result << endl;
	}
	cout << "generate " << this->problem_num << " problems"<<endl;
	delete p, q;
	return;
}
```

##### 答案判断

答案判断首先需要同步读取答案和题目文件，然后将题目字符串放入计算模块得出结果，并将结果与答案进行比对

```cpp
void opt_handler::compare()
{
	vector<unsigned int>correct, error;
	caculator* q = new caculator();
	ifstream AnswerFile;
	ifstream ExerciseFile;
	AnswerFile.open(this->answerfile);//打开答案文件
	ExerciseFile.open(this->exercisefile);//打开题目文件
	if (!AnswerFile.is_open() || !ExerciseFile.is_open())
	{
		cout << "文件不存在";
		return;
	}
	string ans, exe;
	unsigned int current_problem_num = 0;
	while (!AnswerFile.eof() && !ExerciseFile.eof())//读取文件内容
	{

		current_problem_num++;
		getline(AnswerFile, ans);
		getline(ExerciseFile, exe);
		unsigned int pos = ans.find('.');
		if (pos != string::npos)
			ans = ans.substr(pos + 2);
		else
			break;
		pos = exe.find('.');
		exe = exe.substr(pos + 1);
		q->start_process(exe);
		ans._Equal(q->final_result) ? correct.push_back(current_problem_num) : error.push_back(current_problem_num);//结果判定
	}
	
	cout << "Correct: "<<correct.size()<<" (";
	for (unsigned int x = 0; x < correct.size(); x++)
	{
		if (x == 0)
			cout << " " << correct[x];
		else
			cout << ", " << correct[x];
	}
	cout << " )"<<endl;

	cout << "Error: " << error.size() << " (;
	for (unsigned int x = 0; x < error.size(); x++)
	{
		if (x == 0)
			cout << " " << error[x];
		else
			cout << ", " << error[x];
	};
	cout << " )" << endl;
	delete q;
	return;
}
```

### -Gaveu：

#### 题目生成模块

##### 主数据结构

- 运行状态枚举值定义：

```c++
typedef enum 
{ 
	en_success = 0, 
	en_fail, 
	en_true, 
	en_false, 
	en_nullptr 
}Status;	//Status状态变量定义，用于表明运行状态，常作为函数返回值。
```



- 以二叉树为基础的随机题目生成树。

```c++
typedef struct GenNode
{
	bool isElem;			//标识当前二叉树节点是否为运算数值，若为表达式则值为false
	bool isExpressionHead;	//标识当前二叉树节点是否为运算表达式的第一个元素
							//是的话该值为true，nodeSymbol不能为sym_multiply或sym_divide
							//否则值为false，nodeSymbol取值不限。
    
	bool isFraction;		//标识当前运算数值是否为真分数，是则为true，否则为false

	Symbol nodeSymbol;		//表示当前二叉树节点的运算符号类型
	ValueType value;		//表示当前二叉树节点的运算值，若为表达式，则值为0
	ValueType molecular;	//表示当前二叉树节点的真分数分子
	ValueType denominator;	//表示当前二叉树节点的真分数分母

	GenNode *nextElem;		//指向下一个运算数值节点的指针，若为NULL则说明已至当前表达式的末尾
	GenNode *expressionHead;//指向下一个运算表达式节点的指针，若为NULL则说明当前节点为数值节点
}GenNode, *pGenNode;
```

示例图：

![picture01](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/picture01.png)

- 题目随机生成类`clExamGen`定义：

```c++
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
```



##### 题目生成算法

深度优先，随机生成运算符号与数值，流程可见流程图：

![picture02](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/picture02.png)

具体实现代码：

```C++
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
```



##### 题目二叉树字符串化算法

同样的，深度优先的遍历规则，遇头节点则不显示符号，节点为子表达式节点则增加“ ( 表达式 )”，同时递归进入子表达式中；节点为运算数值节点则判断是否为分数，为分数则增加” value\`molecular/denominator“(value为0时增加” molecular/denominator“)，为自然数则增加” value“。运算数值（包括分数）、子表达式、运算符号彼此用空格相隔以示独立。

```c++
void clExamGen::BiTreeInfoIntoString1(pGenNode pFather, string &dstCal, string &dstCout)	//将试题的信息输入至dstCal(真分数转换)、dstCout(无真分数转换)对应字符串中
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
```



#### 计算结果字串查重模块

##### 主数据结构

`std::map<string,int>`

##### 原理

以计算结果的`string`字串为索引，以当前生成题目的`int`型题号作为键值，建立一个映射计算结果与题号的`map`类。在生成题目后，模块会将该题答案(`string`字串)传入`map`中进行检索，若`map`中不存在该索引则将答案与题号添加入`map`中；若已存在，则模块的接口函数将返回一个`false`，让程序重新生成一道题目。

##### 字串查重类的具体代码定义

```c++
class clStrRepeatCheck
{
public:
	map<string, int> checkMap;				//存储string-int的字串查重map类
	map<string, int>::iterator mapIt;		//字串查重map类迭代器

	bool StrCheckAndAdd(string &s, int IN_Num);		//检查传入字串是否存在于checkMap中，不存在则将该字串及对应的int型标号插入checkMap中，返回true；
													//如果传入的IN_Num小于等于0或者字串存在则不操作并返回false。
	int isInMap(string &s);		//检查传入字串是否存在于checkMap中，是则返回其对应的int值，不存在则返回0
};
```

##### 具体方法实现代码

```c++
bool clStrRepeatCheck::StrCheckAndAdd(string &s, int IN_Num)		
//检查传入字串是否存在于checkMap中，不存在则将该字串及对应的int型标号IN_Num插入checkMap中，返回true；
//如果传入的IN_Num小于等于0或者字串存在则不操作并返回false。
{
	//传入的IN_Num小于等于0，则返回false
	//若s在checkMap中被查找到对应的int值，则返回false
	if (IN_Num <= 0 || isInMap(s) != 0)
	{
		return false;
	}

	//运行到此处则说明s在checkMap中并无重复，此时以s为索引，将对应的int标号IN_Num作为键值加入checkMap中
	checkMap[s] = IN_Num;
	return true;
}

int clStrRepeatCheck::isInMap(string &s)
//检查传入字串是否存在于checkMap中，是则返回其对应的int值，不存在则返回0
{
	mapIt = checkMap.find(s);
	if (mapIt != checkMap.end())
	{
		return mapIt->second;
	}
	else
	{
		return 0;
	}
}
```



## 运行测试

### -Gaveu：

* 分别测试生成10到数值范围为10的题目、生成10到数值范围为20的题目、生成20到数值范围为20的题目：

  ![TestPic01](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TestPic01.png)



此时程序同目录下存有了试题文件Exercises.txt、答案文件Answers.txt，且答案题目均无重复：

  ![TestPic01-1](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TestPic01-1.png)

  ![TestPic02](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TestPic03.png)

  ![TestPic02](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TestPic02.png)



- 组合`-a` `-e`进行答案验证：

  ![TestPic04](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TestPic04.png)

修改Answer.txt中的第4题和第19题答案为0并保存修改：

  ![TestPic05](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TestPic05.png)

再次校验，结果显示第4题和第19题答案错误，符合预期：

  ![TestPic06](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TestPic06.png)

- 10000道运算数值范围为20的题目生成测试：

  ![TestPic07](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TestPic07.png)

  ![TestPic08](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TestPic08.png)


本地Answers.txt与Exercises.txt头与末尾，符合需求:

  ![TestPic09](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TestPic09.png)

  ![TestPic10](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TestPic10.png)

### Chernobyl：

两次生成一百万道、数值范围为一万以内的题目耗时：

- 第一次耗时17秒73：

  ![TimeTest01](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TimeTest01.png)

- 第二次耗时22秒55：

  ![TimeTest02](https://github.com/Gaveu/ExamGeneration/blob/master/blog/picture/TimeTest02.png)



## 项目总结与反思

### Chernobyl

通过计算器项目，了解并实践逆波兰算法和二叉树相关的知识。在结对的过程中学习了代码实现的协商与同步，积累的合作项目的经验。

项目闪光点 ：生成100w题仅需要26秒~

结对闪光点：积极沟通，制定了编程规范，接口对接顺利，实现良好。

### -Gaveu

该项目我主要实现的试题的生成与查重模块的设计。之前有过二叉树及其相关算法的练习与实践，所以实现难度不大。耗时多的地方还是在出题的参数的设计与把控上，像括号嵌套层数、数值大小、真分数设计、括号内运算单元数目多少等，文档中还表明不应当有负数运算。可没有负数运算的四则运算还算是四则运算？按照一切遵循需求的原则，将负数判断的环节交给@Chernobyl了，因为这个涉及到计算。

项目存在的可能的优化点：由于运算模块基于二叉树，题目生成的模块也是基于二叉树，如若前期能商讨出一套方案使得运算模块与题目生成模块能共用同一棵二叉树，时间的开销应该会更小。如今要尝试该优化的话需要重构代码，时间与精力成本较大。

总的而言，这次的项目不仅在开发能力上有所锻炼，在团队沟通分工协作方面也有收获良多。

完成项目后心情是自由自在，毕竟是~~小学生暑假杀手~~小学生四则运算习题库的代码实现，在充实暑假时光的同时也能提升计算能力，是一个十分有意义的项目~~，还能减少假期游戏的小学生队友数目~~，让妈妈再也不用担心孩子的学习！

结对闪光点：很好地实现了将团队与项目中的复杂问题逐步细化与逐一解决的过程，沟通有效，按时完成任务规划。