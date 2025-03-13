// 0. concat:
// 인자로 주어진 배열이나 값들을 기존 배열에 합쳐서 새 배열을 return
var items = [1, 2];
var newItems = items.concat(3, 4, 5, 'str', undefined);
console.log(newItems); //  [ 1, 2, 3, 4, 5, 'str', undefined ]
// 1. join
// join 은 배열의 모든 요소를 연결해 하나의 문자열로 만듬
// 인자로 특정문자열을 전달하면, 특정 문자열로 구분자로 요소들을 연결
// 배열 요소 값이 null 이거나 undefined 일 경우, 빈 문자열을 return
var names = ['shane', 'alan', 'osbourne'];
console.log(names.join('-')); // shane-alan-osbourne

// 다른 메서드와 함께 사용한 예제
var name = 'shane osbourne';
var upper = name
  .split(' ')
  .map((x) => x.charAt(0).toUpperCase() + x.slice(1))
  .join(' ');
console.log(upper); // Shane Osbourne

// 2. indexOf
// 배열에서 지정된 요소를 찾을 수있는 첫 번째 인덱스를 반환하고 존재하지 않으면 -1을 반환(return 값을 검사해서 Boolean 형태로 활용 가능)
// ===(Strict Equality Comparison Algorithm: 자료형 일치여부까지 비교)
console.log('---- indexOf ----');
var x = [10, 20, 30, 40, 40];
var idx = x.indexOf(20);
console.log(idx); // 1
var idx = x.lastIndexOf(40); // 해당 값에 맞는 마지막 인덱스 반환
console.log(idx); // 4

// 3. slice
// 배열을 전체 혹은 부분 복제(clone)할 때
// 인자를 두개 받는다. 시작 index(포함) 와 끝 index(비포함)
console.log('---- slice ----');
var x = [10, 20, 30, 40, 50];
console.log(x.slice()); // 전체 복사 : [ 10, 20, 30, 40, 50 ]
console.log(x.slice(1, 2)); // 1(포함) 부터 2까지(비포함) : [20]

// 3-2 splice:
// 기존 요소를 제거하거나 새 요소를 추가하여 배열의 내용을 변경
// start: 배열의 변경을 시작하는 인덱스
// deleteCount: 배열에서 제거를 할 요소의 수
// itemN: 배열에 추가될 요소, 리턴 값: 삭제된 요소들의 배열이 리턴
// array.splice(start, deleteCount[, item1[, item2[, ...]]])
console.log('---- splice ----');
var x = [10, 20, 30, 40, 50];
var removed = x.splice(1, 2);
console.log(removed); // [ 20, 30 ]

// 4. sort
// 배열의 요소를 적절한 위치에 정렬하고 배열을 반환
console.log('---- sort ----');
var x = [50, 30, 20, 40, 10];
x.sort();
console.log(x); // [ 10, 20, 30, 40, 50 ]

// 5. push: 배열에 추가 w/ apply -> pop, shift, unshift
console.log('---- push, pop, shift, unshift ----');
var x = [10, 20, 30, 40, 50];
x.push(60);
console.log(x); // [ 10, 20, 30, 40, 50, 60 ]
x.pop();
console.log(x); // [ 10, 20, 30, 40, 50 ]
x.shift(); // shift: 배열에서 첫 번째 요소를 제거하고, 제거된 요소를 반환
console.log(x); // [ 20, 30, 40, 50 ]
x.unshift(60); // 하나 또는 그 이상의 요소를 배열의 시작점에 추가하고 배열의 새 길이(length)를 반환
console.log(x); // [ 60, 20, 30, 40, 50 ]

// 6. <추가> find, findIndex(ES6)
// find: 제공된 테스트 함수를 만족하는 배열의 첫 번째 요소를 반환
// findIndex: 제공된 테스트 함수를 만족하는 배열의 첫 번째 요소에 대한 인덱스를 반환
console.log('---- find, findIndex(ES6) ----');
var x = [10, 20, 30, 40, 50];
var val = x.find((a) => a == 10);
console.log('val ' + val); // 10
var idx = x.findIndex((a) => a == 10);
console.log('index ' + idx); // 0
