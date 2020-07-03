type t = {
  letter: string,
  letterNumber: int,
  guessedNumber: option(int),
  duration: float,
  length: float,
  score: int,
} 

let initial = {
  letter: "A",
  letterNumber: 1,
  guessedNumber: None,
  duration: 5000.,
  length: 0.,
  score: 0,
};
