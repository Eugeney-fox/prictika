#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

const int H = 21;
const int W = 19;

const int ts = 25;

int q = 0;
bool life = true;

String TileMap[H] = {
"AAAAAAAAAAAAAAAAAAA",
"A1       A       2A",
"A AA AAA A AAA AA A",
"A        A        A",
"A AA A AAAAA A AA A",
"A    A   A   A    A",
"AAAA AAA A AAA AAAA",
"BBBA A       A ABBB",
"AAAA A AAAAA A AAAA",
"BBBB   ABBBA   BBBB",
"AAAA A AAAAA A AAAA",
"BBBA A       A ABBB",
"AAAA A AAAAA A AAAA",
"A        A        A",
"A AA AAA A AAA AA A",
"A  A     C     A  A",
"AA A A AAAAA A A AA",
"A    A   A   A    A",
"A AAAAAA A AAAAAA A",
"A3               4A",
"AAAAAAAAAAAAAAAAAAA",
};

class Player {
public:
	float frame = 0;

	void update() {
		frame += 0.01;
		if (frame > 5)
			frame -= 5;
	}

		
};



int main() {
	srand(time(0));
	RenderWindow window(VideoMode(W * ts, H * ts), "Maze!");
	Texture t;
	t.loadFromFile("C:/Users/Asus/source/repos/prictika/Paint/title.png");
	Sprite plat(t);

	Texture yw;
	yw.loadFromFile("C:/Users/Asus/source/repos/prictika/Paint/youwin.png");
	Sprite youwin(yw);
	youwin.setPosition(100, 210);

	Texture yl;
	yl.loadFromFile("C:/Users/Asus/source/repos/prictika/Paint/youlose.png");
	Sprite youlose(yl);
	youlose.setPosition(100, 210);

	Player p;
	

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			
		}

		if (q < 171 && life) {
			p.update();
		}
		window.clear(Color::Black);

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				if (TileMap[i][j] == 'A')
					plat.setTextureRect(IntRect(0, 0, ts, ts));
				if (TileMap[i][j] == 'C')
					plat.setTextureRect(IntRect(ts * int(p.frame), ts, ts, ts));
				if (TileMap[i][j] == ' ')
					plat.setTextureRect(IntRect(ts, 0, ts, ts));
				
				if (TileMap[i][j] == 'B')
					continue;

				plat.setPosition(j * ts, i * ts);
				window.draw(plat);
			}

	

		window.display();
	}

	return 0;
}