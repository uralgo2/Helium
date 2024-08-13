#pragma once

namespace phoenix {
    enum class CapabilitiesEnum {
        Blend, 
        ClipDistance,
        ColorLogicOp,
        CullFace,
        DebugOutput,
        DebugOutputSynchronous,
        DepthClamp,
        DepthTest,
        Dither,
        FramebufferSRGB,
        LineSmooth,
        PolygonOffsetFill,
        PolygonOffsetLine,
        PolygonOffsetPoint,
        PolygonSmooth,
        PrimitiveRestart,
        PrimitveRestartFixedIndex,
        RasterizerDiscard,
        SampleAlphaToCoverage,
        SampleAlphaToOne,
        SampleCoverage,
        SampleShading,
        SampleMask,
        ScissorTest,
        StencilTest,
        TextureCubeMapSeamless,
        ProgramPointSize
    };
}