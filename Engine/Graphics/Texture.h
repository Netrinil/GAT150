#pragma once
#include "Resource/Resource.h"
#include "Math/Vector2.h"
#include <SDL.h>

namespace ds
{
	class Texture : public Resource
	{
	public:
		bool Load(const std::string& name, void* data) override;

		Vector2 GetSize();

		friend class Renderer;
	private:
		SDL_Texture* texture{ nullptr };
		SDL_Renderer* renderer{ nullptr };
	};
}