#!/bin/bash
export PATH="$PATH:../../riscv64-linux-musl-cross/bin"
proc_id=0
Nproc=1
Npatch_num=1
Nproc_per_case=5000
cd ./maturin/libc/
python3 test.py $proc_id $Npatch_num $Nproc_per_case

