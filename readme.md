# C语言笔试题汇总

## 题目列表

[题目列表(clib/readme.md)](clib/readme.md)

此代码只适合在线笔试和学习交流使用。（不会处理一些在在线笔试的时候没有必要处理的错误）
欢迎大家贡献代码。

## 自动代码生成器

首先，安装 nodejs <https://nodejs.org/en/>， 安装过程中要选择安装 npm 模块。打开命令控制台执行以下命令。

    # 全局安装 grunt-cli 只需要安装一次， linux 可能需要管理员权限
    npm install -g grunt-cli 
    
    # clone 此版本库
    git clone https://github.com/zonxin/expandC.git
    # 进入版本库的目录
    cd grunt-expandC
    # 安装依赖模块
    npm install

执行

    make MAIN=demo.c TEST=a/add

会自动编译测试，在 `dest/demo.c` 中生成的就是代码。

### grunt 命令

1. `grunt` 默认命令，自动生产单个可以编译的 `.c` 文件，并且编译测试
5. `grunt add:路径/文件.c` 创建文件生成对应的头文件，同时在testdata中创建一个测试数据文件夹，并且自动把头文件添加到 "main" 指定的文件中。

### make 命令

1. `make build`:生成文件
2. `make t`:默认，编译并测试，利用`T`中的，"test\*in.txt"为测试数据，"test\*out.txt"为对应的结果
3. `make tt`:运行时间测试，根据选项`T`中，"time\*.txt"测试数据

### make 配置

1. `T`:测试数据所在路径，相对于"testdata",默认为"a/same"
1. `MAIN`:main函数所在文件，默认为"main.c"
2. `OUTDIR`:输出编译后代码输出文件夹，默认为"dest"
3. `DIFF`:对比输入输出的程序，默认为"diff"
4. `DFLAGS`:"diff"的参数,默认为"-b"
6. `CC`:c编译器，默认为`cc`
7. `CFLAGS`:编译参数，默认为空

# LICENSE

MIT

