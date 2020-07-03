let reducer: (State.GameOverState.t, Actions.GameOverActions.action) => State.GameOverState.t = (state, action) => {
  switch(action) {
  | Init(score, letter, letterNumber) => 
    let bestScore = max(state.bestScore, score);
    {score, bestScore, letter, letterNumber}
  }
}
