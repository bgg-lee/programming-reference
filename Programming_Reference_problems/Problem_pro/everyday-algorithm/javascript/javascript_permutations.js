/*
  i 가 0일 때:
    i 가 0이면 배열의 첫 원소이기 때문에 바로 쓰면 된다.
  arr[i-1] != arr[i] 일 때:
    지금은 arr 이 정렬되어 있다. 이때 i 번째 원소가 i-1 번째와 다르면 그냥 ‘B’, ‘C’ 처럼 서로 다른 원소이기 때문에 바로 쓴다.
  used[i-1] 일 때:
    가령 i 번째 원소가 두 번째 ‘A’이면, 중복을 피하기 위해 첫 번째 ‘A’가 사용된 상태여야만 쓸 수 있다. 그래서 i-1 번째 원소가 쓰인 상태인지 확인한다.
  이렇게 하면 순열일 때 중복을 피할 수 있다.
  // 입력값 arr은 정렬된 문자열이다 !
*/
const permutations = (arr, r) => {
  arr = [...arr].sort(); // sorted
  used = [];
  for (let i = 0; i < arr.length; i++) used.push(0);

  const generate = (chosen, used) => {
    if (chosen.length == r) {
      console.log(chosen);
      return;
    }

    for (let i = 0; i < arr.length; i++) {
      if (!used[i] && (i == 0 || arr[i - 1] != arr[i] || used[i - 1])) {
        chosen.push(arr[i]);
        used[i] = 1;
        generate(chosen, used);
        used[i] = 0;
        chosen.pop();
      }
    }
  };
  generate([], used);
};

permutations('AABC', 2); // 정렬된 문자열!
permutations([1, 2, 3, 4, 5], 3); // 정렬된 배열
