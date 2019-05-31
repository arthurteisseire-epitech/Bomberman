/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by Arthamios
*/

#include <climits>
#include <irrlicht/IVideoDriver.h>
#include <irrlicht/IGUIButton.h>
#include "PlayersSettingsSave.hpp"
#include "OptionsScene.hpp"
#include "PlaceRectangle.hpp"

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
    returnButton->remove();
    playerMaxBombsPlaced->remove();
    bombsPlacedDown->remove();
    bombsPlacedUp->remove();
    bombsPlacedNumber->remove();
}

void ind::OptionsScene::initButtons(const irr::core::dimension2d<irr::s32> &size)
{
    returnButton = initButton({1.0f / 2, 3.0f / 4}, {1.0f / 10, 1.0f / 20}, size, "./assets/return.png");
    playerMaxBombsPlaced = initButton({1.0f / 4, 1.0f / 4}, {1.0f / 10, 1.0f / 15}, size, "./assets/settings/bombs_placed_max.png");
    bombsPlacedDown = initButton({3.0f / 5, 1.0f / 4}, {1.0f / 20, 1.0f / 30}, size, "./assets/settings/minus.png");
    bombsPlacedUp = initButton({4.0f / 5, 1.0f / 4}, {1.0f / 20, 1.0f / 30}, size, "./assets/settings/plus.png");

    bombsPlacedNumber = initButton({3.5f / 5, 1.0f / 4}, {1.0f / 20, 1.0f / 30}, size, "./assets/settings/empty.png");
    std::string maxBombsPlacedstr = std::to_string(PlayersSettingsSave::defaultSettings().maxBombsPlaced);
    bombsPlacedNumber->setText(std::wstring(maxBombsPlacedstr.begin(), maxBombsPlacedstr.end()).c_str());
}

irr::gui::IGUIButton *ind::OptionsScene::initButton(const irr::core::dimension2df &center,
                                                    const irr::core::dimension2df &size,
                                                    const irr::core::dimension2di &screenDimension, const char *path)
{
    irr::gui::IGUIButton *button = gui->addButton(ind::PlaceRectangle::getRectangle(
            {(int)(center.Width * screenDimension.Width), (int)(center.Height * screenDimension.Height)},
            {(int)(size.Width * screenDimension.Width), (int)(size.Height * screenDimension.Height)}));
    button->setImage(gui->getVideoDriver()->getTexture(path));
    button->setDrawBorder(false);
    buttonsPlace[button] = std::unique_ptr<irr::core::dimension2d<irr::core::dimension2df>>(
            new irr::core::dimension2d<irr::core::dimension2df>(center, size));
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
    if (bombsPlacedUp->isPressed())
        incrementBombsInit();
    if (bombsPlacedDown->isPressed())
        decrementBombsInit();
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

    returnButton->setRelativePosition(findPosition(x, y, returnButton));
    playerMaxBombsPlaced->setRelativePosition(findPosition(x, y, playerMaxBombsPlaced));
    bombsPlacedDown->setRelativePosition(findPosition(x, y, bombsPlacedDown));
    bombsPlacedUp->setRelativePosition(findPosition(x, y, bombsPlacedUp));
    bombsPlacedNumber->setRelativePosition(findPosition(x, y, bombsPlacedNumber));
}

irr::core::rect<irr::s32> ind::OptionsScene::findPosition(const irr::u32 &x, const irr::u32 &y,
                                                          irr::gui::IGUIButton *button) const
{
    const std::unique_ptr<irr::core::dimension2d<irr::core::dimension2df>> &buttonPlace = buttonsPlace.at(button);

    return ind::PlaceRectangle::getRectangle(
            {(int)(x * buttonPlace->Width.Width), (int)(y * buttonPlace->Width.Height)},
            {(int)(x * buttonPlace->Height.Width), (int)(y * buttonPlace->Height.Height)});
}

ind::SceneType ind::OptionsScene::type()
{
    return OPTIONS;
}

void ind::OptionsScene::incrementBombsInit()
{
    if (PlayersSettingsSave::defaultSettings().maxBombsPlaced == SHRT_MAX)
        return;

    ++PlayersSettingsSave::defaultSettings().maxBombsPlaced;

    std::string maxBombsPlacedtr = std::to_string(PlayersSettingsSave::defaultSettings().maxBombsPlaced);
    bombsPlacedNumber->setText(std::wstring(maxBombsPlacedtr.begin(), maxBombsPlacedtr.end()).c_str());
    bombsPlacedUp->setPressed(false);
}

void ind::OptionsScene::decrementBombsInit()
{
    if (PlayersSettingsSave::defaultSettings().maxBombsPlaced <= 1)
        return;

    --PlayersSettingsSave::defaultSettings().maxBombsPlaced;

    std::string maxBombsPlacedtr = std::to_string(PlayersSettingsSave::defaultSettings().maxBombsPlaced);
    bombsPlacedNumber->setText(std::wstring(maxBombsPlacedtr.begin(), maxBombsPlacedtr.end()).c_str());
    bombsPlacedDown->setOverrideFont();
    bombsPlacedDown->setPressed(false);
}