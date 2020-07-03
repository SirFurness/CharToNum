open Revery;
open Revery.UI;
open Revery.UI.Components;
open Actions;
open Component_Utils;

let%component make = (~state, ~dispatch, ()) => {
  let State.CharToNumState.{letter, guessedNumber, letterNumber, duration, length, score} = state;
  
  let%hook (newLength, _animState, resetLength) =
    Hooks.animation(
      Animation.(
        animate(Time.ms(int_of_float(duration))) |> tween(0., 1.0)
      ),
      ~active=true,
      ~onComplete=() => dispatch(Stop(score, letter, letterNumber))
    );

  if(length != newLength) {
    dispatch(CharToNum(CharToNumActions.NewLength(newLength)));
  };
  
  let numberUI =
    switch (guessedNumber) {
    | None => 
      <Text
        text="0"
        fontSize=30.
        style=Style.[color(Theme.background), marginBottom(10)]
      />
    | Some(num) =>
      if(letterNumber == num) {
        dispatch(CharToNum(CharToNumActions.CorrectGuess));
        resetLength();
      };
      
      // Hide the number if the guess is correct
      // to avoid distracting number flashing
      let newColor =
        if(letterNumber == num) {
          Theme.background;
        }
        else {
          Theme.green;
        };
        
      <Text
        text=string_of_int(num)
        fontSize=30.
        style=Style.[color(newColor), marginBottom(10)]
      />;
    };

  <FadeIn>
    <Center>
      numberUI
      <Text text=letter fontSize=150. style=Style.[color(Theme.blue)] />
      <View
        style=Style.[
          width(212),
          height(21),
          border(~color=Theme.gray, ~width=3),
        ]>
        <View
          style=Style.[
            backgroundColor(Theme.red),
            width(int_of_float(length *. 206.0)),
            height(18),
            borderBottom(~color=Theme.gray, ~width=3),
          ]
        />
      </View>
    </Center>
  </FadeIn>;
};
