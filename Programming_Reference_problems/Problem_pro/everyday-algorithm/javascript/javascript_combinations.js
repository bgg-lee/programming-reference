const combinations = (arr, r) => {
  arr = [...arr].sort(); // sorted
  used = [];
  for (let i = 0; i < arr.length; i++) used.push(0);

  const generate = (chosen) => {
    if (chosen.length == r) {
      console.log(chosen);
      return;
    }

    last_element = chosen.slice(-1)[0];
    if (chosen) start = arr.indexOf(last_element) + 1;
    else start = 0;
    for (let next = start; next < arr.length; next++) {
      if (!used[next] && (next == 0 || arr[next - 1] != arr[next] || used[next - 1])) {
        chosen.push(arr[next]);
        used[next] = 1;
        generate(chosen);
        used[next] = 0;
        chosen.pop();
      }
    }
  };
  generate([], used);
};

combinations('ABCDE', 2); // 정렬된 문자열
combinations([1, 2, 3, 4, 5], 3); // 정렬된 배열
