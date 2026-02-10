use std::env;

fn main() {
    println!("hello");
    for arg in env::args().skip(1) {
        println!("{}", arg);
    }
}
