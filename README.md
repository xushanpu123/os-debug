panic_test目录

​	panic_type(i)类型的目录下存放了产生不同类型bug信息的测例，其中note.txt中存放了bug信息，panic_test_num中以数组形式存放了所有测例的编号。



maturin/libc/test_one.py的使用方法：

传入一个编号作为参数，可以在maturin上跑该编号对应的测例。



maturin/libc/test.py的使用方法：

批量运行测例，传入参数patch_num，表示启动一次os执行的测例数量。