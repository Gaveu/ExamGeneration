# ExamGeneration

由[@Chernobyl](https://github.com/Pryriat)与[@-Gaveu](https://github.com/Gaveu)合力完成的四则运算题目与答案生成程序，难度可控，刷题体验良好。

详细的代码文档说明可参考仓库下blog目录内的Blog.md

~~妈妈再也不用担心我的学习~~

## 进展

实现了题目生成、计算、查重、问题与答案本地文件存储、对错判断的功能。当前项目工作基本完成。

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
