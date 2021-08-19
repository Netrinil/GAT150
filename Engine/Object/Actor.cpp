#include "Actor.h"
#include "Graphics/Renderer.h"
#include "Math/MathUtils.h"
#include "Math/Random.h"
#include "Component/GraphicsComponent.h"
#include <algorithm>

namespace ds
{
	void Actor::Update(float dt)
	{
		std::for_each(components.begin(), components.end(), [](auto& component) { component->Update(); });

		transform.Update();
		std::for_each(children.begin(), children.end(), [](auto& child) { child->transform.Update(child->parent->transform.matrix); });
	}

	void Actor::Draw(Renderer* renderer)
	{
		std::for_each(components.begin(), components.end(), [renderer](auto& component) 
		{ 
			if (dynamic_cast<GraphicsComponent*>(component.get()))
			{
				dynamic_cast<GraphicsComponent*>(component.get())->Draw(renderer);
			}
		});

		std::for_each(children.begin(), children.end(), [renderer](auto& child) { child->Draw(renderer); });
	}

	void Actor::OnCollision(Actor* actor)
	{

	}

	void Actor::AddChild(std::unique_ptr<Actor> actor)
	{
		actor->parent = this;

		children.push_back(std::move(actor));
	}

	float Actor::GetRadius()
	{
		//return std::max(texture->GetSize().x/2, texture->GetSize().y/2);

		return 0;//(texture) ? texture->GetSize().Length() * 0.5f * transform.scale.x : 0;
	}
}