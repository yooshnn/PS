use std::io::BufRead;
use std::io::Write;

fn main() {
    let mut read = std::io::BufReader::new(std::io::stdin());
    let mut out = std::io::BufWriter::new(std::io::stdout());

    let chilli: Vec<i64> = vec![1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 40353607, 282475249, 1977326743, 13841287201, 96889010407, 678223072849];
    let b: Vec<i64> = vec![1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969];
    
    let mut cnt: Vec<i64> = vec![0; 14];
    let mut res: i64 = 0;

    let mut get = String::new();
    read.read_line(&mut get).unwrap();
    let mut n: i64 = get.trim().parse().unwrap();

    for i in (0..=13).rev() {
        while n >= chilli[i] {
            n -= chilli[i];
            cnt[i] += 1;
        }
    }
    for i in (0..=13).rev() {
        res += cnt[i] * b[i];
    }

    writeln!(out, "{}", res).unwrap();
    
}