open Revery;
open Revery.UI;
open Revery.UI.Components;

let main = () => {
  <View style=Style.[alignItems(`Center)]>
    <Text
      text="Type the corresponding number (1-26)"
      fontSize=20.
      style=Style.[marginTop(10)]
    />
  </View>;
};

let init = app => {
  Revery.App.initConsole();

  Timber.App.enable();
  Timber.App.setLevel(Timber.Level.perf);

  let win = App.createWindow(app, "CharToNum");

  let _update: Revery.UI.renderFunction = UI.start(win, <main />);
  ();
};

App.start(init);
