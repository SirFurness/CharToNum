module CharToNumState = CharToNumState;
module GameOverState = GameOverState;
module CountdownState = CountdownState;

module Pages {
  type t =
    | StartMenu
    | Countdown
    | CharToNum
    | GameOver;
};


type t = {
  currentPage: Pages.t,
  charToNum: CharToNumState.t,
  gameOver: GameOverState.t,
  countdown: CountdownState.t,
};

let initial = {
  currentPage: Pages.StartMenu,
  charToNum: CharToNumState.initial,
  gameOver: GameOverState.initial,
  countdown: CountdownState.initial,
};
