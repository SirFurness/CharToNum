open Revery;
open Revery.UI;
open Revery.UI.Components;
open Actions;
open Component_Utils;

let%component make = (~state, ~dispatch, ()) => {
  let%hook () = Hooks.tick(~tickRate=Time.ms(1000), (_dt) => dispatch(Countdown(CountdownActions.DecreaseCountdown)));

  let State.CountdownState.{count} = state;

  if (count <= 0) {
    dispatch(Start);
  };

  let count =
    if (count <= 0) {
      "";
    } else {
      string_of_int(count);
    };

  <FadeIn>
    <Center>
      <Text text=count fontSize=100. style=Style.[color(Theme.blue)] />
    </Center>
  </FadeIn>;
};
