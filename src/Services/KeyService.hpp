/*
** EPITECH PROJECT, 2019
** bomberman
** File description:
** Created by abel,
*/

#pragma once

#include <irrlicht/irrlicht.h>
#include <vector>

namespace ind {

    class KeyService : public irr::IEventReceiver {
        public:
            KeyService();
            bool isKeyPressed(irr::EKEY_CODE key) const;
            bool OnEvent(const irr::SEvent &event) override;

        private:
            bool keyDown[irr::KEY_KEY_CODES_COUNT];
    };
}
