open Revery;
open Revery.UI;
open Revery.UI.Components;

let make = (~start, ()) => {
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
      <Clickable onClick=start>
        <Text text="Start" fontSize=80. style=Style.[color(Theme.blue)] />
      </Clickable>
    </Center>
  </FadeIn>;
};
