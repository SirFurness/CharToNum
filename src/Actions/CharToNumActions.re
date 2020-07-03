type action =
  | Init
  | DigitPressed(int)
  | DeletePressed
  | CorrectGuess
  | NewLength(float);
