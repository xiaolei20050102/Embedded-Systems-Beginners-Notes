# $STM32$  学习笔记杂项

## 

## 关于在$Keil5$ 里面 新建$STM32$工程

------

1. 打开Keil5在工具栏里面选择Project -> New μVison Project 新建一个工程。

![image-20250912202018140](C:\Users\12272\AppData\Roaming\Typora\typora-user-images\image-20250912202018140.png)

2.根据自己的芯片选择即可

![image-20250912202348846](C:\Users\12272\AppData\Roaming\Typora\typora-user-images\image-20250912202348846.png)

3.工程文件夹下新建一个文件夹Strat里面存放，**基本启动文件**、**外设寄存器描述文件**、**配置时钟的文件**、**内核寄存器描述文件**。

![image-20250912204358054](C:\Users\12272\AppData\Roaming\Typora\typora-user-images\image-20250912204358054.png)

4.工程文件夹下新建一个文件夹Library里面存放，**标准外设驱动文件**（使用库函数编程必备）。

![image-20250912205154395](C:\Users\12272\AppData\Roaming\Typora\typora-user-images\image-20250912205154395.png)

5.工程目录下新建User作为用户文件夹，里面存放**库配置文件**、**中断服务程序源文件**、**中断服务程序头文件**。

![image-20250912205908454](C:\Users\12272\AppData\Roaming\Typora\typora-user-images\image-20250912205908454.png)

6.回到keil里面添加Strat、Library、User组，并且添加相关文件。

![image-20250912210707235](C:\Users\12272\AppData\Roaming\Typora\typora-user-images\image-20250912210707235.png)

7.在Option for Target ‘Target1’（小魔术棒） 中 C/C++  下include Path中添加上述组文件夹的路径。

![image-20250912211052635](C:\Users\12272\AppData\Roaming\Typora\typora-user-images\image-20250912211052635.png)

![image-20250912211222519](C:\Users\12272\AppData\Roaming\Typora\typora-user-images\image-20250912211222519.png)

8.在User组下新建main.c文件，写入测试代码，同时在Option for Target ‘Target1’（小魔术棒） 中 C/C++ Define 栏中添加USE_STDPERIPH_DRIVER 宏定义

![image-20250912211813583](C:\Users\12272\AppData\Roaming\Typora\typora-user-images\image-20250912211813583.png)

9.点击build target files。如果0 error 0 waring 就ok 了。

![image-20250912212020052](C:\Users\12272\AppData\Roaming\Typora\typora-user-images\image-20250912212020052.png)