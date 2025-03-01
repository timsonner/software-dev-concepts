#[derive(Debug)]
struct Person {
    name: String,
    age: u32,
}

impl Person {
    fn new(name: &str, age: u32) -> Self {
        Person {
            name: String::from(name),
            age,
        }
    }

    fn greet(&self) {
        println!("Hello, my name is {} and I am {} years old.", self.name, self.age);
    }
    // Example usage
pub fn create_and_greet_person() {
    let person = Person::new("Alice", 30);
    person.greet();
    println!("{:?}", person);
}
}

enum Vehicle {
    Car(String),
    Bike(String),
}

impl Vehicle {
    fn describe(&self) {
        match self {
            Vehicle::Car(model) => println!("This is a car of model: {}", model),
            Vehicle::Bike(model) => println!("This is a bike of model: {}", model),
        }
    }
}

pub trait Describable {
    fn describe(&self);
}

impl Describable for Person {
    fn describe(&self) {
        self.greet();
    }
}

impl Describable for Vehicle {
    fn describe(&self) {
        self.describe();
    }
}

pub fn demonstrate_usage() {
    Person::create_and_greet_person();
    let person = Person::new("Alice", 30);
    person.describe();

    let car = Vehicle::Car(String::from("Tesla Model S"));
    car.describe();

    let bike = Vehicle::Bike(String::from("Yamaha MT-07"));
    bike.describe();
}