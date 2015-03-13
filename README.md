# dexFileAnalyze

在学习《安卓逆向分析》一书的dex文件格式时写的一个小工具，因为PE文件结构在PC端是非常重要的，那么想了解安卓下的加壳就必须从代码的角度去分析一下dex文件格式。


### 文件说明： ###
- `test.java`:用与测试dex文件的java源文件
- `test.dex`:用于测试的dex文件，由test.java生成
- `Dex文件解析`目录包含完整代码，在VC6下可以正确运行，用MFC写的
- `Dex文件解析/dex.h`：包含了dex文件解析时用到的各种结构
- `Dex文件解析/Dex文件解析Dlg.cpp`:有用的代码都在这里面


test.java代码：

    class test{
    	public static void main(String[] argc){
    		System.out.println("test!");
    	}
    }



- 实验对ClassDefs的解析如下：

    Start read ClassDefs......
    类名:		Ltest;
    访问权限:	Null
    父类:		Ljava/lang/Object;
    接口:		Null
    源文件名:	test.java
    注释信息:	Null
    
解析了我们定义的类各种信息

- 对method的解析如下：

    Start read Methods......
    class: Ljava/io/PrintStream;  proto: short-form: VL  return_type: V  parameters: Ljava/lang/String;  name: println
    class: Ljava/lang/Object;  proto: short-form: V  return_type: V  parameters: NULL  name: <init>
    class: Ltest;  proto: short-form: V  return_type: V  parameters: NULL  name: <init>
    class: Ltest;  proto: short-form: VL  return_type: V  parameters: [Ljava/lang/String;  name: main

解析出来了一共四个方法：

PrintStream类的println方法、object类的构造函数方法、test类的构造函数方法、class类的test方法。

- 在代码中每一个header的字段都有一个专门用于解析字段的函数，为了解析了一个字段的函数能用于别的字段当中，做了重载，利用了一下C++的特性，果然代码比较简洁了。



    ReadStrings(dex);
    ReadTypes(dex);
    ReadProtos(dex);
    ReadFields(dex);
    ReadMethods(dex);
    ReadClassDefs(dex);



- 对于混淆：

只要把相应的类名，方法名用随机字符替换原来的类名方法名即可。

- 总结：

通过亲自动手做了这个小工具，复习了C++、dex文件的整体结构、以及dex的混淆原理。
