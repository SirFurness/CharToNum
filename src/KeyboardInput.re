open Revery;
open Revery.UI;
open Revery.UI.Components;

type state = {
  ref: option(node),
  hasFocus: bool,
};

type action =
  | Focused(bool)
  | SetRef(node);

let reducer = (action, state) =>
  switch (action) {
  | Focused(v) => {...state, hasFocus: v}
  | SetRef(v) => {...state, ref: Some(v)}
  };

let%component make = (~onDigit, ~onDelete, ~onKey, ()) => {
  let%hook (v, dispatch) =
    Hooks.reducer(~initialState={ref: None, hasFocus: false}, reducer);

  let%hook () =
    Hooks.effect(
      Always,
      () => {
        if (!v.hasFocus) {
          switch (v.ref) {
          | Some(v) => Focus.focus(v)
          | None => ()
          };
        };
        None;
      },
    );

  let onBlur = () => {
    dispatch(Focused(false));
  };
  let onFocus = () => {
    dispatch(Focused(true));
  };

  let onKeyDown = (event: NodeEvents.keyEventParams) => {
    if (!event.repeat
        && Key.Keycode.digit0 <= event.keycode
        && event.keycode <= Key.Keycode.digit9) {
      onDigit(int_of_string(Key.Scancode.getName(event.scancode)));
    } else if (event.keycode == Key.Keycode.delete
               || event.keycode == Key.Keycode.backspace) {
      onDelete();
    };

    onKey();
  };

  <View
    ref={r => dispatch(SetRef(r))}
    onBlur
    onFocus
    style=Style.[position(`Absolute), width(1), height(1)]
    onKeyDown
  />;
};
