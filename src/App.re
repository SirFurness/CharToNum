open Revery;
open Revery.UI;
open Revery.UI.Components;

type state =
  | StartMenu
  | CharToNum
  | GameOver;
type action =
  | Start
  | Stop;

let%component main = () => {
  let%hook (state, dispatch) =
    Hooks.reducer(~initialState=StartMenu, (action, _state) => {
      switch (action) {
      | Start => CharToNum
      | Stop => GameOver
      }
    });

  let currentUI =
    switch (state) {
    | StartMenu => <StartMenu start={() => dispatch(Start)} />
    | CharToNum => <CharToNum stop={() => dispatch(Stop)} />
    | GameOver => <View></View>
    };

  <View style=Style.[
    position(`Absolute),
    top(0),
    bottom(0),
    left(0),
    right(0),
    backgroundColor(Theme.background),
  ]>
    currentUI
  </View>;
};

let init = app => {
  let win = App.createWindow(app, "CharToNum");

  let _update: Revery.UI.renderFunction = UI.start(win, <main />);
  ();
};

App.start(init);
