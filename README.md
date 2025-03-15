# cpp_kkksc03
C++练习 kkksc03考前临时抱佛脚


题目背景：
kkksc03 的大学生活非常的颓废，平时根本不学习。但是，临近期末考试，他必须要开始抱佛脚，以求不挂科。

题目描述：
这次期末考试，kkksc03 需要考 $4$ 科。因此要开始刷习题集，每科都有一个习题集，分别有 $s_1,s_2,s_3,s_4$ 道题目，完成每道题目需要一些时间，可能不等（$A_1,A_2,\ldots,A_{s_1}$，$B_1,B_2,\ldots,B_{s_2}$，$C_1,C_2,\ldots,C_{s_3}$，$D_1,D_2,\ldots,D_{s_4}$）。
kkksc03 有一个能力，他的左右两个大脑可以同时计算 $2$ 道不同的题目，但是仅限于同一科。因此，kkksc03 必须一科一科的复习。
由于 kkksc03 还急着去处理洛谷的 bug，因此他希望尽快把事情做完，所以他希望知道能够完成复习的最短时间。

输入格式：
本题包含 $5$ 行数据：第 $1$ 行，为四个正整数 $s_1,s_2,s_3,s_4$。
第 $2$ 行，为 $A_1,A_2,\ldots,A_{s_1}$ 共 $s_1$ 个数，表示第一科习题集每道题目所消耗的时间。
第 $3$ 行，为 $B_1,B_2,\ldots,B_{s_2}$ 共 $s_2$ 个数。
第 $4$ 行，为 $C_1,C_2,\ldots,C_{s_3}$ 共 $s_3$ 个数。
第 $5$ 行，为 $D_1,D_2,\ldots,D_{s_4}$ 共 $s_4$ 个数，意思均同上。

输出格式：
输出一行,为复习完毕最短时间。

思路：
遍历四科，求出每一科的最佳答案。
循环中的函数，因为他的左右脑可以同时工作（什么碳基怪物）所以定义两个数分别叠加，例：1 2 3 4，分别将1 4，2 3放入左脑右脑，得出最优解，而判定方式也很简单，因为可以同时工作，
所以两者间大的那个数就是该方案花费的时间，题目是求最小值，所以打擂台，一开始定义最大数，如果该方案小，将原方案替换。
递归结束条件就是定义一个step，初试为0，意为脑子里存入的题，0代表此时还没有放入题（时间）。
先递左脑，知道递完所有，记录时间，归，此时状态应该是递最后一道题的前一刻，递入右脑，如此反复，知道递完该科目所有的题，也完成了最短时间。
主函数内指向第二科，进入函数。
这里解释一下左右脑分别装入的操作，很抽象。
例如有三道题，直到打擂台之前，题的状态是：左左左，即第一次所有的题都进入了左脑，归，在执行右脑装入时的状态是：左左，继续执行：左左右，如此反复。
针对左右脑的操作可以用二叉树图帮助理解，本题的递归构造与PERKET类似。
用二叉树理解。
