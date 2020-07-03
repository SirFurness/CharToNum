module CharToNumActions = CharToNumActions;
module GameOverActions = GameOverActions;
module CountdownActions = CountdownActions;

type t =
	| BeginCountdown
	| Start
	| Stop(int, string, int)
	| CharToNum(CharToNumActions.action)
	| GameOver(GameOverActions.action)
	| Countdown(CountdownActions.action);
