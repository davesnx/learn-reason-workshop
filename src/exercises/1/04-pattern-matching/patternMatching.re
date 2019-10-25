/*
  Pattern matching lets us compare inputs to known values.
  Patterns following "|" are tested in order.
  On the first match, we use the result following "=>".
  The "_" pattern means "could be anything".
 */
let isSuperman = x =>
  switch (x) {
  | "Clark Kent" => true
  | _ => false
  };

/*
  Let's use our own pattern matching. Write a function that returns
  whether x is non zero by matching on x
 */
let nonZero = x => failwith("For you to implement");

Test.runAll([
  (nonZero(0) == false, "non zero"),
  (nonZero(500) == true, "non zero"),
  (nonZero(-400) == true, "non zero"),
]);

let jsCalculate: (array(int), int) => int = [%bs.raw
  {|
 function (numbers, scaleFactor) {
   var result = 0;
   numbers.forEach(number => {
     result += number;
   });
   return result * scaleFactor;
 }
|}
];

let calculate = (numbers, scaleFactor) =>
  jsCalculate(Array.of_list(numbers), scaleFactor);

Js.log(calculate([1, 2, 3], 10)); /* -> 60 */
