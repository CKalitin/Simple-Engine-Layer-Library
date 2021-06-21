#include "UI.hpp"

Element::Element(Vector2 _pos, Vector2 _scale, SDL_Texture* _tex, InputManager* _inputManager, Vector2Int _windowDimensions) : pos(_pos), scale(_scale), tex(_tex), inputManager(_inputManager), windowDimensions(_windowDimensions) {
	int w, h;
	SDL_QueryTexture(_tex, NULL, NULL, &w, &h); // Get pixel dimensions of texture

	// Set variables of currentFrame
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = w;
	currentFrame.h = h;

	windowXtoY = (float)_windowDimensions.x / (float)_windowDimensions.y;
}

void Element::Move(Vector2 _pos) {
	pos.x = _pos.x;
	pos.y = _pos.y;
}

bool Element::isClicked() {
	if (inputManager->isMouseButtonDown(0)) { // If left mouse button is down
		int xPos = pos.x * (windowDimensions.x / windowXtoY); // X of element in window pixels
		if (inputManager->getMousePosition().x < xPos + (currentFrame.w) && inputManager->getMousePosition().x > xPos - (currentFrame.w)) { // If X is within texture
			int yPos = pos.y * windowDimensions.y; // Y of element in window pixels
			if (inputManager->getMousePosition().y < yPos + (currentFrame.h) && inputManager->getMousePosition().y > yPos - (currentFrame.h)) { // If Y is within texture
				selected = !selected;
				return true;
			}
		}
		selected = false; // If left mouse button down, not selected
	}
	return false;
}

UIManager::UIManager(Vector2Int _windowDimensions, RenderWindow* _renderWindow, InputManager* _inputManager) {
	windowDimensions = _windowDimensions;
	windowXToY = (float)_windowDimensions.x / (float)_windowDimensions.y;
	renderWindow = _renderWindow;
	inputManager = _inputManager;
}

void UIManager::RenderElements() {
	for (Element& element : elements) { // Loop through entities
		Vector2 pos = Vector2(element.getPos().x * (windowDimensions.x / windowXToY), element.getPos().y * windowDimensions.y); // Set pos to window coordinates not normalized coordinates
		// Get size, y = window height * normalized ui coordinate y, x = window height * normalized ui coordinate y * (pixel width / pixel height)
		Vector2 size = Vector2((windowDimensions.y * element.getScale().y) * ((float)element.getCurrentFrame().w / (float)element.getCurrentFrame().h), windowDimensions.y * element.getScale().y);
		renderWindow->Render(element.getTex(), element.getCurrentFrame(), pos, size); // Draw current entity
		//std::cout << element.getPos() << std::endl;
	}
	//std::cout << inputManager << std::endl;
}

Element* UIManager::InstantiateElement(Vector2 _pos, Vector2 _scale, SDL_Texture* _tex) {
	Element newElement = Element(_pos, _scale, _tex, inputManager, windowDimensions);
    elements.push_back(newElement); // Create new entity and add to entities list
    return &elements.back(); // return memory position of new Entity in entities list
}

void UIManager::RemoveElement(Element* _element) {
	//elements.erase(std::remove(elements.begin(), elements.end(), _element), elements.end());
	delete _element;
}

void UIManager::SetWindowDimensions(Vector2Int _windowDimensions) {
	windowDimensions = _windowDimensions;
	windowXToY = (float)_windowDimensions.x / (float)_windowDimensions.y;
}
