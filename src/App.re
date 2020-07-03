open Revery;
open Revery.UI;
open Revery.UI.Components;
open Views;
open Component_Utils;

type countdownAction =
  | Reset
  | Countdown;

let main = (~state: State.t, ~dispatch: Actions.t => unit, ()) => {
  let onDigit = digit => {
    dispatch(CharToNum(DigitPressed(digit)));
  };

  let onDelete = () => {
    dispatch(CharToNum(DeletePressed));
  };

  let onStartKey = () => {
    switch (state.currentPage) {
    | GameOver
    | StartMenu => dispatch(Actions.BeginCountdown)
    | _ => ()
    };
  };

  let currentUI =
    switch (state.currentPage) {
    | StartMenu => <StartMenuView dispatch />
    | Countdown => <CountdownView state={state.countdown} dispatch />
    | CharToNum => <CharToNumView state={state.charToNum} dispatch />
    | GameOver => <GameOverView state={state.gameOver} dispatch />
    };

  <View
    style=Style.[
      position(`Absolute),
      top(0),
      bottom(0),
      left(0),
      right(0),
      backgroundColor(Theme.background),
    ]>
    <KeyboardInput onDigit onDelete onStartKey />
    currentUI
  </View>;
};

let init = app => {
  Random.self_init();

  let win = App.createWindow(app, "CharToNum");

  let currentState = ref(State.initial);
  let uiDispatch = ref(_ => ());

  let isDirty = ref(false);
  let onStateChanged = state => {
    currentState := state;
    isDirty := true;
  };

  let dispatch = Store.start(~onStateChanged, ~getState=() => currentState^);
  uiDispatch := dispatch;

  let update: Revery.UI.renderFunction =
    UI.start(win, <main state=currentState^ dispatch=uiDispatch^ />);

  let tick = _dt =>
    if (isDirty^) {
      update(<main state=currentState^ dispatch=uiDispatch^ />);
      isDirty := false;
    };

  let _: unit => unit = Tick.interval(tick, Time.zero);

  ();
};

App.start(init);
