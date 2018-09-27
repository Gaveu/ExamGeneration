#pragma once
#include<string>
#include<iostream>
#include<vector>
#include <cctype>
using namespace std;
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
	vector<string> split(string str, const string& find_pattern = " ");//分割字符串
	vector<struct Node*> analyzed();//算式分析，返回临时节点数组
	struct Node* createNode(const string& in_str, const unsigned int pri);//创建节点
	struct Node* caculate_process(struct Node* left, struct Node* right, char sign);//先序遍历计算函数
	void caculate(struct Node* head);//计算具体实现
	void destory_tree(struct Node* p);//销毁生成树
	unsigned int measure(unsigned int x, unsigned int y);//计算最大公因数
	void start_process(string equation);//启动计算过程
};


void caculator::output_equation()
{
	/*
	输入函数
	参数：无
	返回值：输入的等式
	*/
	cout << " = ";
	if (this->result->up_num%this->result->button_num == 0)
		cout << this->result->up_num / this->result->button_num;
	else
		cout << this->result->up_num << "/" << this->result->button_num;
	cout << endl;
}

unsigned int caculator::tonum(const string& in)
{
	/*
	将字符串转为数字
	传入参数：数字字符串
	返回值:字符串对应的无符号整数
	*/
	unsigned int result = 0;
	for (auto x : in)
		result = result * 10 + (x - '0');
	return result;
}

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
		if (x._Equal("=") || x._Equal(" ") || x.size() == 0)
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
			rtn.push_back(createNode(x, 0));
	}
	return rtn;
}

struct Node* caculator::createNode(const string& in_str, const unsigned int pri = 0)
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
			string up_num_2 = in_str.substr(dot_pos + 1, pos - dot_pos - 1);
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
for (; pos != end; pos++)
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

struct Node* caculator::createTree(const vector<struct Node*>& items, unsigned int begin, unsigned int end)
{
	/*
	创建算式的计算树
	传入参数：节点序列
	返回值：树根节点
	*/
	if (end - begin == 3)//递归终点，直接构建子树
	{
		items[begin + 1]->left = items[begin];
		items[begin + 1]->right = items[begin + 2];
		return items[begin + 1];
	}

	vector<struct Node*>::size_type pos = find_last(items, begin, end);

	if (pos == begin + 1)//符号位于开头，左临界状态。左子树为数字，右子树进行递归生成
	{
		items[pos]->left = items[begin];
		items[pos]->right = createTree(items, pos + 1, end);
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

struct Node* caculator::caculate_process(struct Node* left, struct Node* right, char sign)
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

void caculator::caculate(struct Node* head)
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

void caculator::destory_tree(struct Node* p)
{
	/*
	资源释放函数
	传入参数：树根节点
	返回值：无
	*/
	if (!p)
		return;
	if (p->left)
		destory_tree(p->left);
	if (p->right)
		destory_tree(p->right);
	delete p;
	p = NULL;
}

unsigned int caculator::measure(unsigned int x, unsigned int y)
{
	if (x == 1 || y == 1)
		return 1;
	int z = y;
	while (x%y != 0)
	{
		z = x % y;
		x = y;
		y = z;
	}
	return z;
}

void caculator::start_process(string equation)
{
	this->equation = equation;
	destory_tree(this->result);
	this->tmp_res = this->analyzed();
	this->result = this->createTree(this->tmp_res, 0, this->tmp_res.size());
	this->caculate(this->result);
	unsigned int up = this->result->up_num;
	unsigned int down = this->result->button_num;
	if (down == 0)
		this->result->re_granted = true;
	else if (up % down)
	{
		unsigned int div = this->measure(down, up%down);
		if (up > down)
			this->final_result = to_string(up / down) + "'" + to_string((up%down) / div) + "/" + to_string(down / div);
		else
			this->final_result = to_string(up / div) + "/" + to_string(down / div);
	}
	else
		this->final_result = to_string(up / down);
}




