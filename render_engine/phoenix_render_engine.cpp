#include "phoenix/phoenix_render_engine.hpp"
#include <GL/glew.h>
#include <stdexcept>

inline static GLenum GetGLEnum(const phoenix::CapabilitiesEnum capabiltiy){
    switch(capabiltiy){
        case phoenix::CapabilitiesEnum::Blend:
            return GL_BLEND;
        case phoenix::CapabilitiesEnum::ClipDistance:
            return GL_CLIP_DISTANCE0;
        case phoenix::CapabilitiesEnum::ColorLogicOp:
            return GL_COLOR_LOGIC_OP;
        case phoenix::CapabilitiesEnum::CullFace:
            return GL_CULL_FACE;
        case phoenix::CapabilitiesEnum::DebugOutput:
            return GL_DEBUG_OUTPUT;
        case phoenix::CapabilitiesEnum::DebugOutputSynchronous:
            return GL_DEBUG_OUTPUT_SYNCHRONOUS;
        case phoenix::CapabilitiesEnum::DepthClamp:
            return GL_DEPTH_CLAMP;
        case phoenix::CapabilitiesEnum::DepthTest:
            return GL_DEPTH_TEST;
        case phoenix::CapabilitiesEnum::Dither:
            return GL_DITHER;
        case phoenix::CapabilitiesEnum::FramebufferSRGB:
            return GL_FRAMEBUFFER_SRGB;
        case phoenix::CapabilitiesEnum::LineSmooth:
            return GL_LINE_SMOOTH;
        case phoenix::CapabilitiesEnum::PolygonOffsetFill:
            return GL_POLYGON_OFFSET_FILL;
        case phoenix::CapabilitiesEnum::PolygonOffsetLine:
            return GL_POLYGON_OFFSET_LINE;
        default:
            return GL_INVALID_ENUM;

    }
}

void phoenix::OpenglRenderEngine::Init()
{
    glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		throw std::runtime_error("Couldn't initialize GLEW.");
    
}

void phoenix::OpenglRenderEngine::Render(const phoenix::Scene & scene)
{

}

void phoenix::OpenglRenderEngine::Render(const phoenix::Mesh &)
{
}

void phoenix::OpenglRenderEngine::EnableCapability(const phoenix::CapabilitiesEnum capability)
{
    glEnable(GetGLEnum(capability));
}

bool phoenix::OpenglRenderEngine::IsEnabled(const CapabilitiesEnum capability)
{
    return glIsEnabled(GetGLEnum(capability));
}

void phoenix::OpenglRenderEngine::DisableCapability(const CapabilitiesEnum capability)
{
    glDisable(GetGLEnum(capability));
}
