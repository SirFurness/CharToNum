open Revery;
open Revery.UI;
open Revery.UI.Components;
open Component_Utils;

let make = (~dispatch, ()) => {
  <FadeIn>
    <Center>
      <Text
        text="Type the number"
        fontSize=30.
        style=Style.[color(Theme.gray)]
      />
      <Text
        text="corresponding to the letter"
        fontSize=30.
        style=Style.[color(Theme.gray), marginBottom(50)]
      />
      <Clickable onClick={() => dispatch(Actions.BeginCountdown)}>
        <Text text="Start" fontSize=80. style=Style.[color(Theme.blue)] />
      </Clickable>
    </Center>
  </FadeIn>;
};
