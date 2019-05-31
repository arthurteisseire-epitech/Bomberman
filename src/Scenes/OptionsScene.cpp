/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include <climits>
#include <irrlicht/IVideoDriver.h>
#include <irrlicht/IGUIButton.h>
#include "OptionsScene.hpp"
#include "PlayersSettingsSave.hpp"
#include "PlaceRectangle.hpp"

ind::ButtonPosition::ButtonPosition(const irr::core::dimension2df center_, const irr::core::dimension2df size_)
        : center(center_), size(size_)
{}

ind::OptionsScene::OptionsScene() :
        AScene(),
        gui(_manager->getGUIEnvironment())
{
    irr::video::IVideoDriver *driver = gui->getVideoDriver();
    const irr::core::dimension2d<irr::u32> size = gui->getVideoDriver()->getScreenSize();

    initButtons({size.Width, size.Height});
    background = driver->getTexture("./assets/bomb_background.png");
}

ind::OptionsScene::~OptionsScene()
{
    for (auto &button : buttonsPlace)
        button.first->remove();
}

void ind::OptionsScene::initButtons(const irr::core::dimension2d<irr::s32> &size)
{
    float bombsHeight = 1.0f / 4;
    float speedHeight = 2.0f / 5;
    irr::core::dimension2df signSize = {1.0f / 20, 1.0f / 30};

    returnButton = initButton({1.0f / 2, 3.0f / 4}, {1.0f / 10, 1.0f / 20}, size, "./assets/return.png", nullptr);

    playerMaxBombsPlaced = initButton({1.0f / 5, bombsHeight}, {1.0f / 10, 1.0f / 15}, size, "./assets/settings/bombs_placed_max.png", nullptr);
    bombsPlacedDown = initButton({3.0f / 5, bombsHeight}, signSize, size, "./assets/settings/minus.png", &ind::OptionsScene::decrementMaxBombsPlaced);
    bombsPlacedUp = initButton({4.0f / 5, bombsHeight}, signSize, size, "./assets/settings/plus.png", &ind::OptionsScene::incrementMaxBombsPlaced);
    bombsPlacedNumber = initButton({3.5f / 5, bombsHeight}, signSize, size, "./assets/settings/empty.png", nullptr);

    speedButton = initButton({1.0f / 5, speedHeight}, {1.0f / 10, 1.0f / 20}, size, "./assets/settings/movement_speed.png", nullptr);
    speedDownButton = initButton({3.0f / 5, speedHeight}, signSize, size, "./assets/settings/minus.png", &ind::OptionsScene::decrementSpeed);
    speedUpButton = initButton({4.0f / 5, speedHeight}, signSize, size, "./assets/settings/plus.png", &ind::OptionsScene::incrementSpeed);
    speedNumber = initButton({3.5f / 5, speedHeight}, signSize, size, "./assets/settings/empty.png", nullptr);

    std::string maxBombsPlacedStr = std::to_string(PlayersSettingsSave::defaultSettings().maxBombsPlaced);
    bombsPlacedNumber->setText(std::wstring(maxBombsPlacedStr.begin(), maxBombsPlacedStr.end()).c_str());

    std::string speedStr = std::to_string(PlayersSettingsSave::defaultSettings().speed);
    speedNumber->setText(std::wstring(speedStr.begin(), speedStr.end()).c_str());
}

irr::gui::IGUIButton *ind::OptionsScene::initButton(const irr::core::dimension2df &center,
                                                    const irr::core::dimension2df &size,
                                                    const irr::core::dimension2di &screenDimension, const char *path,
                                                    void (ind::OptionsScene::*function)())
{
    irr::gui::IGUIButton *button = gui->addButton(ind::PlaceRectangle::getRectangle(
            {(int) (center.Width * screenDimension.Width), (int) (center.Height * screenDimension.Height)},
            {(int) (size.Width * screenDimension.Width), (int) (size.Height * screenDimension.Height)}));
    button->setImage(gui->getVideoDriver()->getTexture(path));
    button->setDrawBorder(false);
    buttonsPlace.emplace(button, ButtonPosition(center, size));
    if (function)
        buttonsFunction[button] = function;
    return button;
}

ind::SceneType ind::OptionsScene::execute(__attribute__((unused)) irr::f32 deltaTime)
{
    static irr::core::dimension2d<irr::u32> size = gui->getVideoDriver()->getScreenSize();
    const irr::core::dimension2d<irr::u32> currSize = gui->getVideoDriver()->getScreenSize();

    if (currSize != size) {
        resizeButtons(currSize);
        size = currSize;
    }
    if (returnButton->isPressed())
        return MAIN_MENU;
    for (const auto &pair : buttonsFunction)
        if (pair.first->isPressed())
            (this->*pair.second)();
    draw(size);
    return OPTIONS;
}

void ind::OptionsScene::draw(const irr::core::dimension2d<irr::u32> &size) const
{
    gui->getVideoDriver()->draw2DImage(background,
                                       irr::core::position2d<irr::s32>(0, 0),
                                       irr::core::rect<irr::s32>(0, 0, 1920, 1080),
                                       new irr::core::rect<irr::s32>(0, 0, size.Width, size.Height));

    gui->drawAll();
}

void ind::OptionsScene::resizeButtons(const irr::core::dimension2d<irr::u32> &currSize) const
{
    const irr::u32 &x = currSize.Width;
    const irr::u32 &y = currSize.Height;

    for (const auto &buttonPair : buttonsPlace)
        buttonPair.first->setRelativePosition(findPosition(x, y, buttonPair.first));
}

irr::core::rect<irr::s32> ind::OptionsScene::findPosition(const irr::u32 &x, const irr::u32 &y,
                                                          irr::gui::IGUIButton *button) const
{
    const ButtonPosition &buttonPlace = buttonsPlace.at(button);

    return ind::PlaceRectangle::getRectangle(
            {(int) (x * buttonPlace.center.Width), (int) (y * buttonPlace.center.Height)},
            {(int) (x * buttonPlace.size.Width), (int) (y * buttonPlace.size.Height)});
}

ind::SceneType ind::OptionsScene::type()
{
    return OPTIONS;
}

void ind::OptionsScene::incrementMaxBombsPlaced()
{
    if (PlayersSettingsSave::defaultSettings().maxBombsPlaced == SHRT_MAX)
        return;

    ++PlayersSettingsSave::defaultSettings().maxBombsPlaced;

    std::string maxBombsPlacedtr = std::to_string(PlayersSettingsSave::defaultSettings().maxBombsPlaced);
    bombsPlacedNumber->setText(std::wstring(maxBombsPlacedtr.begin(), maxBombsPlacedtr.end()).c_str());
    bombsPlacedUp->setPressed(false);
}

void ind::OptionsScene::decrementMaxBombsPlaced()
{
    if (PlayersSettingsSave::defaultSettings().maxBombsPlaced <= 1)
        return;

    --PlayersSettingsSave::defaultSettings().maxBombsPlaced;

    std::string maxBombsPlacedtr = std::to_string(PlayersSettingsSave::defaultSettings().maxBombsPlaced);
    bombsPlacedNumber->setText(std::wstring(maxBombsPlacedtr.begin(), maxBombsPlacedtr.end()).c_str());
    bombsPlacedDown->setPressed(false);
}

void ind::OptionsScene::incrementSpeed()
{
    if (PlayersSettingsSave::defaultSettings().speed == FLT_MAX)
        return;

    ++PlayersSettingsSave::defaultSettings().speed;
    std::string speedStr = std::to_string(PlayersSettingsSave::defaultSettings().speed);
    speedNumber->setText(std::wstring(speedStr.begin(), speedStr.end()).c_str());
    speedUpButton->setPressed(false);
}

void ind::OptionsScene::decrementSpeed()
{
    if (PlayersSettingsSave::defaultSettings().speed <= 1)
        return;

    --PlayersSettingsSave::defaultSettings().speed;

    std::string speedStr = std::to_string(PlayersSettingsSave::defaultSettings().speed);
    speedNumber->setText(std::wstring(speedStr.begin(), speedStr.end()).c_str());
    speedDownButton->setPressed(false);
}