open Setup;

describe("Basic Types", ({test}) => {
  /*
    In Reason there are 6 basic types: int, float, char, string, bool, and unit.
    In Reason floats are distinguished from ints by their decimal points. 0 is an
    int, 0. is a float.
    In addition the basic math operations are also distinguished by a decimal
    point. For example, + allows you to add two ints and +. allows you to add two
    floats.
  */

  test("int, float", ({expect}) => {
    let four = 4;
    let floatFour = 4.;

    /*
      Function signatures
      ===================
      In Reason, functions are also values! And so, functions also have type
      signatures.
      In a function signature, types of parameters are enclosed within parentheses.
      The return value is the described last and preceded immediately by an arrow
      [=>].
      So the signature for a function that takes two integers and returns an
      integer is:
      let intAverage: (int, int) => int
      In Reason there's no explicit return statement: functions just return the
      value of the last statement in that function.
    */

    /* let intAverage : (int, int) => int */
    let intAverage = (x, y) => x;

    /* let floatAverage : (float, float) => float */
    let floatAverage = (x, y) => y;

    expect.int(intAverage(5, 5)).toBe(5);
    expect.float(floatAverage(5., 5.)).toBeCloseTo(~digits=5, 5.);
    expect.float(floatAverage(5., 10.)).toBeCloseTo(~digits=5, 7.5);
  })

  test("string, boolean", ({ expect }) => {
    /*
      As in many languages strings are denoted with "" and chars are denoted with ''.
      String concatenation is done with the ++ operator.
    */

    let firstName = "Fred";
    let lastName: string = "Flintstone";
    let fullName = firstName ++ " " ++ lastName;

    let dontKnowXYet = (lang) => "I don't know " ++ lang ++ " yet";

    expect.string(dontKnowXYet("Reason")).toEqual("I don't know Reason yet");

    /*
      You can use
      && for logical and
      || for logical or
      !  for logical not
    */
    let aBooleanFalse: bool = false;
    let aBooleanNotFalse = !aBooleanFalse;
    let bool = aBooleanNotFalse && false;

    expect.bool(bool).toBeTrue()
  })

  /*
    The [unit] type
    ===============
    unit is a special type in Reason that has only one possible value written ().
    It is generally used for mutation and io-operations such as printing.
    (I/O stands for input/output. Examples: printing to screen, reading a file,
    sending and receiving network requests.)
    To combine several unit operations together the ; operator is used contained
    within curly braces.

  let () = {
    print_endline("Hi, My name is ");
    print_endline("Malisa");
    print_endline(" and I am 5 years old");
  };
  */
});
