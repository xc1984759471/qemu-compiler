/*
qemu快捷编译程序（适用于windows）
原作者：xc1984759471
以下内容可以根据说明自定义
注意：本程序请进入MSYS2 MSYS下安装的gcc进行编译，编译后请到MSYS2 MINGW64运行!
*/
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include<string.h>
int main(int argc,char *argv[])
{
    char argv2;
    int i;
    //用于判断文件是否存在
    int file=access("qemu.tar.xz",F_OK);
    int file1=access("qemu",F_OK);
    //定义命令
    char arr[100000]="/bin/bash -c 'cd qemu;./configure";
    char arr3[300]=" && make -j5 && make install && mkdir qemu-binary-demo ; git clone 'https://gitee.com/xc1984759471/qemu-binary-demo.git';cd qemu-binary-demo;cat uninstall >> /usr/local/bin/uninstall_qemu ; chmod 777 /usr/local/bin/uninstall_qemu  ; cd ../..;rm -rf qemu'";
    char arr4[]="wget -O qemu.tar.xz https://download.qemu.org/qemu-6.1.0.tar.xz;tar xvJf qemu.tar.xz ; mv qemu-6.1.0 qemu ; rm -rf qemu.tar.xz";
    char arr5[]="tar xvJf ./qemu.tar.xz ; mv qemu-?.?.* qemu ; rm -rf qemu.tar.xz";
    char arr6[]="git clone https://mirrors.tuna.tsinghua.edu.cn/git/qemu.git";
    char arr7[]="git clone https://gitlab.com/qemu-project/qemu.git";
    //char arr2;
    if(argc>=2)
    {
        if(strcmp(argv[1],"auto")==0)//自动编译
        {
            //判断文件是否存在
            if(file1==-1)
            {
                
                if(file!=-1)
                {
                    system(arr5);
                }
                else
                {
                    printf("检测到您还没获取源码，正在获取源码(默认获取tar.xz包,如需通过其他通道，请使用%s source命令获取)\n",argv[0]);
                    system(arr4);
                }
            }
            //安装依赖
            system("pacman -Syu --noconfirm");
system("arch=$(arch) pacman -S base-devel mingw-w64-$(arch)-toolchain git --noconfirm");
system("arch=$(arch) pacman -S mingw-w64-$(arch)-glib2 mingw64/mingw-w64-$(arch)-gtk3 mingw64/mingw-w64-$(arch)-SDL2 mingw-w64-$(arch)-ninja --noconfirm");
system("pacman -S mingw-w64-$(arch)-binutils mingw-w64-$(arch)-crt-git --noconfirm; pacman -S mingw-w64-$(arch)-headers-git mingw-w64-$(arch)-gcc-libs --noconfirm; pacman -S mingw-w64-$(arch)-gcc mingw-w64-$(arch)-gdb mingw-w64-$(arch)-make --noconfirm; pacman -S mingw-w64-$(arch)-tools-git mingw-w64-$(arch)-pkg-config --noconfirm; pacman -S mingw-w64-$(arch)-winpthreads-git mingw-w64-$(arch)-libwinpthread-git --noconfirm; pacman -S mingw-w64-$(arch)-winstorecompat-git mingw-w64-$(arch)-libmangle-git --noconfirm; pacman -S mingw-w64-$(arch)-pixman mingw-w64-$(arch)-SDL2 mingw-w64-$(arch)-glib2 --noconfirm;pacman -S mingw-w64-$(arch)-capstone ninja --noconfirm");
            printf("即将开始自动编译，将使用以下默认编译配置：\n");
            printf("待编译的模拟模式：arm-softmmu,aarch64-softmmu,i386-softmmu,ppc-softmmu,ppc64-softmmu,mips64el-softmmu,x86_64-softmmu,\n");
            printf("其他功能：GTK+图形界面，spice图形界面，TPM模块支持等\n");
            for(i=3;i>=1;i--)//倒计时
            {
                printf("%d秒后开始编译\n",i);
                usleep(1000000);
            }
            char arr2[300]=" --enable-gtk --enable-tpm --prefix=~/qemu --enable-spice --target-list=arm-softmmu,aarch64-softmmu,i386-softmmu,ppc-softmmu,ppc64-softmmu,mips64el-softmmu,x86_64-softmmu ";
            strcat(arr,arr2);
            strcat(arr,arr3);
            system(arr);//执行编译命令
            printf("安装已完成，请使用uninstall_qemu命令卸载\n");
            return 0;
        }
        else if(strcmp(argv[1],"source")==0)//获取源代码
        {
            if(file1!=-1)//存在./qemu文件夹时
            {
                printf("已经获取完源码，退出\n如需再次获取，请手动删除qemu目录\n");
                return 0;
            }
            else
           {
               if(argc==3)
               {
               if(strcmp(argv[2],"git-th")==0)//清华源
               {
                   printf("即将通过清华源获取源码\n");
                   system(arr6);
                   printf("已完成\n");
                   return 0;
               }
               else if(strcmp(argv[2],"git")==0)//官方源
               {
                   printf("即将通过官方源获取源码（可能速度较慢）\n");
                    system(arr7);
                    printf("已完成\n");
                   return 0;
               }
               else if(strcmp(argv[2],"tar")==0)//tar.xz包
               {
                   printf("即将通过源码包获取源码（可能速度较慢）\n");
                   system(arr4);
                   printf("已完成\n");
                   return 0;
               }
               else if(strcmp(argv[2],"local")==0)//本地包解压
               {
                   if(file!=-1)
                   {
                       printf("已检测到qemu.tar.xz,即将开始解压\n");
                       usleep(10000);
                       system(arr5);
                       printf("已完成\n");
                        return 0;
                   }
                   else
                   {
                       printf("未检测到本地的qemu.tar.xz,请将下载好的源码包放在当前目录下，并重命名为qemu.tar.xz,或者通过其他方式获取\n");
                       return 1;
                   }
               }
               else
               {
                    printf("参数错误\n");
               }
               
               }
               else
               {
                   printf("参数过多或过少\n");
                   printf("%s source git-th 通过清华镜像站提供的qemu源获取\n",argv[0]);
                   printf("%s source git 通过官方源获取\n",argv[0]);
                   printf("%s source tar 获取源码包（默认6.1.0版本）\n",argv[0]);
                   printf("%s source local 解压本地已有源码包（需要重命名为qemu.tar.xz并放在当前目录）\n",argv[0]);
                    return 1;
               } 
           }
        }
        else if(strcmp(argv[1],"version")==0)//版本信息
        {
            printf("qemu快捷编译程序 for Windowz V4.2-qemu6.1.0\n");
            printf("Copyright(c)xc1984759471 2021\n");
            printf("\n本程序主要为用户提供编译qemu更为快捷的手段，方便小白上手。支持自动获取源代码，自动配置，自动编译，自动安装，提供多种源码获取方式，及自定义配置功能\n注意：本程序需要借助msys2 mingw环境运行\n");
            printf("更新内容：同步上游更新\n");
		printf("\n作者注：为什么要用C语言写本程序呢？\n其实刚开始本人也打算用shell脚本来编写的，因为本程序绝大部分功能最终都是靠shell命令来实现的,但是后来发现用shell编程有些逻辑函数实现更为复杂，况且本人也很少对shell脚本进行过研究，后来本人发现用C语言编写逻辑关系更简单，于是本人就选择用C语言编写本程序。\n\n");
            printf("\n本程序完全免费，严禁任何组织和个人倒卖本程序\n");
            printf("反馈建议与bug请前往本仓库地址https://gitee.com/xc1984759471/qemu-binary-demo\n");
            return 0;

        }
        else if(strcmp(argv[1],"custom")==0)
        {
            if(file1==-1)
            {
                printf("检测到未获取源码，请先用%s source命令获取\n",argv[0]);
                //system(arr4);
                return 1;
            }
            else
            {
                printf("请在下方输入./configure参数（不需要填写./configure本身，只需填写参数即可)。\n");
                printf("如需获取帮助，可输入help(或者--help),也可以访问https://gitee.com/xc1984759471/qemu-binary-demo/blame/97f3030e78d87665d3f32743afe9e749b2da42c9/configure.md 获取参数帮助\n");
                printf("输入参数：./configure ");
                char arr2[500]=" ";
                char arr21[500];
                fgets(arr21,500,stdin);
	            arr21[strlen(arr21)-1]=0;
                
                if(strcmp(arr21,"help")==0||strcmp(arr21,"--help")==0)
                {
                    strcat(arr," --help'");
                    system(arr);
                    return 0;
                }
                else if(strcmp(arr21,"")==0)
                {
                    printf("未输入任何参数，将完全编译,是否继续？[y/N]");
			        char yn;
			        scanf("%c",&yn);
			        if(yn=='y'||yn=='Y')
			        {
                    strcat(arr,arr3);
                    system("pacman -Syu --noconfirm");
system("arch=$(arch) pacman -S base-devel mingw-w64-$(arch)-toolchain git --noconfirm");
system("arch=$(arch) pacman -S mingw-w64-$(arch)-glib2 mingw64/mingw-w64-$(arch)-gtk3 mingw64/mingw-w64-$(arch)-SDL2 mingw-w64-$(arch)-ninja --noconfirm");
system("pacman -S mingw-w64-$(arch)-binutils mingw-w64-$(arch)-crt-git --noconfirm; pacman -S mingw-w64-$(arch)-headers-git mingw-w64-$(arch)-gcc-libs --noconfirm; pacman -S mingw-w64-$(arch)-gcc mingw-w64-$(arch)-gdb mingw-w64-$(arch)-make --noconfirm; pacman -S mingw-w64-$(arch)-tools-git mingw-w64-$(arch)-pkg-config --noconfirm; pacman -S mingw-w64-$(arch)-winpthreads-git mingw-w64-$(arch)-libwinpthread-git --noconfirm; pacman -S mingw-w64-$(arch)-winstorecompat-git mingw-w64-$(arch)-libmangle-git --noconfirm; pacman -S mingw-w64-$(arch)-pixman mingw-w64-$(arch)-SDL2 mingw-w64-$(arch)-glib2 --noconfirm;pacman -S mingw-w64-$(arch)-capstone ninja --noconfirm");
                    system(arr);
                    return 0;
			        }
			        else
			        {
				        printf("已取消\n");
                        return 1;
			        }
                }
                else
                {
                    strcat(arr2,arr21);
                    strcat(arr,arr2);
                    strcat(arr,arr3);
                    system("pacman -Syu --noconfirm");
system("arch=$(arch) pacman -S base-devel mingw-w64-$(arch)-toolchain git --noconfirm");
system("arch=$(arch) pacman -S mingw-w64-$(arch)-glib2 mingw64/mingw-w64-$(arch)-gtk3 mingw64/mingw-w64-$(arch)-SDL2 mingw-w64-$(arch)-ninja --noconfirm");
system("pacman -S mingw-w64-$(arch)-binutils mingw-w64-$(arch)-crt-git --noconfirm; pacman -S mingw-w64-$(arch)-headers-git mingw-w64-$(arch)-gcc-libs --noconfirm; pacman -S mingw-w64-$(arch)-gcc mingw-w64-$(arch)-gdb mingw-w64-$(arch)-make --noconfirm; pacman -S mingw-w64-$(arch)-tools-git mingw-w64-$(arch)-pkg-config --noconfirm; pacman -S mingw-w64-$(arch)-winpthreads-git mingw-w64-$(arch)-libwinpthread-git --noconfirm; pacman -S mingw-w64-$(arch)-winstorecompat-git mingw-w64-$(arch)-libmangle-git --noconfirm; pacman -S mingw-w64-$(arch)-pixman mingw-w64-$(arch)-SDL2 mingw-w64-$(arch)-glib2 --noconfirm;pacman -S mingw-w64-$(arch)-capstone ninja --noconfirm");
                    system(arr);//执行编译命令
                    printf("已完成\n");
                    return 0;
                }
                
            }
        }
        else if(strcmp(argv[1],"help")==0)//帮助信息
        {
            printf("帮助：\n");
            printf("\nauto:自动编译\n");
            printf("source 获取源码\n");
            printf("version 版本信息\n");
            printf("custom 自定义配置参数\n");
            return 0;
        }
        else
        {
            printf("参数错误\n请通过%s help获取命令帮助\n",argv[0]);
            return 1;
        }

    }
    else
    printf("未指定任何参数,请通过%s help获取命令帮助\n",argv[0]);
}
