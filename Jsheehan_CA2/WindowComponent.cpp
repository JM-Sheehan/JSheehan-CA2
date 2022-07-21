#include "WindowComponent.hpp"


WindowComponent::WindowComponent() {
	Setup("Window", sf::Vector2u(640, 480)); 
}

WindowComponent::WindowComponent(const std::string& title, const sf::Vector2u& size){
	Setup(title, size); 
}
WindowComponent::~WindowComponent() {
	Destroy(); 
}

void WindowComponent::Setup(const std::string title, const sf::Vector2u& size) {
	m_windowTitle = title;
	m_windowSize = size;
	m_isFullscreen = false;
	m_isDone = false;
	Create();
}

void WindowComponent::Create() {
	auto style = (m_isFullscreen ? sf::Style::Fullscreen
		: sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 },
		m_windowTitle, style);
}

void WindowComponent::Destroy() {
	m_window.close();
}

void WindowComponent::BeginDraw() {
	m_window.clear(sf::Color::Black); 
}

void WindowComponent::EndDraw() {
	m_window.display(); 
}

bool WindowComponent::IsDone() {
	return m_isDone; 
}

bool WindowComponent::IsFullscreen() {
	return m_isFullscreen; 
}


sf::RenderWindow* WindowComponent::GetRenderWindow() {
	return &m_window; 
}

sf::Vector2u WindowComponent::GetWindowSize() {
	return m_windowSize; 
}

void WindowComponent::ToggleFullscreen() {
	m_isFullscreen = !m_isFullscreen;
	m_window.close();
	Create();
}

void WindowComponent::Update() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_isDone = true;
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
			m_isDone = true; 
		}
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) {
			ToggleFullscreen(); 
		}
	}
}
