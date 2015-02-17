#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>

#include <MiraiProject/util/WindowManager.hpp>
#include <MiraiProject/inputManager/MouseManager.hpp>

#include "character/Character.hpp"
#include "display/DialogueFrame.hpp"
#include "display/DialogueSkin.hpp"
#include "display/DialogueManager.hpp"

using namespace std;
//using namespace mvn;

const sf::Time TimePerFrame = sf::seconds(1.f/60.f);
const sf::Time letterSpeed = sf::seconds(1.f/10.f);
int main()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    mp::WindowManager mainWindowManager;
    sf::RenderWindow &window = mainWindowManager.getWindow();

    mainWindowManager.setOptimalWinWidth(1280);
    mainWindowManager.setOptimalWinHeight(1024);
    mainWindowManager.setVideomodeWidth(1280);
    mainWindowManager.setVideomodeHeight(1024);
    mainWindowManager.setCursorVisible(true);
    mainWindowManager.setFullscreen(false);
    mainWindowManager.drawBorders();
    mainWindowManager.create();

    mvn::Character *lomadriel = new mvn::Character("Lomadriel", sf::Color::Red);
    mvn::Character *enerto = new mvn::Character("Enerto", sf::Color::Green);

    mp::MouseManager mouseManager;

    sf::Texture texture;
    if (!texture.loadFromFile("frame.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;

    mvn::DialogueSkin skin(sprite, sf::Vector2f(0.f, static_cast<float>(mainWindowManager.getVideomodeHeight()) -200.f), "arial.ttf", 20, sf::Color::White, sf::Vector2f(5.f, -22.f), sf::Vector2f(15.f, 20.f));
    mvn::DialogueFrame mainDialogFrame(skin);
    mvn::DialogueManager dialogueManager(mainDialogFrame, 10, sf::seconds(.5f), false);

    dialogueManager.addDialogue(lomadriel, "I'm Lomadriel.");
    dialogueManager.addDialogue(enerto, "I'm Enerto.");

    mouseManager.addBinding("next", sf::Mouse::Left, [&dialogueManager] { 
        dialogueManager.next(); 
    });

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;

        sf::Event event;
        while(timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            while (window.pollEvent(event))
            {
                switch(event.type)
                {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::GainedFocus:
                        dialogueManager.enable();
                        break;
                    case sf::Event::LostFocus:
                        dialogueManager.disable();
                        break;
                    default:
                        break;
                }
            }
            mouseManager();
            dialogueManager(TimePerFrame);
        }

        window.clear(sf::Color(128, 128, 128, 255));
        window.draw(mainDialogFrame.getSprite());
        window.draw(mainDialogFrame.getName());
        window.draw(mainDialogFrame.getText());

        window.display();
    }
    cout << "Closed by precedent line" << endl;
    return 0;

    /*std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    for (std::size_t i = 0; i < modes.size(); ++i)
    {
        sf::VideoMode mode = modes[i];
        std::cout << "Mode #" << i << ": "
                  << mode.width << "x" << mode.height << " - "
                  << mode.bitsPerPixel << " bpp" << std::endl;
    }
    // Create a window with the same pixel depth as the desktop
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();*/
}