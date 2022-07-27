# qemu-compiler
本程序为qemu编译器，只需一条命令，就可以自动完成qemu虚拟机的本地构建，更方便小白上手。支持自动获取源代码，自动安装依赖，自动配置，自动编译，自动安装，提供多种源码获取方式，及自定义配置功能
本存储库已开通Github actions自动构建，如需下载滚动更新版请到Actions选项卡下载
*自动安装依赖目前仅支持debian系发行版，后续会进一步适配其他发行版*
# 使用方法
1.在releases中下载对应架构的版本（普通pc下载x64版本即可）;
2.tar -xf qemu-compiler-\<x64|arm64\>.tar.gz
3.cd qemu-compiler-\<x64|arm64\>
4. ./qemu-compiler help可查看命令帮助，进行常规编译安装可执行./qemu-compiler auto
如果没有你使用的架构，也可以获取源代码自行编译，编译方法：
gcc -o compiler compile_qemu.c;./compiler <参数>

查看qemu帮助请前往https://www.qemu.org/docs/master/
获取源码及反馈问题请前往qemu存储库https://github.com/qemu/qemu
反馈意见/建议请直接提交issue
因本人时间有限，可能来不及更新，欢迎各位共同维护

