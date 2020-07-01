open Revery;
open Revery.UI;

module Styles = {
  open Style;

  let text = (~yOffset) => [
    //color(Color.hex(Theme.darkBlue)),
    transform([Transform.TranslateY(yOffset)]),
  ];
};

let%component make = (~delay: Time.t, ~text: string, ~fontSize, ~style, ()) => {
  let%hook (yOffset, _state, _reset) =
    Hooks.animation(
      Animation.animate(Time.ms(500))
      |> Animation.delay(delay)
      |> Animation.ease(Easing.ease)
      |> Animation.tween(50., 0.),
    );

  let%hook (animatedOpacity, _state, _reset) =
    Hooks.animation(
      Animation.animate(Time.ms(750))
      |> Animation.delay(delay)
      |> Animation.ease(Easing.ease)
      |> Animation.tween(0., 1.),
    );

  <Opacity opacity=animatedOpacity>
    <Text fontSize style text />
  </Opacity>;
};
