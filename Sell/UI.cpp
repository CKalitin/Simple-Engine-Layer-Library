#include "UI.hpp"

Element::Element(Vector2 _pos, Vector2 _scale, SDL_Texture* _tex) : pos(_pos), scale(_scale), tex(_tex) {
	int w, h;
	SDL_QueryTexture(_tex, NULL, NULL, &w, &h); // Get pixel dimensions of texture

	// Set variables of currentFrame
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = w;
	currentFrame.h = h;
}

void Element::Move(Vector2 _pos) {
	pos.x = _pos.x;
	pos.y = _pos.y;
}

UIManager::UIManager(Vector2 _windowDimensions, RenderWindow* _renderWindow) {
	windowDimensions = _windowDimensions;
	renderWindow = _renderWindow;
	windowXToY = _windowDimensions.x / _windowDimensions.y;
}

void UIManager::RenderElements() {
	for (Element& element : elements) { // Loop through entities
		Vector2 pos = Vector2(element.getPos().x * (windowDimensions.x / windowXToY), element.getPos().y * windowDimensions.y); // Set pos to window coordinates not normalized coordinates
		// Get size, y = window height * normalized ui coordinate y, x = window height * normalized ui coordinate y * (pixel width / pixel height)
		Vector2 size = Vector2((windowDimensions.y * element.getScale().y) * ((float)element.getCurrentFrame().w / (float)element.getCurrentFrame().h), windowDimensions.y * element.getScale().y);
		std::cout << element.getTex() << " | " << element.getCurrentFrame().w << ", " << element.getCurrentFrame().h << " | " << pos.x << ", " << pos.y << " | " << size.x << ", " << size.y << std::endl;
		renderWindow->Render(element.getTex(), element.getCurrentFrame(), pos, size); // Draw current entity
	}
}

Element* UIManager::InstantiateElement(Vector2 _pos, Vector2 _scale, SDL_Texture* _tex) {
    Element newElement = Element(_pos, _scale, _tex); // Create new Entity
    elements.push_back(newElement); // Add new Entity to entities list
    return &elements[elements.capacity() - 1]; // return memory position of new Entity in entities list
}

void UIManager::RemoveElement(Element* _element) {
	delete _element;
}