/*
用于表示操作可能成功或失败的情况
enum Result<T, E> {
    Ok(T),    // 表示成功，包含成功时的值
    Err(E),   // 表示失败，包含错误信息
}
这是一个带参数的枚举类型

*/

fn divide(a: f64, b: f64) -> Result<f64, String> {
    if b == 0.0 {
        Err("Division by zero".to_string())
    } else {
        Ok(a / b)
    }
}

// 按引用传递对象的方式称作借用
fn main() {
    let result = divide(10.0, 2.0);
    match result {
        Ok(value) => println!("Result: {}", value),
        Err(error) => println!("Error: {}", error),
    }

    let result = divide(10.0, 0.0);
    match result {
        Ok(value) => println!("Result: {}", value),
        Err(error) => println!("Error: {}", error),
    }
}
