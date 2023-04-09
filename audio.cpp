#include "game.h"
#include "audio.h"
Audio::Audio()
{
}
void Audio::OpenAudio(const char* filename)
{
    Mix_Chunk* sound = Mix_LoadWAV(filename);
    while(Mix_Playing(-1) != 0);
    Mix_FreeChunk(sound);
    Mix_CloseAudio();
    SDL_Quit();
}
