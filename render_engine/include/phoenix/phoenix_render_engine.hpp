#ifndef PHOENIX_RENDER_ENGINE
#define PHOENIX_RENDER_ENGINE

#include "phoenix/scene.hpp"
#include "phoenix/mesh.hpp"
#include "phoenix/capabilities.hpp"

namespace phoenix {
    class IPhoenixRenderEngine {
        public:
        virtual void Init() = 0;
        virtual void Render(const Scene&) = 0;
        virtual void Render(const Mesh&) = 0;
        virtual void EnableCapability(const CapabilitiesEnum) = 0;
        virtual void DisableCapability(const CapabilitiesEnum) = 0;
        virtual bool IsEnabled(const CapabilitiesEnum) = 0;
        //virtual void PolygonMode(const FacesEnum, const DrawModesEnum) = 0;
    };
    class OpenglRenderEngine : IPhoenixRenderEngine {

        void Init() override;
        void Render(const Scene&) override;
        void Render(const Mesh&) override;
        virtual void EnableCapability(const CapabilitiesEnum) override;
        virtual void DisableCapability(const CapabilitiesEnum) override;
        virtual bool IsEnabled(const CapabilitiesEnum) override;
    };
}

#endif