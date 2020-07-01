open Revery;
open Revery.UI;
open Revery.UI.Components;

let make = (~stop, ()) => {
  <Center>
    <Text text="A" fontSize=150. style=Style.[color(Theme.blue)] />
    <View style=Style.[backgroundColor(Theme.red),
      width(212),
      height(21),
      border(~color=Theme.gray, ~width=3)]/>
  </Center>;
};
