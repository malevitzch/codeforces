#[allow(dead_code)]
fn input_str() -> String {
    let mut x = String::new();
    std::io::stdin()
        .read_line(&mut x)
        .expect("Failed to read line");
    x.trim().to_string()
}

#[allow(dead_code)]
fn input_num() -> i32 {
    input_str().parse::<i32>().expect("Not a number")
}

#[allow(dead_code)]
fn input_num64() -> i64 {
    input_str().parse::<i64>().expect("Not a number")
}

#[allow(dead_code)]
fn input_nums() -> Vec<i32> {
    let st = input_str();
    let inputs: Vec<i32> = st
        .split(" ")
        .map(|u| u.parse().expect("Not a number"))
        .collect();
    inputs
}

#[allow(dead_code)]
fn input_nums64() -> Vec<i64> {
    let st = input_str();
    let inputs: Vec<i64> = st
        .split(" ")
        .map(|u| u.parse().expect("Not a number"))
        .collect();
    inputs
}

#[allow(dead_code)]
fn printvec(x: Vec<i32>) {
    let mut st: String = String::new();
    for m in x {
        st += &(m.to_string() + &" ".to_owned());
    }
    println!("{}", st);
}

#[allow(dead_code)]
fn printvec64(x: Vec<i64>) {
    let mut st: String = String::new();
    for m in x {
        st += &(m.to_string() + &" ".to_owned());
    }
    println!("{}", st);
}

#[allow(dead_code)]
fn yes() {
    println!("YES");
}

#[allow(dead_code)]
fn no() {
    println!("NO");
}

#[allow(dead_code)]
fn answer(b: bool) {
    if b {
        yes();
    } else {
        no();
    }
}

fn main() {
    let t = input_num();
    for _ in 0..t {
        let v = input_nums();
        println!("{}", v[1] - v[0]);
    }
}
