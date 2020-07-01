open Revery;
open Revery.UI;
open Revery.UI.Components;

let make = (~letter, ~number, ()) => {
  let numberUI =
    if(number == "") {
      <Text text="0" fontSize=30. style=Style.[color(Theme.background), marginBottom (10)] />
    }
    else {
      <Text text=number fontSize=30. style=Style.[color(Theme.green), marginBottom(10)] />
    };
    
  <Center>
    numberUI
    <Text text=letter fontSize=150. style=Style.[color(Theme.blue)] />
    <View style=Style.[backgroundColor(Theme.red),
      width(212),
      height(21),
      border(~color=Theme.gray, ~width=3)]/>
  </Center>
};
