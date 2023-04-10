#!/bin/bash
export PATH="$PATH:../../riscv64-linux-musl-cross/bin"
Npatch_num=1
cd ./maturin/libc/
python3 test.py $Npatch_num
