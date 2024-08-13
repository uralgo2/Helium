#pragma once 

#include <vector>

namespace phoenix {
    class IComponent {

    };

    class MeshRendererComponent : IComponent {

    };

    class SceneNode {
    private:
        std::vector<SceneNode*> _children;
        std::vector<IComponent*> _components;    
    };

    class Scene {
        private:
            SceneNode _rootNode;

        public:
        friend class IPhoenixRenderEngine;
    };
}