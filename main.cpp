#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <string>
#include <fstream>
#include "game.h"

using namespace sf;
using namespace std;

constexpr int FIELD_WIGTH = 30, FIELD_HIGHT = 20, CELL_SIZE = 32;

inline string getBestScoreString(Game game)
{
	return string("EASY BEST SCORE: " + to_string(game.getBestScore(gameDifficulty::EASY)) + "\n" +
		"MEDIUM BEST SCORE: " + to_string(game.getBestScore(gameDifficulty::MEDIUM)) + "\n" +
		"HARD BEST SCORE: " + to_string(game.getBestScore(gameDifficulty::HARD)));
}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	RenderWindow window(VideoMode(FIELD_WIGTH * CELL_SIZE, FIELD_HIGHT * CELL_SIZE), "Snake", Style::Close);
	Image icon; icon.loadFromFile("resources\\icon.png");
	window.setIcon(64, 64, icon.getPixelsPtr());
	Color background(45, 45, 45);

	SoundBuffer eatSoundBuffer; eatSoundBuffer.loadFromFile("resources\\eat.wav");
	Sound eatSound; eatSound.setBuffer(eatSoundBuffer);

	Font font; font.loadFromFile("resources\\font.ttf");

	Game game(FIELD_WIGTH, FIELD_HIGHT, CELL_SIZE, &window, eatSound, font);

	ifstream saveDataRead("save_data");
	if (saveDataRead.is_open()) {
		string buffer;
		int saveData[3];
		for (size_t i = 0; i < 3; i++) {
			getline(saveDataRead, buffer);
			saveData[i] = stoi(buffer);
		}
		game.setBestScore(saveData);
	}
	saveDataRead.close();

	Text bestScoreText(getBestScoreString(game), font, 20);
	Text menuText("\t\tSNAKE\nSelect the game mode:\n1.Eazy\n2.Medium\n3.Hard", font, 50);
	menuText.setPosition(180, 150);
	Text guideText("press the number button to select", font, 20);
	guideText.setPosition(180, 450);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {
				bool isWindowClose = false;
				switch (event.key.code) {
				case Keyboard::Num1:
					isWindowClose = game.start(gameDifficulty::EASY);
					break;
				case Keyboard::Num2:
					isWindowClose = game.start(gameDifficulty::MEDIUM);
					break;
				case Keyboard::Num3:
					isWindowClose = game.start(gameDifficulty::HARD);
					break;
				}
				bestScoreText.setString(getBestScoreString(game));
				if (isWindowClose)
					window.close();
			}
		}
		window.clear(background);
		window.draw(bestScoreText);
		window.draw(menuText);
		window.draw(guideText);
		window.display();
	}

	ofstream saveDataWrite("save_data");
	for (int i = 0; i < 3; i++) {
		saveDataWrite << game.getBestScore(static_cast<gameDifficulty>(i)) << endl;
	}
	saveDataWrite.close();

	return 0;
}
