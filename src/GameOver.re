open Revery;
open Revery.UI;
open Revery.UI.Components;

let make = (~score, ~bestScore, ~restart, ()) => {
  <FadeIn>
  <View style=Style.[flexDirection(`Column), alignItems(`Center)]>
    <Text text="Game Over" fontSize=80. style=Style.[color(Theme.red), marginTop(30)]/>
    <Text text={"Score: " ++ string_of_int(score)} fontSize=50. style=Style.[color(Theme.green), marginTop(50)]/>
    <Text text={"Best: " ++ string_of_int(bestScore)} fontSize=30. style=Style.[color(Theme.green), marginTop(8)]/>
    <Clickable onClick=restart>
      <Text text="Restart" fontSize=80. style=Style.[color(Theme.blue), marginTop(150)]/>
    </Clickable>
  </View>
  </FadeIn>
};
