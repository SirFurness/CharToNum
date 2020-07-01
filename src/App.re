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

  let getRandomLetter = () => {
    String.make(1, Char.chr(Random.int(26)+Char.code('A')));
  };
  
  let%hook (letter, setLetter) = Hooks.state(getRandomLetter());
  let nextLetter = () => {
    setLetter(_ => getRandomLetter());
  };

  let%hook (score, setScore) = Hooks.state(0);
  let%hook (bestScore, setBestScore) = Hooks.state(0);
  
  let stop = () => {
    if(score > bestScore) {
      setBestScore(_ => score);
    }
    dispatch(Stop);
  };
  
  let%hook (number, setNumber) = Hooks.state(None);
  let initialDuration = 5000.;
  let%hook (duration, setDuration) = Hooks.state(initialDuration);
  let%hook (length, _animState, resetAnim) = Hooks.animation(Animation.(animate(Time.ms(int_of_float(duration))) |> tween(0., 1.0)), ~active=true, ~onComplete=() => {
    switch(state) {
    | CharToNum => stop()
    | _ => ()
    }
  });

  let next = () => {
    resetAnim();
    nextLetter();
    setNumber(_ => None);
    setDuration(prev => prev *. 0.9);
    setScore(prev => prev+1);
  }
  let start = () => {
    next();

    setDuration(_ => initialDuration);
    setScore(_ => 0);

    dispatch(Start);
  };

  let currentUI =
    switch (state) {
    | StartMenu => <StartMenu start />
    | CharToNum => <CharToNum letter number length/>
    | GameOver => <GameOver score bestScore restart=start/>
    };

  let isZeroBased = false;
  let letterNumber = {
    let letterNumber = Char.code(letter.[0]) - Char.code('A'); 
    if(isZeroBased) {
      letterNumber;
    }
    else {
      letterNumber+1;
    }
  };

  let isCorrectNumber = (number) => {
    number == letterNumber;
  };

  let newNumber = (digit) => {
    switch(number) {
    | None => digit
    | Some(prev) =>
      let newNum = 10*prev + digit;
      if(newNum > 99) {
        prev;
      }
      else {
        newNum;
      }
    }
  }
  
  let onDigit = (digit) => {
    switch(state) {
    | CharToNum =>
      let num = newNumber(digit);

      if(isCorrectNumber(num)) {
        next();
      }
      else {
        setNumber(_ => Some(num));
      }
    | _ => ()
    } 
  };

  let onDelete = () => {
    setNumber(prev =>
    switch(prev) {
    | None => None
    | Some(prev) => 
      if(prev < 10) {
        None;
      }
      else {
        Some(prev/10)
      }
    });
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
    <KeyboardInput onDigit onDelete />
    currentUI
  </View>;
};

let init = app => {
  Random.self_init();
  
  let win = App.createWindow(app, "CharToNum");

  let _update: Revery.UI.renderFunction = UI.start(win, <main />);
  ();
};

App.start(init);
