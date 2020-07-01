open Revery;
open Revery.UI;
open Revery.UI.Components;

type action =
  | UpdateTime;

let%component make = (~count, ~countdown, ~start, ()) => {
  let%hook () = Hooks.tick(countdown);

  if(count <= 0) {
  	start();
  };

  let count = if(count <= 0) {
  	""
  } 
  else {
  	string_of_int(count)
  };

  <FadeIn>
    <Center>
      <Text
        text=count
        fontSize=100.
        style=Style.[color(Theme.blue)]
      />
    </Center>
  </FadeIn>;
};
