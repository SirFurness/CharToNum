open Revery;
open Revery.UI;
open Revery.UI.Components;

let%component make =
              (~delay=Time.zero, ~duration=Time.ms(750), ~children, ()) => {
  let%hook (animatedOpacity, _state, reset) =
    Hooks.animation(
      Animation.animate(duration)
      |> Animation.delay(delay)
      |> Animation.ease(Easing.ease)
      |> Animation.tween(0., 1.),
    );

  <View style=Style.[flexGrow(1), `Opacity(animatedOpacity)]>
    children
  </View>;
};
