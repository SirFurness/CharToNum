open Revery;
open Revery.UI;
open Revery.UI.Components;

let%component make = (~letter, ~number, ~length: float, ()) => {
  let numberUI =
    switch(number) {
    | None => <Text text="0" fontSize=30. style=Style.[color(Theme.background), marginBottom (10)] />
    | Some(num) => <Text text=string_of_int(num) fontSize=30. style=Style.[color(Theme.green), marginBottom(10)] />
    };

  let%hook () = Hooks.effect(
    OnMount,
    () => {
      None
    },
  );
    
  <FadeIn>
    <Center>
      numberUI
      <Text text=letter fontSize=150. style=Style.[color(Theme.blue)] />
      <View style=Style.[
        width(212),
        height(21),
        border(~color=Theme.gray, ~width=3)]>
        <View style=Style.[backgroundColor(Theme.red),
          width(int_of_float(length *. 206.0)),
          height(18),
          borderBottom(~color=Theme.gray, ~width=3)]/>
      </View>
    </Center>
  </FadeIn>
};
