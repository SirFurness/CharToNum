let reducer: (State.t, Actions.t) => State.t = (state, action) => {
	switch(action) {
	| BeginCountdown =>
		let action = Actions.CountdownActions.Init;
		{...state, currentPage: Countdown, countdown: CountdownReducer.reducer(state.countdown, action)}
	| Start => 
		let action = Actions.CharToNumActions.Init;
		{...state, currentPage: CharToNum, charToNum: CharToNumReducer.reducer(state.charToNum, action)}
	| Stop(score, letter, letterNumber) => 
		let action = Actions.GameOverActions.Init(score, letter, letterNumber);
		{...state, currentPage: GameOver, gameOver: GameOverReducer.reducer(state.gameOver, action)}
	| Countdown(a) => {...state, countdown: CountdownReducer.reducer(state.countdown, a)}
	| CharToNum(a) => {...state, charToNum: CharToNumReducer.reducer(state.charToNum, a)}
	| GameOver(a) => {...state, gameOver: GameOverReducer.reducer(state.gameOver, a)}
	};
};
