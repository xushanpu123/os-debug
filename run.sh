#!/bin/bash
export PATH="$PATH:../../riscv64-linux-musl-cross/bin"
cd ./maturin/libc/
python3 test.py 0 1 5000
