#!/usr/bin/bash
#rm -rf qemu-compiler/compile_qemu.c ; cp compile_qemu.c qemu-compiler
cp -rf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
sudo apt update
if [[ "$(arch)"="x86_64" ]];then
sudo apt install gcc gcc-aarch64-linux-gnu build-essential -y
elif [[ "$(arch)"="aarch64" ]];then
sudo apt install gcc gcc-x86-64-linux-gnu build-essential -y
fi
mkdir qemu-compiler-arm64 qemu-compiler-x64
time bash -c "aarch64-linux-gnu-gcc -O3 -o qemu-compiler-arm64/qemu-compiler compile_qemu.c -static ;x86_64-linux-gnu-gcc -O3 -o qemu-compiler-x64/qemu-compiler compile_qemu.c -static"
for i in arm64 x64;do
cp LICENSE qemu-compiler-$i
tar -cf qemu-compiler-$i.tar qemu-compiler-$i/*
rm -rf qemu-compiler-$i.tar.gz
gzip qemu-compiler-$i.tar
rm -rf qemu-compiler-$i.tar qemu-compiler-$i
done
#cd qemu-compiler
export COMMIT=$@
if [[ $COMMIT != "" ]];then
git commit -a -m "$@"
git push -u origin main
else
echo "未添加提交信息，默认不会提交到git存储库"
fi
