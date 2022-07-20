# qemu-binary-demo
该库目前只存放install，uninstall等脚本以及qemu快捷编译程序源代码。
为了方便大家更快获取最新版的qemu，本人利用c语言编写了qemu快捷编译程序
# 使用方法
1.如果是arm64/x64架构处理器的设备，可以前往releases下载（可能来不及更新），下载完成后通过终端运行（请先通过chmod +x命令给予可执行权限），普通用户请在命令前加sudo
2.如果是其他架构的处理器的设备，也可以自行克隆源码，通过以下命令编译运行：
gcc -o compiler compile_qemu.c ; sudo ./compiler
3.如果你有极客精神，也可以自行修改其中源码的内容（不要直接更改本仓库中的文件并提交！！！），实现功能的定制（如源码获取方式，编译方式等），请注意，只推荐修改带注释的内容，不要随意修改其他代码内容，否则造成的bug由用户自行承担。

查看qemu帮助请前往https://www.qemu.org/docs/master/
获取源码及反馈问题请前往qemu存储库https://github.com/qemu/qemu

因本人时间有限，可能来不及更新，欢迎各位共同维护
