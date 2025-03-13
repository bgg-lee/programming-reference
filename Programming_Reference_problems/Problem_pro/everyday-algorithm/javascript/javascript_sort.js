// 자바스크립트 1차원 배열 정렬하기
/*
    function(a,b) < 0 이면 a를 b보다 작은 인덱스로 정렬한다.
    function(a,b) == 0 이면 a와 b의 순서를 바꾸지 않는다.
    function(a,b) > 0 이면 b를 a보다 작은 인덱스로 정렬한다.
*/
let number = [2, 5, 3, 4, 1];
let number_list = [
  [1, 2],
  [3, 1],
  [4, 5],
];
let fruit = ['orange', 'apple', 'banana'];
let student = [
  { name: 'Andrew', age: 21 },
  { name: 'Amy', age: 20 },
  { name: 'David', age: 26 },
  { name: 'Bryan', age: 19 },
];

// 오름차순 정렬
// 생략하면 오름차순, ASCII 문자 순서로 정렬
number.sort();
number_list.sort((a, b) => a[0] - b[0]); // 첫번째 원소 오름차순
fruit.sort();
student.sort((a, b) => (a.name > b.name ? 1 : -1)); // 이름 오름차순
console.log(number);
console.log(number_list);
console.log(fruit);
console.log(student);

// 내림차순 정렬
number.sort((a, b) => b - a);
number_list.sort((a, b) => a[1] - b[1]); // 두번째 원소 오름차순
fruit.sort().reverse();
student.sort((a, b) => (a.name < b.name ? 1 : -1)); // 이름 내림차순
console.log(number);
console.log(number_list);
console.log(fruit);
console.log(student);

// object 숫자 오름차순 정렬
student.sort((a, b) => a.age - b.age);

// payload 순위 조정 (경험치 기준)
rankings.sort((x, y) => {
  if (y.exp === x.exp) return y.achievement - x.achievement;
  return y.exp - x.exp;
});
