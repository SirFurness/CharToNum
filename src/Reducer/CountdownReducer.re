let reducer: (State.CountdownState.t, Actions.CountdownActions.action) => State.CountdownState.t = (state, action) => {
  switch(action) {
  | Init => {count: 3}
  | DecreaseCountdown => {count: state.count-1}
  } 
};
