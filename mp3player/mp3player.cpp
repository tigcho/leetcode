#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

bool init() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "SDL_mixer Error: " << Mix_GetError() << std::endl;
        return false;
    }

    return true;
}

void close() {
    Mix_Quit();
    SDL_Quit();
}

void playMP3(const char* file) {
    Mix_Music* music = Mix_LoadMUS(file);
    if (!music) {
        std::cout << "Failed to load music: " << Mix_GetError() << std::endl;
        return;
    }

    Mix_PlayMusic(music, 1);

    std::cout << "Playing..." << std::endl;
    while (Mix_PlayingMusic()) {
        SDL_Delay(100); // Check every 100ms
    }

    std::cout << "Music finished!" << std::endl;

    Mix_FreeMusic(music);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <MP3 file path>" << std::endl;
        return -1;
    }

    if (!init()) {
        return -1;
    }

    playMP3(argv[1]);

    close();
    return 0;
}
