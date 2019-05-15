/*
** EPITECH PROJECT, 2019
** Hello_World
** File description:
** Created by abel,
*/

#include <iostream>
#include <irrlicht/irrlicht.h>

using namespace irr;

using namespace core;
using namespace video;
using namespace scene;
using namespace gui;

int main()
{
    std::cout << "Hello World !" << std::endl;
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(1920, 1080), 16, false, false, false, 0);
    irr::video::IVideoDriver* driver = device->getVideoDriver();
    irr::scene::ISceneManager* smgr = device->getSceneManager();
    irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
    irr::scene::IAnimatedMesh *bite = smgr->getMesh("./assets/BomberMan.3ds");
    if (!bite)
        {
        printf("bite\n");
        exit(0);
    }
    irr::scene::IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( bite );
    if (node)
    {
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node->setMD2Animation(irr::scene::EMAT_STAND);
        node->setMaterialTexture( 0, driver->getTexture("./assets/Bomberma.png"));
    }
    guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
        irr::core::rect<irr::s32>(10, 10, 260, 22), true);
    device->setWindowCaption(L"Bonjour");
    smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
    while (device->run())
    {
        driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
        guienv->drawAll();
        smgr->drawAll();
        driver->endScene();
    }
    return 0;
}
