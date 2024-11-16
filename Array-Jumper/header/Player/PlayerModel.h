#pragma once
namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	private: 
			
		PlayerState player_state;
		int current_position;

		const int max_lives = 3;
		int current_lives ;

			
	public:
		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		int getCurrentPosition();
		void setCurrentPosition(int new_position);

        void initialize();
		void resetPlayer();

		int getCurrentLives();
		void decrementLife();
		void resetPosition();
	};
}