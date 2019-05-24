#ifndef BOMBERMAN_ANIMATEDMESH_HPP
#define BOMBERMAN_ANIMATEDMESH_HPP

#include <vector>
#include <string>
#include <irrlicht/coreutil.h>
#include <irrlicht/IAnimatedMesh.h>
#include <irrlicht/ISceneManager.h>
#include <bits/unique_ptr.h>

namespace ind {
    namespace animations {
        class AnimatedMesh : public irr::scene::IAnimatedMesh, public virtual irr::IReferenceCounted {
            public:
                explicit AnimatedMesh(irr::scene::ISceneManager &manager, std::string &objfolderpath);
                irr::f32 getAnimationSpeed() const override;
                irr::u32 getFrameCount() const override;
                IMesh *getMesh(irr::s32 frame, irr::s32 detailLevel, irr::s32 startFrameLoop, irr::s32 endFrameLoop) override;
                irr::scene::E_ANIMATED_MESH_TYPE getMeshType() const override;
                void setAnimationSpeed(irr::f32 fps) override;
                irr::u32 getMeshBufferCount() const override;
                irr::scene::IMeshBuffer* getMeshBuffer(irr::u32 nr) const override;
                irr::scene::IMeshBuffer* getMeshBuffer(const irr::video::SMaterial &material) const override;
                const irr::core::aabbox3d<irr::f32>& getBoundingBox() const override;
                void setBoundingBox(const irr::core::aabbox3df& box) override;
                void setMaterialFlag(irr::video::E_MATERIAL_FLAG flag, bool newvalue) override;
                void setHardwareMappingHint(irr::scene::E_HARDWARE_MAPPING newMappingHint, irr::scene::E_BUFFER_TYPE buffer) override;
                void setDirty(irr::scene::E_BUFFER_TYPE buffer) override;
            private:
                void loadFolder(irr::scene::ISceneManager &manager);
                std::string _folderPath;
                std::vector<irr::scene::IAnimatedMesh *> _frames;
                std::unique_ptr<irr::scene::IAnimatedMesh> _frame = nullptr;
        };
    }
}
#endif //BOMBERMAN_ANIMATEDMESH_HPP
