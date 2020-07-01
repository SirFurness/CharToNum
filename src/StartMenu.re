open Revery;
open Revery.UI;
open Revery.UI.Components;

let make = (~start, ()) => {
  <View>
    <Text text="StartMenu" />
    <Button title="click" onClick=start/>
  </View>
};
