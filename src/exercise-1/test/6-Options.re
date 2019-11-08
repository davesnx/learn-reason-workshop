open Setup;

type option('a) =
  | None
  | Some('a);

describe("Options", ({test}) => {
  test("Basic", ({expect}) => {
    /*
      Many languages have a concept of "Null", which describes that some data is
      absent. In Reason, we can model the presence/absence data using ordinary
      variants.

      We're have the [option] type on top of the file to show you that it isn't magic.
      In real life you would always use the [option] type provided by the standard
      library.
    */

    /*
      An [option('a)] is either [None], meaning absence of data, or [Some x]
      meaning the data exists, and that data specifically is [x]. Here's an
      example:
    */
    let whatNumberAmIThinking = (myNumber: option(int)) =>
      switch (myNumber) {
      | None => "I'm not thinking of any number!"
      | Some(number) => "My number is: " ++ string_of_int(number)
      };

    assert (whatNumberAmIThinking(None) == "I'm not thinking of any number!");

    assert (whatNumberAmIThinking(Some(7)) == "My number is: 7");

    /*
      Implement the function [safeDivide(~dividend, ~divisor)], which takes two
      ints and returns an int option. It should return None if [divisor = 0], and
      otherwise returns [Some(x)] where [x] is the division result
    */
    let safeDivide = (~dividend, ~divisor) => failwith("For you to implement");

    expect.option(safeDivide(~dividend=3, ~divisor=2)).toBeSome();
    expect.option(safeDivide(~dividend=3, ~divisor=0)).toBeNone();
  });
});
