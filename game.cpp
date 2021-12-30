#include "game.hpp"
#include "streets.hpp"
#include <vector>
#include <list>

bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//TTF_Init();
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window

		gWindow = SDL_CreateWindow("CLICK AND TYPE: the night sky was the deepest sapphire; Claire realised that she had not observed its beauty until now.", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	assets = loadTexture("");

	gTexture = loadTexture("Main menu.jpg");
	if (gTexture == NULL) //assets == NULL ||
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	gMusic = Mix_LoadMUS( "01 Amplifier (Imran Khan).wav");
    if( gMusic == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }
	return success;
}


void Game::close()
{
	SDL_DestroyTexture(assets);
	assets = NULL;
	SDL_DestroyTexture(gTexture);

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	Mix_FreeMusic( gMusic );
    gMusic = NULL;
	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture *newTexture = NULL;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		cout << "Texture loaded success" << endl;
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void Game::write(string keychar)
{

	cur_time = time(0) - start_time;

	int length_text, length_sentence, wpm, accuracy;
	int mistakes = 0;
	string text = "";
	cout << endl;
	//length_sentence = sentence.length();
	time_t start;
	cur_string += keychar;
	time_t end;
	string input;
	//cur_string += keychar;
	input = text + cur_string;

	//input = cur_time + "\n" + input;

	TTF_Init();

	TTF_Font *font = TTF_OpenFont("arial.ttf", 25);
	SDL_Color color = {0, 0, 0};
	SDL_Surface *surface = TTF_RenderText_Solid(font,
												input.c_str(), color);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(gRenderer, surface);

	//cout << wpm << endl;
	//accuracy = 100 - ((mistakes / length_text) * 100);

	int texW = 0;
	int texH = 0;
	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	SDL_Rect dstrect = {0, 50, texW, texH};

	SDL_RenderCopy(gRenderer, texture, NULL, &dstrect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	TTF_CloseFont(font);
	TTF_Quit();
}

//void Game::writetime()
//{
//	cur_time = time(0) - start_time;
//	cout << to_string(cur_time).c_str() << endl;
//	TTF_Init();
//
//	TTF_Font *font = TTF_OpenFont("arial.ttf", 25);
//	SDL_Color color = {0, 0, 0};
//	SDL_Surface *surface = TTF_RenderText_Solid(font,
//												to_string(cur_time).c_str(), color);
//	SDL_Texture *texture = SDL_CreateTextureFromSurface(gRenderer, surface);
//
//	//cout << wpm << endl;
//	//accuracy = 100 - ((mistakes / length_text) * 100);
//
//	int texW = 0;
//	int texH = 0;
//	SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
//	SDL_Rect dstrect = {0, 0, texW, texH};
//
//	SDL_RenderCopy(gRenderer, texture, NULL, &dstrect);
//
//	SDL_DestroyTexture(texture);
//	SDL_FreeSurface(surface);
//	TTF_CloseFont(font);
//	TTF_Quit();
//}

void Game::run()
{
	int count = 0;
	bool quit = false;
	SDL_Event e;
	Mix_PlayMusic(gMusic, -1);
	Streets Streets(gRenderer, assets);
	while (!quit)
	{
		//writetime();
		string inputSentence = "the night sky was the deepest sapphire; claire realised that she had not observed its beauty until now.";
		char nextchar;
		char inputchar;
		// int count=0;
		nextchar = inputSentence[count];
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			//write("Welcome");

			if (e.type == SDL_MOUSEBUTTONDOWN)
			{

				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse, &yMouse);
				// Streets.createObject(xMouse, yMouse, 3);
				if ((xMouse >= 255 && xMouse <= 760) && (yMouse >= 201 && yMouse <= 270))
				{
					//assets = loadTexture("ap2.png");
					//write("Welcome");

					gTexture = loadTexture("bgboat.png");
					assets = loadTexture("assets.png");
					Streets.createObject(xMouse, yMouse, 2);
				}
				else if ((xMouse >= 255 && xMouse <= 760) && (yMouse >= 308 && yMouse <= 370))
				{

					gTexture = loadTexture("bgap1.jpg");
					assets = loadTexture("assets.png");
					Streets.createObject(xMouse, yMouse, 1);
				}
				else if ((xMouse >= 255 && xMouse <= 760) && (yMouse >= 410 && yMouse <= 470))
				{

					gTexture = loadTexture("bgcar1.jpg");
					assets = loadTexture("assets.png");
					Streets.createObject(xMouse, yMouse, 3);
				}
				Streets.updateAssets(assets);
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_a)
			{
				if ('a' == nextchar)
				{
					Streets.z = 0;
					write("a");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_b)
			{
				if ('b' == nextchar)
				{
					Streets.z = 0;
					write("b");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_c)
			{
				if ('c' == nextchar)
				{
					Streets.z = 0;
					write("c");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_d)
			{
				if ('d' == nextchar)
				{
					Streets.z = 0;
					write("d");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_e)
			{
				if ('e' == nextchar)
				{
					Streets.z = 0;
					write("e");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_f)
			{
				if ('f' == nextchar)
				{
					Streets.z = 0;
					write("f");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_g)
			{
				if ('g' == nextchar)
				{
					Streets.z = 0;
					write("g");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_h)
			{
				if ('h' == nextchar)
				{
					Streets.z = 0;
					write("h");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_i)
			{
				if ('i' == nextchar)
				{
					Streets.z = 0;
					write("i");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_j)
			{
				if ('j' == nextchar)
				{
					Streets.z = 0;
					write("j");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_k)
			{
				if ('k' == nextchar)
				{
					Streets.z = 0;
					write("k");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_l)
			{
				if ('l' == nextchar)
				{
					Streets.z = 0;
					write("l");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_m)
			{
				if ('m' == nextchar)
				{
					Streets.z = 0;
					write("m");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_n)
			{
				if ('n' == nextchar)
				{
					Streets.z = 0;
					write("n");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_o)
			{
				if ('o' == nextchar)
				{
					Streets.z = 0;
					write("o");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p)
			{
				if ('p' == nextchar)
				{
					Streets.z = 0;
					write("p");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q)
			{
				if ('q' == nextchar)
				{
					Streets.z = 0;
					write("q");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_r)
			{
				if ('r' == nextchar)
				{
					Streets.z = 0;
					write("r");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_s)
			{
				if ('s' == nextchar)
				{
					Streets.z = 0;
					write("s");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_t)
			{
				if ('t' == nextchar)
				{
					Streets.z = 0;
					write("t");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_u)
			{
				if ('u' == nextchar)
				{
					Streets.z = 0;
					write("u");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_v)
			{
				if ('v' == nextchar)
				{
					Streets.z = 0;
					write("v");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_w)
			{
				if ('w' == nextchar)
				{
					Streets.z = 0;
					write("w");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_x)
			{
				if ('x' == nextchar)
				{
					Streets.z = 0;
					write("x");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_y)
			{
				if ('y' == nextchar)
				{
					Streets.z = 0;
					write("y");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_z)
			{
				if ('z' == nextchar)
				{
					Streets.z = 0;
					write("z");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
			{
				if (' ' == nextchar)
				{
					Streets.z = 0;
					write(" ");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_1)
			{
				if ('1' == nextchar)
				{
					Streets.z = 0;
					write("1");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_2)
			{
				if ('2' == nextchar)
				{
					Streets.z = 0;
					write("2");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_3)
			{
				if ('3' == nextchar)
				{
					Streets.z = 0;
					write("3");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_4)
			{
				if ('4' == nextchar)
				{
					Streets.z = 0;
					write("4");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_5)
			{
				if ('5' == nextchar)
				{
					Streets.z = 0;
					write("5");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_6)
			{
				if ('6' == nextchar)
				{
					Streets.z = 0;
					write("6");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_7)
			{
				if ('7' == nextchar)
				{
					Streets.z = 0;
					write("7");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_8)
			{
				if ('8' == nextchar)
				{
					Streets.z = 0;
					write("8");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_9)
			{
				if ('9' == nextchar)
				{
					Streets.z = 0;
					write("9");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_COMMA)
			{
				if (',' == nextchar)
				{
					Streets.z = 0;
					write(",");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_EQUALS)
			{
				if ('=' == nextchar)
				{
					Streets.z = 0;
					write("=");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_MINUS)
			{
				if ('-' == nextchar)
				{
					Streets.z = 0;
					write("-");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_PERIOD)
			{
				if ('.' == nextchar)
				{
					Streets.z = 0;
					write(".");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SEMICOLON)
			{
				if (';' == nextchar)
				{
					Streets.z = 0;
					write(";");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SLASH)
			{
				if ('/' == nextchar)
				{
					Streets.z = 0;
					write("/");
					count += 1;
					nextchar = inputSentence[count];
				}
				else
				{
					Streets.z = 1;
				}
			}
		}

		SDL_RenderClear(gRenderer);						 //removes everything from renderer
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL); //Draws background to renderer
		//***********************draw the objects here********************
		write("");
		Streets.drawObjects();
		//****************************************************************
		SDL_RenderPresent(gRenderer); //displays the updated renderer

		SDL_Delay(200); //causes sdl engine to delay for specified miliseconds
	}
}
