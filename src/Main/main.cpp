////////////////////////////////////////////////////////////
//
// MiraiVN
// Copyright (C) 2014-2015 CORTIER Benoît (benoit.cortier@gmail.com), BOULMIER Jérôme (jerome.boulmier@outlook.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#include <iostream>

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

    mp::WindowManager windowManager;
    sf::RenderWindow &window = windowManager.getWindow();

    windowManager.setOptimalWinWidth(1280);
    windowManager.setOptimalWinHeight(1024);
    windowManager.setVideomodeWidth(1280);
    windowManager.setVideomodeHeight(1024);
    windowManager.setCursorVisible(true);
    windowManager.setFullscreen(false);
    windowManager.drawBorders();
    windowManager.create();

    mvn::Character *lomadriel = new mvn::Character("Lomadriel", sf::Color::Red);
    mvn::Character *enerto = new mvn::Character("Enerto", sf::Color::Green);

    mp::MouseManager mouseManager;

    sf::Texture texture;
    if (!texture.loadFromFile("resources/imgs/frame.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    mvn::DialogueSkin skin(sprite, sf::Vector2f(0.f, static_cast<float>(windowManager.getVideomodeHeight()) -200.f), "resources/fonts/UbuntuMono-R.ttf", 20, sf::Color::White, sf::Vector2f(5.f, -22.f), sf::Vector2f(15.f, 20.f));
    mvn::DialogueFrame dialogFrame(skin);
    mvn::DialogueManager dialogueManager(dialogFrame, 50, sf::Time::Zero, true);

    dialogueManager.addDialogue(lomadriel, "Ac ne quis a nobis hoc ita dici forte miretur, quod alia quaedam in hoc facultas sit ingeni, neque haec dicendi ratio aut disciplina, ne nos quidem huic uni studio penitus umquam dediti fuimus. Etenim omnes artes, quae ad humanitatem pertinent, habent quoddam commune vinculum, et quasi cognatione quadam inter se continentur.");
    dialogueManager.addDialogue(enerto, "Amor progredi ob habuit amicos contra Coriolano Coriolanus Numne cum num debuerunt ob si ferre ferre si num contra contra amicos si debuerunt debuerunt num patriam Coriolanus amor debuerunt cum videamus debuerunt iuvare si Coriolanus amicos debuerunt videamus debuerunt primum amici Coriolano id regnum primum arma debeat amicos debeat Maelium rem adpetentem debeat ob amici amor patriam in amicos amicitia debuerunt illi in debuerunt Vecellinum Coriolano Coriolanus amicos regnum Numne arma illi primum cum habuit placet in regnum Coriolano illi num num ferre primum num debeat debeat debeat illi regnum illi patriam amicos Maelium ferre in illi iuvare Vecellinum habuit.");

    mouseManager.addBinding("next", sf::Mouse::Left, [&dialogueManager] { 
        dialogueManager.next(); 
    }, mp::Binding::Mode::onPress);

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
                        mouseManager.enable();
                        break;
                    case sf::Event::LostFocus:
                        dialogueManager.disable();
                        mouseManager.disable();
                        break;
                    default:
                        break;
                }
            }
            mouseManager();
            dialogueManager(TimePerFrame);
        }

        window.clear(sf::Color(128, 128, 128, 255));
        window.draw(dialogFrame.getSprite());
        window.draw(dialogFrame.getName());
        window.draw(dialogFrame.getText());

        window.display();
    }

    return 0;
}