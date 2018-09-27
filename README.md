# ExamGeneration

由[@Chernobyl](https://github.com/Pryriat)与[@-Gaveu](https://github.com/Gaveu)合力完成的四则运算题目与答案生成程序，可控难度，刷题体验良好。

~~妈妈再也不用担心我的学习~~



## 进展

基本实现了题目生成、计算、问题与答案本地文件存储、对错判断的功能。目前正在测试与误操作方面进行处理打磨。

- 修复了漏显第一题的bug。

- 修复了`-n` `-r`单独使用时报错的bug，添加了部分默认规则。`-n` 下默认生成数值10以内的题目,`-r`默认生成10道题目。

- 修复了`opt_handler.h`中的逻辑错误。


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
| · Analysis                              | · 需求分析 (包括学习新技术)             | 20                   | 20                   |
| · Design Spec                           | · 生成设计文档                          | 30                   | 50                   |
| · Design Review                         | · 设计复审 (和同事审核设计文档)         | 30                   | 20                   |
| · Coding Standard                       | · 代码规范 (为目前的开发制定合适的规范) | 0                    | 10                   |
| · Design                                | · 具体设计                              | 60                   | 80                   |
| · Coding                                | · 具体编码                              | 200                  | 160                  |
| · Code Review                           | · 代码复审                              | 30                   | 60                   |
| · Test                                  | · 测试（自我测试，修改代码，提交修改）  | 30                   | 60                   |
| Reporting                               | 报告                                    | 60                   | 20                   |
| · Test Report                           | · 测试报告                              | 30                   | 20                   |
| · Size Measurement                      | · 计算工作量                            | 10                   | 10                   |
| · Postmortem & Process Improvement Plan | · 事后总结, 并提出过程改进计划          | 20                   | 30                   |
| 合计                                    |                                         | 900                  | 780                  |