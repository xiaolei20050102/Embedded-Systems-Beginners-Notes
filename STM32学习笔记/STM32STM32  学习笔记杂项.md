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







## 关于上拉输入和下拉输入

------

- 

    **默认状态（悬空）**：当输入引脚**什么都不接**时，它的状态完全由您软件配置的**内部上拉或下拉电阻**决定。就像一辆停在坡上的车，您拉了手刹（上拉）它就不会溜车。

- 

    **强外部驱动**：当您用一个**稳定的外部信号源**（如直接接 `GND`或 `VCC`）驱动该引脚时，这个外部信号的驱动能力远强于内部微弱的上拉/下拉电阻。因此，**外部信号会覆盖内部电阻的效果**，引脚的电平将由外部信号决定。就像您用力推那辆停了手刹的车，它依然会被推动。

**简单来说：软件配置的上拉/下拉只决定了“没人说话时听谁的”；而一旦外部有个“大嗓门”明确发声，大家就都会听它的。**

这个设计保证了电路的稳定性和灵活性，是所有单片机输入设计的基础。





## 关于推挽输出和开漏输出

------

- 推挽输出，输出1（高电平）——> 输出高电平，输出0（低电平）——> 输出低电平。
- 开漏输出，输出1（高电平）——> 高电平断开（成高阻）,输出0（低电平）——> 输出低电平。

