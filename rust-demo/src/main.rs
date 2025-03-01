extern crate my_rust_project as lib;

fn main() {

    let integer: i32 = 10;
    let float: f64 = 3.14;
    let boolean: bool = true;
    let character: char = 'R';
    let string: &str = "Hello, Rust!";

    println!("Integer: {}", integer);
    println!("Float: {}", float);
    println!("Boolean: {}", boolean);
    println!("Character: {}", character);
    println!("String: {}", string);


    let person = Person {
        name: String::from("Alice"),
        age: 30,
    };

    println!("Person: {:?}", person);
    println!("Person's name: {}", person.name);
    println!("Person's age: {}", person.age);
    lib::demonstrate_usage();
}

#[derive(Debug)]
struct Person {
    name: String,
    age: u32,
}