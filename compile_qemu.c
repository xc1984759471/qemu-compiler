#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include<string.h>
int detectlocale(char * processName)
{
    FILE* fp1 = NULL;
    int count = 1;
    int BUFSZ = 100;
    char buf[BUFSZ];
    char command[150];

    if(snprintf(command,  150, "locale | grep %s", processName) < 0)
        return -1;

    if((fp1 = popen(command,"r")) == NULL)
    {
        return -2;
    }
    if((fgets(buf, BUFSZ, fp1))!= NULL)
    {
        pclose(fp1);
        fp1 = NULL;
        if(NULL != strstr(buf, processName))
            return 0;
    }

    return -3;
}
int detectsu(char * userid)
{
    FILE* fp2 = NULL;
    int count2 = 1;
    int BUFSZ2 = 100;
    char buf2[BUFSZ2];
    char command2[150];

    if(snprintf(command2,  150, "whoami | grep %s", userid) < 0)
        return -1;

    if((fp2 = popen(command2,"r")) == NULL)
    {
        return -2;
    }
    if((fgets(buf2, BUFSZ2, fp2))!= NULL)
    {
        pclose(fp2);
        fp2 = NULL;
        if(NULL != strstr(buf2, userid))
            return 0;
    }

    return -3;
}



int main(int argc,char *argv[])
{
int su=detectsu("root");
if(su==0)
{
    char argv2;
    int i;
    int loc=detectlocale("zh_CN");
    //用于判断文件是否存在
    int file=access("qemu.tar.xz",F_OK);
    int file1=access("qemu",F_OK);
    //定义命令
    char ver[50]="7.0.0"; //qemu版本号
	char arr[100000]="/bin/bash -c 'cd qemu;./configure";
    char arr3[300]=" && make -j5 && make install && mkdir qemu-binary-demo && git clone 'https://github.com/xc1984759471/qemu-compiler.git';cd qemu-compiler;rm -rf /usr/local/bin/uninstall_qemu;cat uninstall >> /usr/local/bin/uninstall_qemu ; chmod 777 /usr/local/bin/uninstall_qemu  ; cd ../..;rm -rf qemu'";
    char arr4[300]="wget --no-check-certificate -O qemu.tar.xz https://download.qemu.org/qemu-";
	char arr41[100]=".tar.xz;tar --no-same-owner -xvJf qemu.tar.xz ; mv qemu-";
char arr42[100]=" qemu ; rm -rf qemu.tar.xz";
	strcat(arr4,ver);
	strcat(arr4,arr41);
	strcat(arr4,ver);
	strcat(arr4,arr42);
    char arr5[]="tar --no-same-owner -xvJf ./qemu.tar.xz ; mv qemu-?.?.* qemu ; rm -rf qemu.tar.xz";
    char arr6[]="git clone https://mirrors.tuna.tsinghua.edu.cn/git/qemu.git";
    char arr7[]="git clone https://gitlab.com/qemu-project/qemu.git";
    char dep1[]="sudo apt-get -y install build-essential git wget libglib2.0-dev libfdt-dev libpixman-1-dev zlib1g-dev";
    char dep2[]="sudo apt-get -y install nano git-email ninja-build";
    char dep3[]="sudo apt-get -y install libpulse-dev libasound2-dev libspice-protocol-dev libspice-server-dev libcap-dev libcap-ng-dev libcurl4-gnutls-dev libgtk-3-dev";
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
                    if(loc==0)
                    {
			        printf("检测到您还没获取源码，正在获取源码(默认获取tar.xz包,如需通过其他通道，请使用%s source命令获取)\n",argv[0]);
                    }
                    else
                    {
                    printf("The system detects that you have not yet obtained the source code, get the source code (default get the tar.xz package, if you need to pass the other channel, please use the \"%s source\" command to get)\n",argv[0]);
                    }
                    system(arr4);
                }
            }
            //安装依赖
            system(dep1);
            system(dep2);
            system(dep3);
            if(loc==0)
            {
            printf("即将开始自动编译，将使用以下默认编译配置：\n");
            printf("待编译的模拟模式：arm-softmmu,arm-linux-user,aarch64-softmmu,aarch64-linux-user,i386-softmmu,i386-linux-user,ppc-softmmu,ppc64-softmmu,ppc-linux-user,ppc64-linux-user,mips64el-softmmu,mips64el-linux-user,x86_64-softmmu,x86_64-linux-user\n");
            printf("其他功能：GTK+图形界面，spice图形界面，TPM模块支持等\n");
            }
            else
            {
            printf("It is about to start automatically compiling, you will use the following default compilation configuration:\n");
            printf("Simulation mode to be compiled: ARM-SoftMMU, ARM-Linux-User, Aarch64-Softmmu, Aarch64-Linux-User, I386-SoftMMU, I386-Linux-User, PPC-SoftMMU, PPC64-Softmu, PPC-Linux-User, PPC64-Linux-User, MIPS64EL-SoftMMU, MIPS64EL-Linux-User, X86_64-SoftMMU, X86_64-Linux-User\n");
            printf("Other features: GTK + graphical interface, SPICE graphical interface, TPM module support, etc.\n");
            }
            for(i=3;i>=1;i--)//倒计时
            {
                if(loc==0)
                {
                printf("%d秒后开始编译(按ctrl-c取消)\n",i);
                }
                else
                {
                printf("The compile program will be started after %d seconds (Press Ctrl-C to cancel)\n",i);
                }
                usleep(1000000);
            }
            char arr2[400]=" --enable-gtk --enable-tpm --prefix=/usr/local --enable-spice --target-list=arm-softmmu,arm-linux-user,aarch64-softmmu,aarch64-linux-user,i386-softmmu,i386-linux-user,ppc-softmmu,ppc64-softmmu,ppc-linux-user,ppc64-linux-user,mips64el-softmmu,mips64el-linux-user,x86_64-softmmu,x86_64-linux-user --audio-drv-list=alsa,pa ";
            strcat(arr,arr2);
            strcat(arr,arr3);
            system(arr);//执行编译命令
            if(loc==0)
            {
            printf("安装已完成，请使用uninstall_qemu命令卸载\n");
            }
            else
            {
            printf("Installation has been completed, please use the uninstall_qemu command to uninstall.\n");
            }
            return 0;
        }
        else if(strcmp(argv[1],"source")==0)//获取源代码
        {
            if(file1!=-1)//存在./qemu文件夹时
            {
                if(loc==0)
                {
                printf("已经获取完源码，退出\n如需再次获取，请手动删除qemu目录\n");
                }
                else
                {
                printf("Already got the source code, exit\nIf you need to get again, please delete the QEMU directory manually\n");
                }
                return 0;
            }
            else
           {
               if(argc==3)
               {
               if(strcmp(argv[2],"git-th")==0)//清华源
               {
                   if(loc==0)
                   {
                   printf("即将通过清华源获取源码\n");
                   }
                   else
                   {
                   printf("Source code will be obtained through Tsinghua mirror.\n");
                   }
                   system(arr6);
                   printf("已完成\nCompleted.\n");
                   return 0;
               }
               else if(strcmp(argv[2],"git")==0)//官方源
               {
                   if(loc==0)
                   {
                   printf("即将通过官方源获取源码（可能速度较慢）\n");
                   }
                   else
                   {
                   printf("Source code will be obtained through the official mirror.\n");
                   }
                    system(arr7);
                    printf("已完成\nCompleted.\n");
                   return 0;
               }
               else if(strcmp(argv[2],"tar")==0)//tar.xz包
               {
                   if(loc==0)
                   {
                   printf("即将通过源码包获取源码（可能速度较慢）\n");
                   }
                   else
                   {
                   printf("Source code will be obtained through the source package.\n");
                   }
                   system(arr4);
                   printf("已完成\nCompleted.\n");
                   return 0;
               }
               else if(strcmp(argv[2],"local")==0)//本地包解压
               {
                   if(file!=-1)
                   {
                       if(loc==0)
                       {
                       printf("已检测到qemu.tar.xz,即将开始解压\n");
                       }
                       else
                       {
                       printf("The qemu.tar.xz has been detected, will begin to decompress.\n");
                       }
                       usleep(10000);
                       system(arr5);
                       printf("已完成\nCompleted.\n");
                        return 0;
                   }
                   else
                   {
                       if(loc==0)
                       {
                       printf("未检测到本地的qemu.tar.xz,请将下载好的源码包放在当前目录下，并重命名为qemu.tar.xz,或者通过其他方式获取\n");
                       }
                       else
                       {
                       printf("No local qemu.tar.xz is detected, put the downloaded source package in the current directory and rename the package to qemu.tar.xz, or get other way.\n");
                       }
                       return 1;
                   }
               }
               else
               {
                    if(loc==0)
                    {
                    printf("参数错误\n");
                    }
                    else
                    {
                    printf("Parameter error\n");
                    }
               }
               
               }
               else
               {
                   if(loc==0)
               {
                   printf("参数过多或过少\n");
                   printf("%s source git-th 通过清华镜像站提供的qemu源获取\n",argv[0]);
                   printf("%s source git 通过官方源获取\n",argv[0]);
                   printf("%s source tar 获取源码包（默认%s版本）\n",argv[0],ver);
                   printf("%s source local 解压本地已有源码包（需要重命名为qemu.tar.xz并放在当前目录）\n",argv[0]);
               }
               else
                    {
                   printf("Excessive parameters or too little\n");
                   printf("%s source git-th:Get obtained by QEMU source provided by Tsinghua Mirror\n",argv[0]);
                   printf("%s source git:Get the source code by official mirror\n",argv[0]);
                   printf("%s source tar:Get the source package (default version:%s)\n",argv[0],ver);
                   printf("%s source local:Unzip the local existing source package (need to be renamed qemu.tar.xz and put it in the current directory)\n",argv[0]);
                    }
                    return 1;
               } 
           }
        }
        else if(strcmp(argv[1],"version")==0)//版本信息
        {
            printf("  QQQQQQQQ     EEEEEEEE    M     M     U      U    \n");
            printf(" Q        Q    E           MM   MM     U      U    \n");
            printf(" Q        Q    E           M M M M     U      U    \n");
            printf(" Q    Q   Q    EEEEEEEE    M  M  M     U      U    \n");
            printf(" 0      Q Q    E           M     M     U      U    \n");
            printf("  QQQQQQQQQ    E           M     M     U      U    \n");
            printf("            Q  EEEEEEEE    M     M      UUUUUU     \n");
            char comp_ver[]="5.2";
	if(loc==0)
            {
            printf("qemu快捷编译程序 V%s-qemu%s\n",comp_ver,ver);
            printf("版权所有(c)xc1984759471 2021-2022\n");
            printf("\n本程序主要为用户提供编译qemu更为快捷的手段，方便小白上手。支持自动获取源代码，自动配置，自动编译，自动安装，提供多种源码获取方式，及自定义配置功能\n");
            printf("更新内容：存储库已搬运到github,请通过新存储库获取\n");
            printf("\n本程序完全免费，遵守GPLV3协议，严禁任何组织和个人倒卖本程序\n");
            printf("反馈建议与bug请前往本仓库地址https://github.com/xc1984759471/qemu-compiler\n");
	    printf("\n版权声明:\n本程序是自由软件：你可以根据自由软件基金会发布的GNU通用公共许可证的条款，即许可证的第3版，或（你选择）任何更高的版本，重新发布和/或修改它。\n本程序的发布是希望它是有用的，但没有任何保证；甚至没有隐含的适销性或特定用途的保证。  更多细节请参见GNU通用公共许可证。\n你应该已经收到了与本程序一起的GNU通用公共许可证的副本。  如果没有，请参阅<http://www.gnu.org/licenses/>。\n");
            }
            else
            {
            printf("Qemu compiler V%s-qemu%s\n",comp_ver,ver);
            printf("Copyright(c)xc1984759471 2021-2022\n");
            printf("\nThis program mainly provides users with more fast means for compilation QEMU, which is convenient for small white hands. Support automatic acquisition source code, automatic configuration, automatic compilation, automatic installation, providing multiple source code acquisition methods, and custom configuration\n");
            printf("Update: The repository was moved to Github,please get it through the new repository\n");
            printf("\nThis program is completely free,Compliance with GPLV3 agreement,and it is strictly forbidden to organize and personal reselling\n");
            printf("Feedback Suggestions and Bug Please go to this GIT repository:https://github.com/xc1984759471/qemu-compiler\n");
	    printf("\nLicense Agreement:\nThis program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or  (at your option) any later version.\nThis program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.\nYou should have received a copy of the GNU General Public Licence along with this program.  If not, see <http://www.gnu.org/licenses/>.\n");
            }
            return 0;

        }
        else if(strcmp(argv[1],"custom")==0)
        {
            if(file1==-1)
            {
                if(loc==0)
                {
                printf("检测到未获取源码，请先用%s source命令获取\n",argv[0]);
                }
                else
                {
                printf("Detected an unprecedented source code, please use the %s source command to get\n",argv[0]);
                }
                //system(arr4);
                return 1;
            }
            else
            {
                if(loc==0)
                {
                printf("请在稍后打开的编辑器中输入./configure参数（不要填写./configure本身，否则会报错，请直接填写参数)。\n");
                printf("如需获取帮助，可输入help(或者--help),也可以访问https://gitee.com/xc1984759471/qemu-binary-demo/blame/97f3030e78d87665d3f32743afe9e749b2da42c9/configure.md 获取参数帮助\n如需完全编译，直接填入空格即可。\n");
                printf("注意：您可将参数分为多行写入，但是不可将参数截断（例如\n--prefix=\n/usr/bin\n是不允许的）。此外，请不要编写无法被./configure识别的参数,并且不支持注释功能。\n");
                printf("是否已阅读说明并继续？[y/N]");
                }
                else
                {
                printf("Enter ./configure parameters in the editor you open later.(Do not fill in ./configure itself, otherwise it will report an error, please fill in the parameters directly).\n");
                printf("If you need help, you can enter help (or --help), you can also access https://gitee.com/xc1984759471/qemu-binary-demo/blame/97f3030e78d87665d3f32743afe9e749b2da42c9/configure.md to get parameters help.\n");
                printf("Note: You can divide the parameters into multi-line writes, but you cannot truncate the parameter (for example, \n --prefix=\n/usr/bin \n is not allowed).\n");
                printf("Have you read the instructions and continue?[y/N]");
                }
                char yn1;
                scanf("%s",&yn1);
                if(yn1=='y'||yn1=='Y')
                {
                    if(loc==0)
                    {
                    printf("正在打开文本编辑器，请稍候\n");
                    }
                    else
                    {
                    printf("Opening the text editor,please wait\n");
                    }
                    usleep(1500000);
                char arr2[500]=" ";
                char arr21[500];
                //fgets(arr21,500,stdin);
	            //arr21[strlen(arr21)-1]=0;
                system("touch /tmp/custom_command.txt");
                system("editor /tmp/custom_command.txt");
                system("sed -i ':a;N;s/\\n/ /g;ta' /tmp/custom_command.txt");
                FILE *fp = NULL;
                fp = fopen("/tmp/custom_command.txt", "r");
                fgets(arr21, 255, (FILE*)fp);
                arr21[strlen(arr21)-1]=0;
                if(loc==0)
                {
                    printf("输入的参数为:%s\n",arr21);
                }
                else
                {
                printf("The Parameter is:%s\n",arr21);
                }
                if(strstr(arr21,"help")||strstr(arr21,"--help"))
                {
                    strcat(arr," --help'");
                    system(arr);
                    system("rm -rf /tmp/custom_command.txt");
                    return 0;
                }
                else 
                {
                    if(strcmp(arr21,"")==0)
                {
                    fflush(stdout);
                    if(loc==0)
                    {
                        printf("未输入任何参数，将完全编译,是否继续？[y/N]");
                    }
                    else
                    {
                    printf("No parameters are input, will be fully compiled, do you want to continue?[y/N]");
                    }
			        char yn;
			        scanf("%s",&yn);
			        if(yn=='y'||yn=='Y')
			        {
                    strcat(arr,arr3);
                    system(dep1);
                    system(dep2);
                    system(dep3);
                    system(arr);
                    printf("已完成\nCompleted\n");
                    system("rm -rf /tmp/custom_command.txt");
                    return 0;
			        }
			        else
			        {
				        printf("已取消\nCancelled\n");
                        system("rm -rf /tmp/custom_command.txt");
                        return 1;
			        }
                }
                else
                {
                    strcat(arr2,arr21);
                    strcat(arr,arr2);
                    strcat(arr,arr3);
                    system(dep1);
                    system(dep2);
                    system(dep3);
                    system(arr);//执行编译命令
                    printf("已完成\nCompleted\n");
                    system("rm -rf /tmp/custom_command.txt");
                    return 0;
                }
                }
                }
                else
                {
                    printf("已取消\nCancelled\n");
                    return 1;
                }
                
            }
        }
        else if(strcmp(argv[1],"help")==0)//帮助信息
        {
            if(loc==0)
            {
            printf("帮助：\n");
            printf("\nauto:自动编译(适用于较新的qemu版本)\n");
            printf("source 获取源码\n");
            printf("version 版本信息\n");
            printf("custom 自定义配置参数(适用于几乎所有qemu版本)\n");
            }
            else
            {
            printf("Help：\n");
            printf("\nauto:Automatic compilation (suitable for new QEMU versions)\n");
            printf("source:Get source\n");
            printf("version:Show the version information\n");
            printf("custom:Custom configuration parameters (for almost all QEMU versions)\n");
            }
            return 0;
        }
        else
        {
            if(loc==0)
            {
            printf("参数错误\n请通过%s help获取命令帮助\n",argv[0]);
            }
            else
            {
            printf("Parameter error\nPlease get the command help through %s help\n",argv[0]);
            }
            return 1;
        }

    }
    else
    if(loc==0)
    {
    printf("未指定任何参数,请通过%s help获取命令帮助\n",argv[0]);
    }
    else
    {
    printf("No parameters are specified, please use the %s help to get the command help\n",argv[0]);
    }
}
else
{
printf("本程序需要root权限才能运行\n");
}
}
