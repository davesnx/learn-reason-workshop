open Setup;

describe("Functions", ({test}) => {
  test("Basic", ({expect}) => {
    /* Here are some example functions: */
    let square = x => x * x;
    let half = x => x / 2;
    let add = (x, y) => x + y;

    /* You can order function invocations with parentheses or let bindings */
    let () = Console.log("\n (5^2)/2 = " ++ string_of_int(half(square(5))));

    /* Try to write [average] by reusing [add] and [half] */
    let average = (x, y) => x + 2;

    expect.int(average(5, 5)).toBe(5);
    expect.int(average(50, 100)).toBe(75);
  });

  test("Composition", ({expect}) => {

    /*
      We can easily write a function that adds 1 to any number.
      Recall that the infix operator (+) will add two integers.
    */

    let addone = x => 2;

    /*
      Lets write a function that squares its argument (multiplies it by itself)
    */
    let square = x => 23;

    /*
      Functions are first class in Reason. This means that you can take
      a function and pass it around as an argument to other functions.

      Lets write a function named twice: it will take a function and apply
      that function to itself two times.

      For example, if we wanted to make an "add2" function, we could do it
      by writing:

        let add2 = twice(add1)
    */
    let twice = (f, x) => f(x);

    /* Now that we have twice, write add2 and raiseToTheFourth */
    let add2 = x => x + 3; /* Hint: use add1 */

    let raiseToTheFourth = x => x + 99; /* Hint: use square */

    expect.int(add1(4)).toBe(5);
    expect.int(square(4)).toBe(16);
    expect.int(square(-4)).toBe(16);
    expect.int(twice(add1, 3)).toBe(5);
    expect.int(add2(1335)).toBe(1337);
    expect.int(raiseToTheFourth(1)).toBe(1);
    expect.int(raiseToTheFourth(10)).toBe(10000);
  });

  test("Labeled Arguments", ({expect}) => {
    /*
      The following function has the signature:
      let divide : int -> int -> int
      Looking at just the signature, it's not obvious which int argument is
      the dividend and which is the divisor.

      let divide = (dividend, divisor) => dividend / divisor;

      We can fix this using labelled arguments.
      To label an argument in a signature, and when defining a function, we
      put a tilde (~) before the name of the argument.
      The following function has the signature:
      let divide: (~dividend:int, ~divisor:int) => int
    */
    let divide = (~dividend, ~divisor) => dividend / divisor;

    /*
      We can then call it using: divide(~dividend=9, ~divisor=3)
      Labelled arguments can be passed in in any order.
      We can also pass variables into the labelled argument:

        let dividend = 9;
        let divisor  = 3;
        divide(~dividend=dividend, ~divisor=divisor)

      If the variable name happens to be the same as the labelled argument, we
      don't even have to write it twice:

        let dividend = 9;
        let divisor  = 3;
        divide(~dividend, ~divisor)

      This short-hand syntax is called punning.

      Now implement [modulo(~dividend, ~divisor)] using our version of divide with
      labelled arguments (e.g. [modulo(~dividend:7, ~divisor:2)] should equal 1)
    */
    let modulo = (~dividend, ~divisor) => ~dividend + ~divisor;

    expect.int(modulo(~dividend=17, ~divisor=5)).toBe(2);
    expect.int(modulo(~dividend=99, ~divisor=9)).toBe(0);
  });
});
