open Setup;

describe("PatternMatching", ({test}) => {
  test("Basic", ({expect}) => {
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
      Lets use our own pattern matching. Write a function that returns
      whether x is non zero by matching on x
    */
    let nonZero = x => failwith("For you to implement");

    expect.bool(nonZero(0).toBeFalse();
    expect.bool(nonZero(500).toBeTrue();
    expect.bool(nonZero(-400).toBeTrue();
  });

  test("Variants", ({expect}) => {
    /*
      As in most languages, you can define your own types.
      The keyword "type" introduces a type definition.

      One of the non-basic types in Reason is called the variant type.
      Variant types are similar to Enums in other languages. They are
      types which may take on multiple forms, where each form is marked
      by an explicit tag. A variant type is defined as follows:
    */
    type color =
      | Red
      | Green
      | Blue;

    /* Variants are very useful in combination with pattern matching */
    let toString = color =>
      switch (color) {
      | Red => "red"
      | Green => "green"
      | Blue => "blue"
      };

    /*
      Reason variants are in many ways more powerful than Enums because the different
      constructors of your variant can include data in them. Here's an example:
    */
    type cardValue =
      | Ace
      | King
      | Queen
      | Jack
      | Number(int);

    let oneCardValue: cardValue = Queen;

    let anotherCardValue: cardValue = Number(8);

    let cardValueToString = cardValue =>
      switch (cardValue) {
      | Ace => "Ace"
      | King => "King"
      | Queen => "Queen"
      | Jack => "Jack"
      | Number(i) => string_of_int(i)
      };

    /*
      Write a function that computes the score of a card (aces should score 11
      and face cards should score 10).
    */
    let cardValueToScore = cardValue => 3;

  expect.int(cardValueToScore(Ace).toBe(11);
  expect.int(cardValueToScore(King).toBe(10);
  expect.int(cardValueToScore(Queen).toBe(10);
  expect.int(cardValueToScore(Jack).toBe(10);
  expect.int(cardValueToScore(Number(5)).toBe(5);
  })

  // Explain equality of records/lists
  // Explain pattern matching with records/lists
});
