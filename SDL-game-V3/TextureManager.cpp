
#pragma once
#include "TextureManager.h"
#include "SDL_image.h"
#include "SDL.h"
#include "Game.h"
#include <stdexcept>

TextureManager* TextureManager::s_pInstance = 0;



bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{

	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

	if (pTempSurface == 0)
	{
		std::cout << IMG_GetError();
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

	SDL_FreeSurface(pTempSurface);

	if (pTexture != 0)
	{
		m_textureMap[id] = pTexture;
		return true;
	}
	else
		throw std::runtime_error("Error loading " + fileName + ": " + SDL_GetError());

	throw std::runtime_error("Error loading " + fileName + ": " + SDL_GetError());
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}



void TextureManager::drawFrame(std::string id, int x, int y, int	width, int height, int currentRow, int currentFrame, SDL_Renderer	*pRenderer)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,		&destRect, 0, 0, SDL_FLIP_NONE);
}




void TextureManager::clearTextureMap()
{
	m_textureMap.clear();
}

void TextureManager::clearFromTextureMap(std::string id)
{
	m_textureMap.erase(id);
}

