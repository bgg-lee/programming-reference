const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;
let memo;

rl.on('line', function (line) {
  input = line;
}).on('close', function () {
  memo = Array.apply(null, Array(31)).map(Number.prototype.valueOf, 0);
  console.log(dp(input));
  process.exit();
});

// 홀수 일 경우는(Ex: 3*3 = 9) -> 2*1 / 1*2 로 못 만듬
function dp(x) {
  if (x == 0) return 1;
  if (x == 1) return 0;
  if (x == 2) return 3;
  if (memo[x] != 0) return memo[x];
  result = 3 * dp(x - 2);
  for (let i = 3; i <= x; i++) {
    if (i % 2 == 0) {
      result += 2 * dp(x - i);
    }
  }
  return (memo[x] = result);
}
