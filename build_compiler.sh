#!/usr/bin/bash
#rm -rf qemu-compiler/compile_qemu.c ; cp compile_qemu.c qemu-compiler
if [[ "$(arch)"="x86_64" ]];then
sudo apt install gcc gcc-aarch64-linux-gnu
elif [[ "$(arch)"="aarch64" ]];then
sudo apt install gcc gcc-x86-64-linux-gnu
fi
mkdir qemu-compiler-arm64 qemu-compiler-x64
time bash -c "aarch64-linux-gnu-gcc -O3 -o qemu-compiler-arm64/qemu-compiler compile_qemu.c -static ;x86_64-linux-gnu-gcc -O3 -o qemu-compiler-x64/qemu-compiler compile_qemu.c -static"
tar -cf qemu-compiler-arm64.tar qemu-compiler-arm64/*
tar -cf qemu-compiler-x64.tar qemu-compiler-x64/*
rm -rf qemu-compiler-*.tar.gz
gzip qemu-compiler-arm64.tar
gzip qemu-compiler-x64.tar
rm -rf qemu-compiler-*.tar qemu-compiler-arm64 qemu-compiler-x64
#cd qemu-compiler
export COMMIT=$@
if [[ $COMMIT != "" ]];then
git commit -a -m "$@"
git push -u origin main
else
echo "未添加提交信息，默认不会提交到git存储库"
fi
