let addDigit = (prev, digit) => {
  switch(prev) {
  | None => digit
  | Some(num) =>
    let newNum = 10*num + digit;
    if(newNum > 99) {
      num;
    }
    else {
      newNum;
    };
  };  
};

let deleteDigit = (prev) => {
  switch(prev) {
  | None => None
  | Some(num) =>
    if(num < 10) {
      None;
    }
    else {
      Some(num/10);
    }
  }
}

// The letter shown
let getRandomLetter = () => {
  String.make(1, Char.chr(Random.int(26) + Char.code('A')));
};

// 0-25 or 1-26
let isZeroBased = false;
let letterNumber = (letter) => {
  let letterNumber = Char.code(letter.[0]) - Char.code('A');
  if (isZeroBased) {
    letterNumber;
  } else {
      letterNumber + 1;
  };
};

let isGuessCorrect = (guessedNumber, letterNumber) => {
  switch(guessedNumber) {
  | None => false
  | Some(num) => num == letterNumber
  };
};

let reducer: (State.CharToNumState.t, Actions.CharToNumActions.action) => State.CharToNumState.t = (state, action) => {
  switch(action) {
  | Init =>
    let newLetter = getRandomLetter();
    let newLetterNumber = letterNumber(newLetter);
    
    {duration: 5000., guessedNumber: None, letter: newLetter, letterNumber: newLetterNumber, score: 0, length: 0.}
  | DigitPressed(n) => {...state, guessedNumber: Some(addDigit(state.guessedNumber, n))}
  | DeletePressed => {...state, guessedNumber: deleteDigit(state.guessedNumber)}
  | CorrectGuess =>
    // Double check here because sometimes it gets dispatched multiple times
    if(isGuessCorrect(state.guessedNumber, state.letterNumber)) {
      let newLetter = getRandomLetter();
      let newLetterNumber = letterNumber(newLetter);
      
      {...state, duration: 0.9*.state.duration, guessedNumber: None, letter: newLetter, letterNumber: newLetterNumber, score: state.score+1}
    }
    else {
      state
    }
  | NewLength(newLength) => {...state, length: newLength}
  } 
};
