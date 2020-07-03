type t = {latestState: ref(State.t)};

let start = (~onStateChanged, ~getState) => {
  let store: t = {latestState: ref(getState())};

  let dispatch = (action: Actions.t) => {
    let currentState = store.latestState^;
    let newState = Reducer.reducer(currentState, action);

    store.latestState := newState;

    if (newState !== currentState) {
      onStateChanged(newState);
    };
  };

  dispatch;
};
