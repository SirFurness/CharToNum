open Revery;
open Revery.UI;
open Revery.UI.Components;
open Component_Utils;

let make = (~state, ~dispatch, ()) => {
  let State.GameOverState.{score, bestScore, letter, letterNumber} = state;
  
  <FadeIn>
    <View style=Style.[flexDirection(`Column), alignItems(`Center)]>
      <Text
        text="Game Over"
        fontSize=80.
        style=Style.[color(Theme.red), marginTop(30)]
      />
      <Text
        text={letter ++ " is " ++ string_of_int(letterNumber)}
        fontSize=30.
        style=Style.[color(Theme.red), marginTop(8)]
      />
      <Text
        text={"Score: " ++ string_of_int(score)}
        fontSize=50.
        style=Style.[color(Theme.green), marginTop(50)]
      />
      <Text
        text={"Best: " ++ string_of_int(bestScore)}
        fontSize=30.
        style=Style.[color(Theme.green), marginTop(8)]
      />
      <Clickable onClick={() => dispatch(Actions.BeginCountdown)}>
        <Text
          text="Restart"
          fontSize=80.
          style=Style.[color(Theme.blue), marginTop(90)]
        />
      </Clickable>
    </View>
  </FadeIn>;
};
