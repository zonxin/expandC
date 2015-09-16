# C语言笔试题汇总

## 题目列表

[题目列表(clib/readme.md)](clib/readme.md)

此代码只适合在线笔试和学习交流使用。（不会处理一些在在线笔试的时候不可能出现的错误）
欢迎大家贡献代码。

## 自动代码生成器

首先，安装 nodejs <https://nodejs.org/en/>， 安装过程中要选择安装 npm 模块。打开命令控制台执行以下命令。

    # 全局安装 grunt-cli 只需要安装一次， linux 可能需要管理员权限
    npm install -g grunt-cli 
    
    # clone 此版本库
    git clone https://github.com/zonxin/grunt-expandC.git
    # 进入版本库的目录
    cd grunt-expandC
    # 安装依赖模块
    npm install

然后，在 expandC.json 文件中输入

    {
        "main":"demo.c",
        "output":"main",

        "CC":"gcc",      
        "ccArg":"",     
        "dest":"dest/",

        "test":"testdata/a/add.txt",
        "test_result":"testdata/a/add_result.txt",

        "DIFF":"diff",
        "diffArg":"-b",

        "watchfile":["demo.c"]
     } 

最后运行 `grunt` 则在 `dest/demo.c` 中生成的就是代码。

### grunt 命令

1. `grunt` 默认命令，自动生产单个可以编译的 `.c` 文件，并且编译测试
2. `grunt watch` 监控文件变动，自动编译测试
3. `grunt build` 生成单个可编译的`.c`
4. `grunt pretest` 编译原始文件，并测试
5. `grunt add:路径/文件.c` 创建文件生成对应的头文件，并且自动把头文件添加到 "main" 指定的文件中。

### expandC.json 配置

    // 注意:json 文件不支持任何注释
    {
        "main":"main.c",                                // main 函数所在文件
        "output":"main.exe",                            // 编译后生成程序的文件名

        "CC":"gcc",                                     // C 编译器选择 
        "ccArg":"",                                     // 编译参数
        "dest":"dest/",                                 // 输出文件所在文件夹

        "test":"testdata/develop.txt",                  // 测试用例
        "test_result":"testdata/develop_result.txt",    // 测试用例结果

        "DIFF":"diff",                                  // 对比结果使用的程序
        "diffArg":"-b",                                 // 参数

        "watchfile":["main.c","clib/**/*.c"]            // grunt watch 监控的文件 支持 globbing
     } 

# LICENSE

MIT

