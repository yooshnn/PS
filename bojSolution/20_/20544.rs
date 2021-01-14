use std::io::BufRead;
use std::io::Write;

fn main() {
    let mut read = std::io::BufReader::new(std::io::stdin());
    let mut out = std::io::BufWriter::new(std::io::stdout());

    const MOD: i64 = 1000000007;

    let mut get = String::new();
    read.read_line(&mut get).unwrap();
    let n: i32 = get.trim().parse().unwrap();

    let (mut res0, mut res1): (i64, i64) = (0, 0);
    let dp: &mut [[[i64; 3]; 3]; 1010] = &mut [[[0; 3]; 3]; 1010];
    let dp_: &mut [[[i64; 2]; 2]; 1010] = &mut [[[0; 2]; 2]; 1010];
    
    // 1: 0, 2: 1
    dp[3][0][0] = 1;
    dp[3][0][1] = 1;
    dp[3][0][2] = 1;
    dp[3][1][0] = 1;
    dp[3][1][1] = 1;
    dp[3][1][2] = 1;
    dp[3][2][0] = 1;
    dp[3][2][1] = 1;
    
    for i in 4..=n {
        let cur: usize = i as usize;
        dp[cur][0][0] = (dp[cur-1][0][0] + dp[cur-1][1][0] + dp[cur-1][2][0]) % MOD;
        dp[cur][0][1] = (dp[cur-1][0][0] + dp[cur-1][1][0] + dp[cur-1][2][0]) % MOD;
        dp[cur][0][2] = (dp[cur-1][0][0] + dp[cur-1][1][0] + dp[cur-1][2][0]) % MOD;

        dp[cur][1][0] = (dp[cur-1][0][1] + dp[cur-1][1][1] + dp[cur-1][2][1]) % MOD;
        dp[cur][1][1] = (dp[cur-1][0][1]) % MOD;
        dp[cur][1][2] = (dp[cur-1][0][1]) % MOD;

        dp[cur][2][0] = (dp[cur-1][0][2] + dp[cur-1][1][2]) % MOD;
        dp[cur][2][1] = (dp[cur-1][0][2]) % MOD;
    }

    for i in 0..3 {
        for j in 0..3 {
            res0 += dp[n as usize][i][j];
        }
    }


    dp_[3][0][0] = 1;
    dp_[3][0][1] = 1;
    dp_[3][1][0] = 1;
    dp_[3][1][1] = 1;
    
    for i in 4..=n {
        let cur: usize = i as usize;
        dp_[cur][0][0] = (dp_[cur-1][0][0] + dp_[cur-1][1][0]) % MOD;
        dp_[cur][0][1] = (dp_[cur-1][0][0] + dp_[cur-1][1][0]) % MOD;

        dp_[cur][1][0] = (dp_[cur-1][0][1] + dp_[cur-1][1][1]) % MOD;
        dp_[cur][1][1] = (dp_[cur-1][0][1]) % MOD;
    }

    for i in 0..2 {
        for j in 0..2 {
            res1 += dp_[n as usize][i][j];
        }
    }

    if n == 1 {
        writeln!(out, "{}", 0).unwrap();
    }
    else if n == 2 {
        writeln!(out, "{}", 1).unwrap();
    }
    else {
        writeln!(out, "{}", (MOD + res0 - res1) % MOD).unwrap();
    }
    
}