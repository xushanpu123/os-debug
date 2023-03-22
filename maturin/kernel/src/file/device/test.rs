//! 运行比赛测试

use crate::{
    constants::{NO_PARENT, ROOT_DIR},
    task::TaskControlBlock,
};
use alloc::{boxed::Box, string::String, sync::Arc, vec::Vec};
use lock::Mutex;

/// 分隔 argv 参数，处理带引号的情况
pub fn split_argv(s: &[u8]) -> Vec<String> {
    let mut argv: Vec<String> = Vec::new();
    let mut in_quotation = false; // 当前是否在引号中
    let mut start = 0; // 从何处开始
    // 因为需要特判引号，所以这里用一种 c style 的方式处理
    for pos in 0..s.len() {
        if s[pos] == '\"' as u8 {
            in_quotation = !in_quotation;
        } else if s[pos] == ' ' as u8 && !in_quotation {
            if pos > start { // 避免塞入空串
                argv.push(core::str::from_utf8(&s[start..pos]).unwrap().into());
            }
            start = pos + 1;
        }
    }
    if start < s.len() {
        argv.push(core::str::from_utf8(&s[start..]).unwrap().into());
    }
    argv
}

/// 加载下一个用户程序。
pub fn load_next_testcase() -> Option<Arc<TaskControlBlock>> {
    TESTCASES_ITER.lock().next().map_or_else(
        || {
            TEST_STATUS.lock().final_info();
            None
        },
        |&user_command| {
            //let mut argv: Vec<String> = user_command.split(' ').map(|s| s.into()).collect();
            //let argv = argv.drain_filter(|s| s != "").collect();
            let argv = split_argv(user_command.as_bytes());
            TEST_STATUS.lock().load(&user_command.into());
            Some(Arc::new(
                TaskControlBlock::from_app_name(ROOT_DIR, NO_PARENT, argv).unwrap(),
            ))
        },
    )
}

/// 输出测试结果
pub fn show_testcase_result(exit_code: i32) {
    TEST_STATUS.lock().update_result(exit_code)
}

/// 运行测试时的状态机
struct TestStatus {
    cnt: usize,
    passed: usize,
    now: Option<String>,
    failed_tests: Vec<String>,
}

impl TestStatus {
    /// 初始化测试信息
    pub fn new(cases: &[&str]) -> Self {
        Self {
            cnt: cases.len(),
            passed: 0,
            now: None,
            failed_tests: Vec::new(),
        }
    }

    /// 输入测试
    pub fn load(&mut self, testcase: &String) {
        println!(
            " --------------- load testcase: {} --------------- ",
            testcase
        );
        self.now = Some(testcase.into());
    }

    /// 更新执行结果
    pub fn update_result(&mut self, exit_code: i32) {
        // 检查是否已有退出
        // 这一步检查是因为测例中可能使用 fork/clone，但每个进程退出都会执行 update_result
        // 这件事的本质原因是进程退出后 cpu_local 无法知道这是否是一个测例，如果需要改这一点就需要把 exit_code 留存 scheduler 为空。
        // 但如果这样改会导致需要更多的全局 lazy_static，在内核中不太合适
        if self.now == None {
            return;
        }
        //cnt += 1;
        match exit_code {
            0 => {
                println!(" --------------- test passed --------------- ");
                self.passed += 1;
                self.now.take();
            }
            _ => {
                println!(
                    " --------------- TEST FAILED, exit code = {} --------------- ",
                    exit_code
                );
                self.failed_tests.push(self.now.take().unwrap());
            }
        }
    }

    /// 最终输出测试信息
    pub fn final_info(&self) {
        println!(
            " --------------- all test ended, passed {} / {} --------------- ",
            self.passed, self.cnt
        );
        println!(" --------------- failed tests: --------------- ");
        for test in &self.failed_tests {
            println!("{}", test);
        }
        println!(" --------------- end --------------- ");
        panic!("");
    }
}

#[allow(dead_code)]
const CASES: &[&str] = crate::testcases::TESTCASES;
lazy_static::lazy_static! {
    //static ref TESTCASES_ITER: Mutex<Box<dyn Iterator<Item = &'static &'static str> + Send>> = Mutex::new(Box::new(FORMAT_LIBC_STATIC.into_iter().chain(FORMAT_LIBC_DYNAMIC.into_iter())));
    //static ref TEST_STATUS: Mutex<TestStatus> = Mutex::new(TestStatus::new(&[FORMAT_LIBC_STATIC, FORMAT_LIBC_DYNAMIC].concat()));
    static ref TESTCASES_ITER: Mutex<Box<dyn Iterator<Item = &'static &'static str> + Send>> = Mutex::new(Box::new(CASES.into_iter()));
    static ref TEST_STATUS: Mutex<TestStatus> = Mutex::new(TestStatus::new(CASES));
}
