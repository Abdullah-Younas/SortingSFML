#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

void TextDef(sf::Text &text, sf::Font &font, std::string valuestring, int txtSize, bool isBold) {
    text.setFont(font);
    text.setString(valuestring);
    text.setCharacterSize(txtSize);
    text.setFillColor(sf::Color::Black);
    if (isBold) {
        text.setStyle(sf::Text::Bold);
    }
    else {
        text.setStyle(sf::Text::Regular);
    }
}

void Hover(sf::Vector2i &mousePos, sf::RectangleShape &HoverShape, bool &shapeHover) {
    if (mousePos.x >= HoverShape.getPosition().x && mousePos.x <= HoverShape.getPosition().x + HoverShape.getSize().x &&
        mousePos.y >= HoverShape.getPosition().y && mousePos.y <= HoverShape.getPosition().y + HoverShape.getSize().y) {
        HoverShape.setFillColor(sf::Color::Green);
        shapeHover = true;
    }
    else {
        HoverShape.setFillColor(sf::Color(20, 200, 36));
        shapeHover = false;
    }
}

int main() {
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SORT!"); // creating window
    sf::RectangleShape block1(sf::Vector2f(20, 20));
    sf::RectangleShape block2(sf::Vector2f(20, 150));
    sf::RectangleShape block3(sf::Vector2f(20, 120));
    sf::RectangleShape block4(sf::Vector2f(20, 160));
    sf::RectangleShape block5(sf::Vector2f(20, 240));
    sf::RectangleShape block6(sf::Vector2f(20, 320));
    sf::RectangleShape block7(sf::Vector2f(20, 580));
    sf::RectangleShape block8(sf::Vector2f(20, 300));
    sf::RectangleShape block9(sf::Vector2f(20, 600));
    sf::RectangleShape block10(sf::Vector2f(20, 560));
    sf::RectangleShape block11(sf::Vector2f(20, 40));
    sf::RectangleShape block12(sf::Vector2f(20, 60));
    sf::RectangleShape block13(sf::Vector2f(20, 80));
    sf::RectangleShape block14(sf::Vector2f(20, 100));
    sf::RectangleShape block15(sf::Vector2f(20, 140));
    sf::RectangleShape block16(sf::Vector2f(20, 260));
    sf::RectangleShape block17(sf::Vector2f(20, 280));
    sf::RectangleShape block18(sf::Vector2f(20, 380));
    sf::RectangleShape block19(sf::Vector2f(20, 440));
    sf::RectangleShape block20(sf::Vector2f(20, 460));
    sf::RectangleShape block21(sf::Vector2f(20, 400));
    sf::RectangleShape block22(sf::Vector2f(20, 220));
    sf::RectangleShape block23(sf::Vector2f(20, 180));
    sf::RectangleShape block24(sf::Vector2f(20, 200));
    sf::RectangleShape block25(sf::Vector2f(20, 340));
    sf::RectangleShape block26(sf::Vector2f(20, 360));
    sf::RectangleShape block27(sf::Vector2f(20, 420));
    sf::RectangleShape block28(sf::Vector2f(20, 480));
    sf::RectangleShape block29(sf::Vector2f(20, 500));
    sf::RectangleShape block30(sf::Vector2f(20, 520));
    sf::RectangleShape blocks[] = { block1, block2, block3, block4, block5, block6,block7,block8,block9,block10,block11, block12, block13, block14, block15, block16,block17,block18,block19,block20,block21, block22, block23, block24, block25, block26,block27,block28,block29,block30};
    int numblocks = 30;

    // Sorting animation
    for (int i = 0; i < numblocks; i++) {
        for (int j = 0; j < numblocks - 1 - i; j++) {
            blocks[j].setFillColor(sf::Color::Red);
            if (blocks[j].getSize().y > blocks[j + 1].getSize().y) {
                sf::Vector2f tempSize = blocks[j].getSize();
                blocks[j].setSize(blocks[j + 1].getSize());
                blocks[j + 1].setSize(tempSize);

                // Clear and draw the updated blocks
                window.clear();
                for (int k = 0; k < numblocks; k++) {
                    blocks[k].setPosition(20.0f + 25.0f * k, 300.0f);
                    window.draw(blocks[k]);
                }
                window.display();

                // Introduce a delay (adjust the sleep duration as needed)
                sf::sleep(sf::milliseconds(50));

                blocks[j].setFillColor(sf::Color(255, 255, 255));
            }
        }
    }

    sf::Font font;
    if (!font.loadFromFile("G:\\abdullah\\Abdullah(Dont Delete Any thing)\\FONTS\\Rubik_Mono_One\\RMOR.ttf")) {
        std::cout << "Cant load/find the file" << '\n';
    }

    float scrollSpeed = 0.01f; // Adjust scrolling speed as needed

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                std::cout << "Clicking\n";
            }
        }

        window.clear(); // clearing window before using

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        for (int i = 0; i < numblocks; i++) {
            window.draw(blocks[i]);
        }
        window.display(); // displaying everything
    }

    return 0;
}
