#![allow(dead_code)]

/*
TrafficLight， 枚举类型
Red, Yellow, Green 三个枚举变体
*/
enum TrafficLight {
    Red,
    Yellow,
    Green,
}

// (), 元组结构体语法， 字段没有名称，只有类型，通过位置访问字段
// {}, 结构体语法，字段有名称，通过名称访问字段
enum Shape {
    Circle(f64),
    Rectangle { width: f64, height: f64 },
    Triangle(f64, f64, f64),
}

fn print_shape_info(shape: &Shape) {
    match shape {
        Shape::Circle(radius) => {
            println!("这是一个圆, 半径是{}", radius);
        }
        Shape::Rectangle { width, height } => {
            println!("这是一个矩形, 宽是{}，高是{}", width, height);
        }
        Shape::Triangle(a, b, c) => {
            println!("这是一个三角形, 三条边分别是{}, {}, {}", a, b, c);
        }
    }
}

fn main() {
    let light = TrafficLight::Red;

    match light {
        TrafficLight::Red => println!("请停止"),
        TrafficLight::Yellow => println!("请注意"),
        TrafficLight::Green => println!("请通行"),
    }

    let circle = Shape::Circle(10.0);
    let rectangle = Shape::Rectangle {
        width: 5.0,
        height: 8.0,
    };
    let triangle = Shape::Triangle(3.0, 4.0, 5.0);
    print_shape_info(&circle);
    print_shape_info(&rectangle);
    print_shape_info(&triangle);
}
